# Components List – Smart Kitchen Air Quality & Safety Monitoring System

This document lists all the hardware components used in the project along with their quantities and descriptions.

| Component Name                      | Quantity  | Description                                                                                     |
| ----------------------------------- | --------- | ----------------------------------------------------------------------------------------------- |
| NodeMCU ESP8266                     | 1         | Microcontroller with WiFi used to process sensor data and send updates to Blynk and ThingSpeak. |
| DHT22 Temperature & Humidity Sensor | 1         | Measures the ambient temperature and humidity in the kitchen.                                   |
| MQ135 Air Quality Sensor            | 1         | Measures the air quality/pollution levels.                                                      |
| MQ2 Gas/Smoke Sensor                | 1         | Detects smoke or flammable gas in the kitchen.                                                  |
| Buzzer                              | 1         | Provides an audible alert when air quality or gas levels exceed safe thresholds.                |
| Relay Module                        | 1         | Controls a DC motor/fan based on air quality readings.                                          |
| DC Motor / Fan                      | 1         | Used to ventilate the kitchen when pollution or smoke is detected.                              |
| LCD Display 16x2 (I2C, PCF8574)     | 1         | Displays real-time temperature, humidity, and air quality readings for local monitoring.        |
| External 5V Power Supply / Battery  | 1         | Provides power to the NodeMCU, sensors, and actuators if USB power is insufficient.             |
| Breadboard                          | 1         | Required for connecting all components neatly and safely.                                       |
| Connecting Wires / Jumper Cables    | As needed | Used to connect all components on the breadboard.                                               |

## Notes:

* The NodeMCU ESP8266 acts as the brain of the system, receiving data from sensors and controlling the buzzer, relay, motor, and LCD.
* DHT22: 3 pins (VCC, GND, Data). A 10kΩ pull-up resistor may be required on the data line.
* MQ135: Analog output connected to NodeMCU A0 pin; VCC and GND connected appropriately.
* MQ2: Digital output connected to NodeMCU digital pin; VCC and GND connected appropriately.
* Buzzer: Connect to a digital output pin; can be active-high or active-low depending on module.
* Relay Module: Controls the DC motor/fan. Ensure the relay can handle the motor’s current and isolate NodeMCU from high voltage.
* DC Motor / Fan: Powered via relay from an external 5V supply or battery; NodeMCU signals the relay.
* LCD Display: Uses I2C (SDA, SCL, VCC, GND). Default I2C address is usually 0x27.
* External Power: Required if USB cannot supply enough current for NodeMCU, motor, and sensors simultaneously.
* Breadboard: Necessary to organize all connections; without it, wiring will be messy and prone to errors.
