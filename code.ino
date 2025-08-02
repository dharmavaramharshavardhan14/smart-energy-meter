#include <WiFi.h>
#include "ThingSpeak.h"
#include <ACS712.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

WiFiClient client;
unsigned long channelNumber = YOUR_CHANNEL_ID;
const char* writeAPIKey = "Your_ThingSpeak_API_Key";

// ACS712 setup
ACS712 sensor(ACS712_30A, 34); // 30A version, connected to GPIO 34

float voltage = 230.0; // Assume constant
float ratePerUnit = 7.0; // Rs. per kWh
float energy = 0.0;
unsigned long lastUpdate = 0;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  sensor.begin();

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("WiFi connected!");
  ThingSpeak.begin(client);
}

void loop() {
  float current = sensor.getCurrentAC();
  float power = voltage * current; // Watts

  unsigned long currentMillis = millis();
  float seconds = (currentMillis - lastUpdate) / 1000.0;

  energy += (power / 3600000.0) * seconds; // Convert to kWh
  float bill = energy * ratePerUnit;

  Serial.printf("Current: %.2f A, Power: %.2f W, Energy: %.4f kWh, Bill: ₹%.2f\n", current, power, energy, bill);

  ThingSpeak.setField(1, current);
  ThingSpeak.setField(2, power);
  ThingSpeak.setField(3, energy);
  ThingSpeak.setField(4, bill);
  
  int status = ThingSpeak.writeFields(channelNumber, writeAPIKey);
  if (status == 200) {
    Serial.println("Data sent to ThingSpeak.");
  } else {
    Serial.println("Error sending data.");
  }

  lastUpdate = currentMillis;
  delay(20000); // Send every 20 seconds
}
