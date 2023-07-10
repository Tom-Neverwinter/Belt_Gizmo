#include <Arduino.h>
#include <Wire.h>
#include <MD_MAX72XX.h>
#include <MD_MAX72xx_font.h>
#include <ESPAsyncWebServer.h>
#include <WiFi.h>
#include <WiFiClient.h>

#include "animation.h"   // Include the animation header file
#include "piano.h"       // Include the piano header file
#include "temperature.h" // Include the temperature header file
#include "calculator.h"  // Include the calculator header file
#include "index.h"       // Include the index header file

// Pins for the MAX7219
#define DATA_PIN 14
#define CLK_PIN 13
#define CS_PIN 27

// Buzzer pin
#define BUZZER_PIN 2

// Number of devices (7-segment displays)
#define MAX_DEVICES 8

// Status LED pin
#define STATUS_LED_PIN 23

// WiFi credentials
const char* ssid = "sanyo808D";
const char* password = "ghostbuster";

// Create a new instance for the LED Matrix
MD_MAX72XX mx = MD_MAX72XX(CS_PIN, MAX_DEVICES);

// Create a server instance
AsyncWebServer server(80);

// Add these at the top of your sketch
bool playThemeFlag = true;  // Set to true or false to control theme playing
unsigned long previousMillis = 0;  // will store the last time the theme was played
const long interval = 900000;  // interval at which to play theme (milliseconds)

// Set up the display
void setupDisplay() {
  mx.begin();
  mx.control(MD_MAX72XX::INTENSITY, 8); // Set intensity levels (0-15)
  mx.clear();
}

// Function to display a number on the 7-segment displays
void displayNumber(int num) {
  mx.clear();
  for (int i = 0; i < MAX_DEVICES; i++) {
    byte digit = num % 10;
    mx.setDigit(i, digit, false);
    num /= 10;
    if (num == 0)
      break;
  }
}

// Set up the buzzer
void setupBuzzer() {
  pinMode(BUZZER_PIN, OUTPUT);
}

// Set up the status LED
void setupStatusLED() {
  pinMode(STATUS_LED_PIN, OUTPUT);
}

// Function to set the status LED
void setStatusLED(bool state) {
  digitalWrite(STATUS_LED_PIN, state ? HIGH : LOW);
}

// Set up the web server
void setupServer() {
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    // Serve the index_html webpage
    String html = String(index_html);
    request->send(200, "text/html", html);
  });
  server.on("/calc", HTTP_GET, [](AsyncWebServerRequest *request) {
    // handleCalc(request);
  });
  server.on("/playBuzzer", HTTP_GET, [](AsyncWebServerRequest *request) {
    // handleBuzzer(request);
  });
  server.on("/updateLed", HTTP_GET, [](AsyncWebServerRequest *request) {
    // handleLEDUpdate(request);
  });
  server.on("/getTemperature", HTTP_GET, [](AsyncWebServerRequest *request) {
    // handleGetTemperature(request);
  });
  server.begin();
}

// Set up the WiFi connection
void setupWiFi() {
  WiFi.softAP(ssid, password);
  delay(100); // needed to make sure the access point is started before configuring it
  WiFi.softAPConfig(IPAddress(192, 168, 4, 1), IPAddress(192, 168, 4, 1), IPAddress(255, 255, 255, 0));
}

void setup() {
  Serial.begin(115200);
  setupDisplay();
  setupBuzzer();
  setupStatusLED();
  setupWiFi();
  setupServer();
  setStatusLED(true);
}

void loop() {
  server.handleClient();
  mx.displayAnimate();

  // Check whether to play the theme
  if (playThemeFlag) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      // Save the last time the theme was played
      previousMillis = currentMillis;

      // Play the Ghostbusters theme
      playTheme(1);
    }
  }

  // You can add your own code here, but keep it non-blocking
}
