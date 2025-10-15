#include <Arduino.h>
#include <Wire.h>
#include <MD_MAX72XX.h>
#include <MD_MAX72xx_font.h>
#include <ESPAsyncWebServer.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <time.h>

#ifdef ESP32
  #include "esp_system.h"
#endif

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

// Theme playback control
bool playThemeFlag = true;  // Set to true or false to control theme playing
unsigned long previousMillis = 0;  // will store the last time the theme was played
const long interval = 900000;  // interval at which to play theme (milliseconds)

// Buzzer volume control
int buzzerVolume = 50;  // 0-100

// Temperature reading (simulated if no sensor)
float currentTemperature = 22.5;

// NTP Time settings
const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = -18000;  // EST = UTC-5 hours
const int daylightOffset_sec = 3600;
bool clockEnabled = false;
bool timeInitialized = false;

// Animation control
int currentAnimation = 0;  // 0=none, 1=loading, 2=spinner, 3=pulse, 4=sweep, 5=random
unsigned long lastAnimationUpdate = 0;
int animationFrame = 0;
int animationSpeed = 100;  // milliseconds per frame

// Set up the display
void setupDisplay() {
  mx.begin();
  mx.control(MD_MAX72XX::INTENSITY, 8); // Set intensity levels (0-15)
  mx.clear();
}

// Function to display a number on the 7-segment displays
void displayNumber(long num) {
  mx.clear();
  if (num == 0) {
    mx.setDigit(0, 0, false);
    return;
  }
  
  bool isNegative = num < 0;
  if (isNegative) num = -num;
  
  int digitCount = 0;
  long tempNum = num;
  while (tempNum > 0 && digitCount < MAX_DEVICES) {
    byte digit = tempNum % 10;
    mx.setDigit(digitCount, digit, false);
    tempNum /= 10;
    digitCount++;
  }
}

// Function to display a float on the 7-segment displays
void displayFloat(float num) {
  long intPart = (long)(num * 10);  // One decimal place
  displayNumber(intPart);
}

// Function to display a text message on the 7-segment displays
void displayMessage(String message) {
  mx.clear();
  // Note: MD_MAX72XX can display characters if configured properly
  // For basic 7-segment displays, we'll show the first 8 characters as-is
  // You may need to map characters to 7-segment patterns
  for (int i = 0; i < min((int)message.length(), MAX_DEVICES); i++) {
    char c = message.charAt(i);
    // Simple character mapping for 7-segment
    if (c >= '0' && c <= '9') {
      mx.setChar(i, c);
    } else if (c >= 'A' && c <= 'Z') {
      mx.setChar(i, c);
    } else if (c >= 'a' && c <= 'z') {
      mx.setChar(i, c - 32); // Convert to uppercase
    } else {
      mx.setChar(i, ' ');
    }
  }
}

// Display Animations

// Loading bar animation (fills left to right)
void displayLoadingBar() {
  mx.clear();
  int filled = (animationFrame % (MAX_DEVICES + 1));
  for (int i = 0; i < filled; i++) {
    mx.setChar(i, '8');  // Full block
  }
  if (filled < MAX_DEVICES) {
    mx.setChar(filled, '-');  // Current position
  }
}

// Spinner animation (rotating segments)
void displaySpinner() {
  mx.clear();
  const char spinChars[] = {'|', '/', '-', '\\'};
  char spinChar = spinChars[animationFrame % 4];
  int pos = (animationFrame / 4) % MAX_DEVICES;
  mx.setChar(pos, spinChar);
}

// Pulse animation (breathing effect via brightness)
void displayPulse() {
  int brightness = abs((animationFrame % 30) - 15);
  mx.control(MD_MAX72XX::INTENSITY, brightness);
  displayMessage("PKE 808D");
}

// Sweep animation (Knight Rider style)
void displaySweep() {
  mx.clear();
  int pos = animationFrame % (MAX_DEVICES * 2 - 2);
  if (pos >= MAX_DEVICES) {
    pos = (MAX_DEVICES * 2 - 2) - pos;
  }
  mx.setChar(pos, '8');
  if (pos > 0) mx.setChar(pos - 1, '-');
  if (pos < MAX_DEVICES - 1) mx.setChar(pos + 1, '-');
}

// Random pattern animation
void displayRandom() {
  if (animationFrame % 5 == 0) {  // Update every 5 frames
    mx.clear();
    for (int i = 0; i < MAX_DEVICES; i++) {
      int r = random(0, 10);
      if (r < 10) {
        mx.setChar(i, '0' + r);
      }
    }
  }
}

// PKE Surge animation (simulates energy spike)
void displayPKESurge() {
  mx.clear();
  int intensity = animationFrame % 20;
  if (intensity > 10) intensity = 20 - intensity;
  
  for (int i = 0; i < MAX_DEVICES; i++) {
    if (random(0, 10) < intensity) {
      mx.setChar(i, '8');
    } else {
      mx.setChar(i, '-');
    }
  }
}

// Update animation based on current mode
void updateAnimation() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - lastAnimationUpdate >= animationSpeed) {
    lastAnimationUpdate = currentMillis;
    animationFrame++;
    
    switch(currentAnimation) {
      case 1:
        displayLoadingBar();
        break;
      case 2:
        displaySpinner();
        break;
      case 3:
        displayPulse();
        break;
      case 4:
        displaySweep();
        break;
      case 5:
        displayRandom();
        break;
      case 6:
        displayPKESurge();
        break;
      default:
        // No animation
        break;
    }
  }
}

// NTP Clock Functions

// Initialize NTP time
void initTime() {
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  timeInitialized = true;
}

// Display current time on 7-segment
void displayClock() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    displayMessage("NO TIME");
    return;
  }
  
  // Format: HH:MM:SS or HHMMSS (8 digits)
  char timeStr[9];
  sprintf(timeStr, "%02d%02d%02d", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
  displayMessage(timeStr);
}

// Display date on 7-segment
void displayDate() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    displayMessage("NO DATE");
    return;
  }
  
  // Format: MMDDYYYY or DDMMYY (8 digits)
  char dateStr[9];
  sprintf(dateStr, "%02d%02d%04d", timeinfo.tm_mon + 1, timeinfo.tm_mday, timeinfo.tm_year + 1900);
  
  // If year is too long, use short format
  if (strlen(dateStr) > 8) {
    sprintf(dateStr, "%02d%02d%02d", timeinfo.tm_mon + 1, timeinfo.tm_mday, (timeinfo.tm_year + 1900) % 100);
  }
  displayMessage(dateStr);
}

// Set up the buzzer
void setupBuzzer() {
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
}

// Play a tone on the buzzer with volume control
void playTone(int frequency, int duration) {
  if (buzzerVolume == 0) return;
  
  // Simple PWM-based volume control
  int adjustedDuration = (duration * buzzerVolume) / 100;
  tone(BUZZER_PIN, frequency, adjustedDuration);
  delay(duration);
  noTone(BUZZER_PIN);
}

// Play a note
void playNote(int frequency) {
  playTone(frequency, 200);
}

// Ghostbusters theme (simplified)
void playTheme(int themeNumber) {
  if (buzzerVolume == 0) return;
  
  switch(themeNumber) {
    case 1: // Original Ghostbusters theme
      playTone(262, 200); // C
      playTone(294, 200); // D
      playTone(330, 200); // E
      playTone(349, 200); // F
      playTone(392, 400); // G
      delay(100);
      playTone(392, 200); // G
      playTone(349, 200); // F
      playTone(330, 200); // E
      playTone(294, 400); // D
      break;
      
    case 2: // 2016 theme variation
      playTone(330, 150);
      playTone(392, 150);
      playTone(440, 150);
      playTone(494, 300);
      delay(100);
      playTone(440, 150);
      playTone(392, 150);
      playTone(330, 300);
      break;
      
    case 3: // Afterlife theme
      playTone(294, 300);
      playTone(330, 300);
      playTone(370, 300);
      playTone(392, 600);
      break;
      
    case 4: // Creepy music
      for(int i = 0; i < 3; i++) {
        playTone(200, 300);
        delay(100);
        playTone(180, 300);
        delay(100);
      }
      break;
  }
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
  // Serve the main webpage
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", index_html);
  });
  
  // Update LED display
  server.on("/updateLed", HTTP_GET, [](AsyncWebServerRequest *request) {
    if (request->hasParam("value")) {
      String value = request->getParam("value")->value();
      float numValue = value.toFloat();
      
      // Display on 7-segment
      if (value.indexOf('.') >= 0) {
        displayFloat(numValue);
      } else {
        displayNumber((long)numValue);
      }
      
      request->send(200, "text/plain", "LED updated: " + value);
    } else {
      request->send(400, "text/plain", "Missing value parameter");
    }
  });
  
  // Play buzzer
  server.on("/playBuzzer", HTTP_GET, [](AsyncWebServerRequest *request) {
    if (request->hasParam("volume")) {
      buzzerVolume = request->getParam("volume")->value().toInt();
    }
    
    // Play a confirmation beep
    playTone(1000, 100);
    
    request->send(200, "text/plain", "Buzzer played at volume: " + String(buzzerVolume));
  });
  
  // Play a note
  server.on("/playNote", HTTP_GET, [](AsyncWebServerRequest *request) {
    if (request->hasParam("note")) {
      int note = request->getParam("note")->value().toInt();
      playNote(note);
      request->send(200, "text/plain", "Note played: " + String(note));
    } else {
      request->send(400, "text/plain", "Missing note parameter");
    }
  });
  
  // Play theme music
  server.on("/playTheme", HTTP_GET, [](AsyncWebServerRequest *request) {
    if (request->hasParam("theme")) {
      int theme = request->getParam("theme")->value().toInt();
      playTheme(theme);
      request->send(200, "text/plain", "Theme played: " + String(theme));
    } else {
      request->send(400, "text/plain", "Missing theme parameter");
    }
  });
  
  // Get temperature
  server.on("/getTemperature", HTTP_GET, [](AsyncWebServerRequest *request) {
    // Simulate temperature reading or read from actual sensor
    // If you have a temperature sensor (like DS18B20), read it here
    #ifdef ESP32
      // ESP32 internal temperature (approximate)
      currentTemperature = (temperatureRead() - 32) / 1.8;
    #else
      // Simulated temperature with small variation
      currentTemperature = 22.5 + (random(-10, 10) / 10.0);
    #endif
    
    String json = "{\"temperature\":" + String(currentTemperature, 1) + "}";
    request->send(200, "application/json", json);
  });
  
  // Set volume
  server.on("/setVolume", HTTP_GET, [](AsyncWebServerRequest *request) {
    if (request->hasParam("volume")) {
      buzzerVolume = request->getParam("volume")->value().toInt();
      request->send(200, "text/plain", "Volume set: " + String(buzzerVolume));
    } else {
      request->send(400, "text/plain", "Missing volume parameter");
    }
  });
  
  // Mute function
  server.on("/mute", HTTP_GET, [](AsyncWebServerRequest *request) {
    buzzerVolume = (buzzerVolume == 0) ? 50 : 0;
    request->send(200, "text/plain", "Mute toggled. Volume: " + String(buzzerVolume));
  });
  
  // Settings endpoints
  server.on("/setBrightness", HTTP_GET, [](AsyncWebServerRequest *request) {
    if (request->hasParam("value")) {
      int brightness = request->getParam("value")->value().toInt();
      brightness = constrain(brightness, 0, 15);
      mx.control(MD_MAX72XX::INTENSITY, brightness);
      request->send(200, "text/plain", "Brightness set to: " + String(brightness));
    } else {
      request->send(400, "text/plain", "Missing value parameter");
    }
  });
  
  server.on("/toggleDisplay", HTTP_GET, [](AsyncWebServerRequest *request) {
    if (request->hasParam("enabled")) {
      bool enabled = (request->getParam("enabled")->value() == "1");
      mx.control(MD_MAX72XX::SHUTDOWN, enabled ? MD_MAX72XX::ON : MD_MAX72XX::OFF);
      request->send(200, "text/plain", "Display " + String(enabled ? "enabled" : "disabled"));
    } else {
      request->send(400, "text/plain", "Missing enabled parameter");
    }
  });
  
  server.on("/toggleStatusLED", HTTP_GET, [](AsyncWebServerRequest *request) {
    if (request->hasParam("enabled")) {
      bool enabled = (request->getParam("enabled")->value() == "1");
      setStatusLED(enabled);
      request->send(200, "text/plain", "Status LED " + String(enabled ? "enabled" : "disabled"));
    } else {
      request->send(400, "text/plain", "Missing enabled parameter");
    }
  });
  
  server.on("/setDisplayTimeout", HTTP_GET, [](AsyncWebServerRequest *request) {
    if (request->hasParam("seconds")) {
      int timeout = request->getParam("seconds")->value().toInt();
      // Store timeout value (you can implement auto-off logic in loop())
      request->send(200, "text/plain", "Display timeout set to: " + String(timeout) + " seconds");
    } else {
      request->send(400, "text/plain", "Missing seconds parameter");
    }
  });
  
  server.on("/setStartupMessage", HTTP_GET, [](AsyncWebServerRequest *request) {
    if (request->hasParam("message")) {
      String message = request->getParam("message")->value();
      // Store in EEPROM or global variable for use on startup
      request->send(200, "text/plain", "Startup message set to: " + message);
    } else {
      request->send(400, "text/plain", "Missing message parameter");
    }
  });
  
  server.on("/setIdleMessage", HTTP_GET, [](AsyncWebServerRequest *request) {
    if (request->hasParam("message")) {
      String message = request->getParam("message")->value();
      // Store in EEPROM or global variable for idle display
      request->send(200, "text/plain", "Idle message set to: " + message);
    } else {
      request->send(400, "text/plain", "Missing message parameter");
    }
  });
  
  // Animation endpoints
  server.on("/setAnimation", HTTP_GET, [](AsyncWebServerRequest *request) {
    if (request->hasParam("type")) {
      String type = request->getParam("type")->value();
      animationFrame = 0;  // Reset animation
      
      if (type == "none" || type == "0") {
        currentAnimation = 0;
        mx.control(MD_MAX72XX::INTENSITY, 8);  // Reset brightness
        mx.clear();
        request->send(200, "text/plain", "Animation stopped");
      } else if (type == "loading" || type == "1") {
        currentAnimation = 1;
        request->send(200, "text/plain", "Loading bar animation started");
      } else if (type == "spinner" || type == "2") {
        currentAnimation = 2;
        request->send(200, "text/plain", "Spinner animation started");
      } else if (type == "pulse" || type == "3") {
        currentAnimation = 3;
        request->send(200, "text/plain", "Pulse animation started");
      } else if (type == "sweep" || type == "4") {
        currentAnimation = 4;
        request->send(200, "text/plain", "Sweep animation started");
      } else if (type == "random" || type == "5") {
        currentAnimation = 5;
        request->send(200, "text/plain", "Random animation started");
      } else if (type == "surge" || type == "6") {
        currentAnimation = 6;
        request->send(200, "text/plain", "PKE Surge animation started");
      } else {
        request->send(400, "text/plain", "Unknown animation type");
      }
    } else {
      request->send(400, "text/plain", "Missing type parameter");
    }
  });
  
  server.on("/setAnimationSpeed", HTTP_GET, [](AsyncWebServerRequest *request) {
    if (request->hasParam("speed")) {
      animationSpeed = request->getParam("speed")->value().toInt();
      animationSpeed = constrain(animationSpeed, 10, 1000);
      request->send(200, "text/plain", "Animation speed set to: " + String(animationSpeed) + "ms");
    } else {
      request->send(400, "text/plain", "Missing speed parameter");
    }
  });
  
  // Clock endpoints
  server.on("/initClock", HTTP_GET, [](AsyncWebServerRequest *request) {
    if (!timeInitialized) {
      initTime();
      request->send(200, "text/plain", "NTP time sync initiated");
    } else {
      request->send(200, "text/plain", "Time already initialized");
    }
  });
  
  server.on("/showClock", HTTP_GET, [](AsyncWebServerRequest *request) {
    if (!timeInitialized) {
      initTime();
      delay(2000);  // Wait for NTP sync
    }
    clockEnabled = true;
    currentAnimation = 0;  // Stop animations
    displayClock();
    request->send(200, "text/plain", "Clock display enabled");
  });
  
  server.on("/showDate", HTTP_GET, [](AsyncWebServerRequest *request) {
    if (!timeInitialized) {
      initTime();
      delay(2000);  // Wait for NTP sync
    }
    clockEnabled = false;
    currentAnimation = 0;  // Stop animations
    displayDate();
    request->send(200, "text/plain", "Date displayed");
  });
  
  server.on("/hideClock", HTTP_GET, [](AsyncWebServerRequest *request) {
    clockEnabled = false;
    mx.clear();
    request->send(200, "text/plain", "Clock display disabled");
  });
  
  server.on("/setTimezone", HTTP_GET, [](AsyncWebServerRequest *request) {
    if (request->hasParam("offset")) {
      long offset = request->getParam("offset")->value().toInt();
      // Reinitialize with new timezone
      configTime(offset * 3600, daylightOffset_sec, ntpServer);
      request->send(200, "text/plain", "Timezone set to UTC" + String(offset));
    } else {
      request->send(400, "text/plain", "Missing offset parameter");
    }
  });
  
  // Pager message handler
  server.on("/sendPagerMessage", HTTP_GET, [](AsyncWebServerRequest *request) {
    if (request->hasParam("message")) {
      String message = request->getParam("message")->value();
      
      // Enforce 8 character limit for physical display
      if (message.length() > 8) {
        message = message.substring(0, 8);
      }
      
      // Display message on LED (always 8 chars or less)
      displayMessage(message);
      
      // Check if beep is enabled (default to true if not specified)
      bool beepEnabled = true;
      if (request->hasParam("beep")) {
        String beepParam = request->getParam("beep")->value();
        beepEnabled = (beepParam == "1" || beepParam == "true");
      }
      
      // Play notification beep only if enabled
      if (beepEnabled && buzzerVolume > 0) {
        playTone(800, 100);
        delay(50);
        playTone(1000, 100);
      }
      
      request->send(200, "text/plain", "Pager message received: " + message);
    } else {
      request->send(400, "text/plain", "Missing message parameter");
    }
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
  // AsyncWebServer handles requests automatically, no need to call handleClient()
  
  // Update animations if active
  if (currentAnimation > 0) {
    updateAnimation();
  }
  
  // Update clock if enabled
  if (clockEnabled && currentAnimation == 0) {
    static unsigned long lastClockUpdate = 0;
    unsigned long currentMillis = millis();
    if (currentMillis - lastClockUpdate >= 1000) {  // Update every second
      lastClockUpdate = currentMillis;
      displayClock();
    }
  }
  
  // Check whether to play the theme
  if (playThemeFlag && currentAnimation == 0 && !clockEnabled) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      // Save the last time the theme was played
      previousMillis = currentMillis;

      // Play the Ghostbusters theme
      playTheme(1);
    }
  }

  // Small delay to prevent watchdog issues
  delay(10);
}
