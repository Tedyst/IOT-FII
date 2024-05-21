#include <WiFi.h>
#include <WiFiClient.h>
#include <HTTPClient.h>

#define WIFI_SSID "Wokwi-GUEST"
#define WIFI_PASSWORD "WIFI-PASSWORD"
// Defining the WiFi channel speeds up the connection:
#define WIFI_CHANNEL 6


constexpr int PIR_PIN = 12;
constexpr int SENSOR_PIN = 34;
constexpr int SENSOR_ID = 1;

float getTemperature() {
  // Read the temperature sensor
  float temperature = analogRead(SENSOR_PIN) * 3.3 / 4095;
  Serial.print("Temperature: ");
  Serial.println(temperature);
  return temperature;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  pinMode(PIR_PIN, INPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD, WIFI_CHANNEL);

    // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println(" Connected!");

  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(10); // this speeds up the simulation


  for (;;)
  {
    HTTPClient http;
    Serial.println(digitalRead(12));

      String serverPath = "http://192.168.10.108/api/sensordata/";
      
      // Your Domain name with URL path or IP address with path
      http.begin(serverPath.c_str());
      
      // If you need Node-RED/server authentication, insert user and password below
      //http.setAuthorization("REPLACE_WITH_SERVER_USERNAME", "REPLACE_WITH_SERVER_PASSWORD");
      
      // Send HTTP GET request
      int httpResponseCode = http.POST("sensor_id=" + SENSOR_ID + "&temperature=" + getTemperature());
      
      if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        Serial.println(payload);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      // Free resources
      http.end();

      delay(1000);
  }
}