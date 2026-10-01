# 🌧️ Arduino Rain Detection System

A simple Arduino-based rain detection system using a rain sensor, LED, and buzzer.

# 🔧 Components

- Arduino Uno
- Rain Sensor Module
- Buzzer
- LED
- 220Ω Resistor
- Breadboard
- Jumper Wires

# 🔌 Connections

| Component | Arduino |
|---|---|
| Rain Sensor AO | A0 |
| Rain Sensor VCC | 5V |
| Rain Sensor GND | GND |
| Buzzer + | D3 |
| Buzzer - | GND |
| LED Long Leg (+) | D8 through 220Ω resistor |
| LED Short Leg (-) | GND |

# ⚙️ How It Works

1. The rain sensor detects water.
2. Arduino reads the sensor value.
3. If the sensor value is below **1000**, rain is detected.
4. The LED and buzzer turn ON.
5. After **10 seconds**, the LED and buzzer automatically turn OFF.
6. The system resets when the sensor becomes dry.

# 📊 Sensor Threshold

The current threshold is:

```text
sensorValue < 1000
