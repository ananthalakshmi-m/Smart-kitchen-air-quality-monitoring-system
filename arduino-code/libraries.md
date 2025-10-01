# Libraries Used in Smart Kitchen Air Quality and Safety Monitoring System

This document lists all the libraries used in the project, along with a brief description and installation instructions. These libraries are required for the NodeMCU ESP8266 code to function properly.

## 1. ESP8266WiFi
**Purpose:** Provides WiFi connectivity for the NodeMCU ESP8266 to connect to local WiFi networks.  
**Installation:** Available through Arduino IDE Library Manager.  
**Include Statement:**  
```cpp
#include <ESP8266WiFi.h>
```

## 2. BlynkSimpleEsp8266

**Purpose:** Enables communication with the Blynk cloud platform to send real-time sensor data and receive commands.
**Installation:** Install via Arduino Library Manager (`Blynk` library).
**Include Statement:**

```cpp
#include <BlynkSimpleEsp8266.h>
```

## 3. DHT

**Purpose:** Used to interface with DHT22 (temperature and humidity) sensors. Handles sensor reading and data conversion.
**Installation:** Install via Arduino Library Manager (`DHT sensor library by Adafruit`).
**Include Statement:**

```cpp
#include <DHT.h>
```

## 4. ESP8266HTTPClient

**Purpose:** Facilitates sending HTTP requests from NodeMCU to web servers like ThingSpeak. Used to send sensor data for remote monitoring.
**Installation:** Comes with ESP8266 board package in Arduino IDE.
**Include Statement:**

```cpp
#include <ESP8266HTTPClient.h>
```

## 5. Wire

**Purpose:** Provides I2C communication protocol for interfacing with I2C devices, such as the 16x2 LCD module.
**Installation:** Pre-installed with Arduino IDE.
**Include Statement:**

```cpp
#include <Wire.h>
```

## 6. LiquidCrystal_PCF8574

**Purpose:** Library for controlling I2C-based 16x2 LCD displays using the PCF8574 I/O expander.
**Installation:** Install via Arduino Library Manager (`LiquidCrystal_PCF8574`).
**Include Statement:**

```cpp
#include <LiquidCrystal_PCF8574.h>
```

## Notes

* Make sure all libraries are updated to their latest versions for compatibility with NodeMCU ESP8266.
* Libraries like `ESP8266WiFi` and `ESP8266HTTPClient` require the **ESP8266 board package** installed in Arduino IDE.
