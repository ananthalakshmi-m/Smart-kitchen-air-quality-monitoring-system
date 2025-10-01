/***************************************************************
 * Smart Kitchen Air Quality & Safety Monitoring System
 * Platform: NodeMCU ESP8266
 * Monitors temperature, humidity, air quality, and smoke.
 * Alerts via LCD & buzzer, controls fan via relay, and sends
 * data to Blynk & ThingSpeak.
 ***************************************************************/

#define BLYNK_TEMPLATE_ID   "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "YOUR_TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN    "YOUR_BLYNK_AUTH_TOKEN"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#include <ESP8266HTTPClient.h>
#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

// WiFi and ThingSpeak credentials
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";
String apiKey = "YOUR_THINGSPEAK_API_KEY";
const char* server = "api.thingspeak.com";

// Sensors
#define DHTPIN D4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

#define MQ135 A0
#define MQ2 D3

// Actuators
#define BUZZER_PIN D7
#define RELAY_PIN D6

// LCD
LiquidCrystal_PCF8574 lcd(0x27);

// Thresholds
#define AIR_QUALITY_THRESHOLD 100

BlynkTimer timer;

void controlDevices(int airQuality) {
  if (airQuality > AIR_QUALITY_THRESHOLD) {
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(RELAY_PIN, LOW);
    lcd.clear();
    lcd.setCursor(0, 0); lcd.print("ALERT: Pollution!");
    lcd.setCursor(0, 1); lcd.print("Fan & Buzzer ON");
  } else {
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(RELAY_PIN, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0); lcd.print("Air Quality: OK");
    lcd.setCursor(0, 1); lcd.print("Fan & Buzzer OFF");
  }
}

void sendSensorData() {
  float temperature = dht.readTemperature();
  float humidity    = dht.readHumidity();
  int airQuality    = analogRead(MQ135);
  int gasLevel      = digitalRead(MQ2);

  Serial.print("Air Quality: "); Serial.print(airQuality);
  Serial.print("  Gas Level: "); Serial.println(gasLevel);

  if (isnan(temperature) || isnan(humidity)) {
    lcd.clear();
    lcd.setCursor(0, 0); lcd.print("DHT22 Error");
  } else {
    lcd.clear();
    lcd.setCursor(0, 0); lcd.print("Temp: " + String(temperature) + "C");
    lcd.setCursor(0, 1); lcd.print("Humid: " + String(humidity) + "%");
  }

  controlDevices(airQuality);

  // Send data to Blynk
  Blynk.virtualWrite(V1, temperature);
  Blynk.virtualWrite(V2, humidity);
  Blynk.virtualWrite(V3, airQuality);
  Blynk.virtualWrite(V4, gasLevel);

  // Send data to ThingSpeak
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;
    String url = "http://" + String(server) + "/update?api_key=" + apiKey +
                 "&field1=" + String(temperature) +
                 "&field2=" + String(humidity) +
                 "&field3=" + String(airQuality) +
                 "&field4=" + String(gasLevel);

    http.begin(client, url);
    http.GET();
    http.end();
  }
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) { delay(1000); Serial.print("."); }
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  dht.begin();
  pinMode(MQ2, INPUT);
  pinMode(BUZZER_PIN, OUTPUT); digitalWrite(BUZZER_PIN, LOW);
  pinMode(RELAY_PIN, OUTPUT); digitalWrite(RELAY_PIN, LOW);

  lcd.begin(16, 2);
  lcd.setBacklight(255);
  lcd.setCursor(0, 0); lcd.print("System Starting...");

  timer.setInterval(5000L, sendSensorData);
}

void loop() {
  Blynk.run();
  timer.run();
}
