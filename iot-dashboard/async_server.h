#ifndef ASYNC_SERVER_H
#define ASYNC_SERVER_H

#include <LittleFS.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>
#include <config.h>

//objek server asinkron pada port 80
static AsyncWebServer asyncServer(80);

//refrensi variabel global
extern float currentTemp;
extern float currentHum;
extern bool wifiConnected;
extern unsigned long bootMillis;

/**
*inisialisasi flash file system littleFS
*/
inline bool initLittleFS(){
    if (!LittleFS.begin(true)) {
        Serial.println("[LittleFS] Gagal mount file system flash!");
        return false;
    }
    Serial.println("[LittleFS] file system berhasil dimuat."); 
    return true;
}

/**
*mendaftarkan rute web dan API asinkron
*/
inline void initAsyncWebServer() {
    //1. layani file statis (index.html, style.css) langsung dari littleFS
    asyncServer.serveStatic("/", LittleFS, "/").setDefaultFile("index.html");

    //2. Endpoint REST API Realtime: GET /api/now
    asyncServer.on("/api/now", HTTP_GET, [](AsyncWebServerRequest *request) {
      JsonDocument doc;
      
      if (isnan(currentTemp) || isnan(currentHum)) {
        doc["temp"] = nullptr;
        doc["hum"] = nullptr;
      } else {
        doc["temp"] = round(currentTemp * 10) / 10.0;
        doc["hum"] = round(currentHum * 10) / 10.0;
      }

      doc["online"] = wifiConnected;
      doc["rssi"] = WiFi.RSSI();
      doc["uptime"] = (millis() - bootMillis) / 1000;
      doc["ip"]     = WiFi.localIP().toString();
      doc["ssid"]     = WiFi.SSID();

      String response;
      serializeJson(doc, response);
      request->send(200, "application/json, response");
    });

    //3. fallback jika halaman tidak ditemukan
    asyncServer.onNotFound([] (AsyncWebServerRequest *request) {
        request->send(404, "text/plain, "404: Not Found pada ESP32 Async web server);
    });

    asyncServer.begin();
    Serial.println("[ASYNC HTTP] Server aktif dan siap melaayani request di background.");
}

#endif //ASYNC_SERVER_H

