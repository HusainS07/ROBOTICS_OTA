#include <WiFi.h>
#include <ArduinoOTA.h>

// Wi-Fi credentials
const char* ssid = "ssid";
const char* password = "";

// Allowed ESP32 MAC address (replace with your device's MAC)
const String allowedMAC = "";  

// OTA password
const char* otaPassword = "admin";  // You can change this

void setup() {
  Serial.begin(115200);
  Serial.println("Booting...");

  // Connect to Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }

  // Print device info
  String mac = WiFi.macAddress();
  Serial.print("ESP32 MAC Address: ");
  Serial.println(mac);

  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Check if MAC matches allowed device
  if (mac == allowedMAC) {
    Serial.println("MAC matched! Enabling OTA...");

    // Set OTA password
    ArduinoOTA.setPassword(otaPassword);

    // OTA configuration
    ArduinoOTA
      .onStart([]() {
        String type = (ArduinoOTA.getCommand() == U_FLASH) ? "sketch" : "filesystem";
        Serial.println("Start updating " + type);
      })
      .onEnd([]() {
        Serial.println("\nEnd");
      })
      .onProgress([](unsigned int progress, unsigned int total) {
        Serial.printf("Progress: %u%%\r", (progress * 100) / total);
      })
      .onError([](ota_error_t error) {
        Serial.printf("Error[%u]: ", error);
        if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
        else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
        else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
        else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
        else if (error == OTA_END_ERROR) Serial.println("End Failed");
      });

    ArduinoOTA.begin();
    Serial.println("OTA Ready (password protected).");
  } else {
    Serial.println("MAC does not match. OTA disabled for this device.");
  }
}

void loop() {
  // Only handle OTA if MAC matched
  if (WiFi.macAddress() == allowedMAC) {
    ArduinoOTA.handle();
  }
}
