
# 🔌 Smart IoT Energy Meter with Real-Time Billing (ESP32 + ThingSpeak)

This project simulates a smart energy meter using an ESP32 and a potentiometer (simulating a current sensor like ACS712), and pushes data to ThingSpeak cloud.

---

## ⚙️ Components Used
- ESP32 Dev Board
- Potentiometer (simulated)
- ThingSpeak (cloud dashboard)
- Arduino IDE (via Wokwi)

---

## 🧠 How It Works

1. Reads analog input from potentiometer on GPIO34
2. Calculates:
   - Current (0–5A range)
   - Power (W) = 230V × Current
   - Bill = ₹ based on simulated rate
3. Sends data to ThingSpeak every 15 seconds
4. Visualizes Current, Power, Bill on cloud graphs

---

## 🔧 Circuit Diagram
![Circuit + Serial Output](images/circuit_and_serial_output.png)

---

## 🌐 Live Data from ThingSpeak
![ThingSpeak Chart Output](images/thingspeak_output.png)

---

## 📂 Folder Structure

```
Smart_Energy_Meter_Project/
├── code/
│   └── smart_energy_meter.ino
├── images/
│   ├── thingspeak_output.png
│   └── circuit_and_serial_output.png
└── README.md
```

---

## 📌 Learning Outcomes
- Analog data reading using ESP32
- HTTP communication with ThingSpeak
- Basic power and billing calculations
- IoT + Cloud integration from scratch

---

## 🚀 Future Improvements
- Replace POT with real ACS712
- Add OLED display for live monitoring
- Use Blynk for mobile app control
- Add relay to disconnect loads over threshold

---

Made with 💡 by Harshavardhan
