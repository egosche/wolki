/**
 * Wolki
 *
 *  Created on: 23.01.2021
 *  LED Strip is RBG, not RGB
 *
 */
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "Sektionen.h"
#include "WetterEffekte.h"
#include "Strip.h"

volatile int interruptCounter;
hw_timer_t *timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

WiFiMulti wifiMulti;
char ssid[] = "REPLACE ME";
char password[] = "REPLACE ME";
String city = "REPLACE ME";
String api_key = "REPLACE ME";

int weather_id;

/* ISR */
void IRAM_ATTR onTimer()
{
  portENTER_CRITICAL_ISR(&timerMux);
  interruptCounter++;
  portEXIT_CRITICAL_ISR(&timerMux);
}

/* Setup */
void setup()
{
  Serial.begin(9200);

  Serial.println();
  Serial.println();
  Serial.println();

  timer = timerBegin(0, 80, true);
  timerAttachInterrupt(timer, &onTimer, true);
  timerAlarmWrite(timer, 60000000, true);
  timerAlarmEnable(timer);

  for (uint8_t t = 4; t > 0; t--)
  {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }

  wifiMulti.addAP(ssid, password);
  while (wifiMulti.run() != WL_CONNECTED)
  {
    Serial.println("Connecting...");
    delay(500);
  }
  Serial.println("Connected to AP");

  clearStrip();

  for (int i = 0; i < NUM_LEDS; i++)
  {
    setPixel(i, 255, 255, 255);
    showStrip(); // Send the updated pixel colors to the hardware.
  }
}

/* Loop */
void loop()
{
  // wait for WiFi connection
  if ((wifiMulti.run() == WL_CONNECTED))
  {
    if (interruptCounter > 0)
    {
      portENTER_CRITICAL(&timerMux);
      interruptCounter--;
      portEXIT_CRITICAL(&timerMux);
      Serial.println("UPDATE");
      HTTPClient http_weather, http_datetime;
      DynamicJsonDocument doc(1024);

      Serial.print("[HTTP] Begin requests...\n");
      http_weather.begin("http://api.openweathermap.org/data/2.5/weather?q=" +
                         city + "&appid=" + api_key);
      http_datetime.begin("http://worldtimeapi.org/api/timezone/Europe/Berlin");

      Serial.print("[HTTP] Get data...\n");
      // start connection and send HTTP header
      int http_weatherCode = http_weather.GET();
      int http_datetimeCode = http_datetime.GET();

      // httpCode will be negative on error
      if (http_weatherCode > 0 && http_datetimeCode > 0)
      {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET weather code: %d\n", http_weatherCode);
        Serial.printf("[HTTP] GET datetime code: %d\n", http_datetimeCode);

        // file found at server
        if (http_weatherCode == HTTP_CODE_OK &&
            http_datetimeCode == HTTP_CODE_OK)
        {
          String weather_payload = http_weather.getString();
          deserializeJson(doc, weather_payload);
          weather_id = doc["weather"][0]["id"];
          Serial.printf("Received weatherid: %d\n", weather_id);

          String datetime_payload = http_datetime.getString();
          deserializeJson(doc, datetime_payload);
          const char *datetime = doc["datetime"];
          Serial.printf("Received datetime: %s\n", datetime);
        }
      }
      else
      {
        Serial.printf("[HTTP] GET weather failed, error: %s\n",
                      http_weather.errorToString(http_weatherCode).c_str());
        Serial.printf("[HTTP] GET datetime failed, error: %s\n",
                      http_datetime.errorToString(http_datetimeCode).c_str());
      }
      http_weather.end();
      http_datetime.end();

      Serial.print("An interrupt as occurred. Total number: ");
    }
  }
  // check for thunderstorm
  if (weather_id >= 200 && weather_id <= 232)
  {
    thunderstorm(16, 16, 16, 20, random(5000));
  }

  // check for drizzle and rain
  else if (weather_id >= 300 && weather_id <= 531)
  {
    rain(100, 100, 255, 10, 64, 15);
  }

  // check for snow
  else if (weather_id >= 600 && weather_id <= 622)
  {
    snow(255, 255, 255, 50);
  }

  // check for clouds
  else if (weather_id >= 801 && weather_id <= 804)
  {
    cloudy(250, 250, 250, 10, 64, 15);
  }

  // check for sunny weather, also catch unkown weatherids
  else
  {
    sunny(31, 255, 83, 10, 64, 15);
  }
}

// Sequentially turn on all leds
void sequential()
{
  clearStrip();
  for (int i = 81; i < NUM_LEDS; i++)
  {
    clearStrip();
    setPixel(i, 255, 255, 255);
    showStrip();
    Serial.println(i);
    delay(6000);
  }
}
