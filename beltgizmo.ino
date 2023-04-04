#include <MD_MAX72xx.h>
#include <MD_Parola.h>
#include <pgmspace.h>
#include <webpage.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiManager.h>
#include <WebServer.h>

const char* ssid = "sanyo808D";
const char* password = "ghostbuster";
IPAddress apIP(192, 168, 4, 1);
WebServer server(80);
WiFiManager wifiManager;

const uint8_t buzzerPin = 2;
const uint8_t CLK_PIN = 13;
const uint8_t DATA_PIN = 14;
const uint8_t CS_PIN = 27;

const uint8_t MAX_DEVICES = 8;
const uint8_t CHAR_SPACING = 1;
const uint8_t SCROLL_SPEED = 50;

MD_Parola P = MD_Parola(MD_MAX72XX::FC16_HW, CS_PIN, MAX_DEVICES);

void setup() {
  Serial.begin(115200);

  // Start the access point
  wifiManager.autoConnect("AP_Name", "AP_Password");
  delay(100);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
  
  // Configure the web server
  server.on("/", handleRoot);
  server.on("/calc", handleCalc);
  server.on("/playBuzzer", handleBuzzer);
  server.on("/updateLed", handleLEDUpdate);
  server.begin();

  Serial.print("Access point started, IP address: ");
  Serial.println(WiFi.softAPIP());

  pinMode(buzzerPin, OUTPUT);

  P.begin();
  P.setInvert(false);
  P.setIntensity(15);
  P.setTextAlignment(PA_CENTER);
  P.displayClear();
  P.displayText("0", PA_CENTER, SCROLL_SPEED, 0, PA_PRINT, PA_NO_EFFECT);
}

void loop() {
  server.handleClient();
  P.displayAnimate();
}

void handleRoot() {
  server.send(200, "text/html", html);
}

void handleCalc() {
  server.send(200, "text/plain", "OK");
}

void handleLEDUpdate() {
  if (server.hasArg("value")) {
    String value = server.arg("value");
    P.displayClear();
    P.displayText(value.c_str(), PA_CENTER, SCROLL_SPEED, 0, PA_PRINT, PA_NO_EFFECT);
  }
  server.send(200, "text/plain", "OK");
}

void handleBuzzer() {
  if (server.hasArg("volume")) {
    int volume = server.arg("volume").toInt();
    int frequency = 2000;
    int duration = 50;

    tone(buzzerPin, frequency, duration);
  }
  server.send(200, "text/plain", "OK");
}
