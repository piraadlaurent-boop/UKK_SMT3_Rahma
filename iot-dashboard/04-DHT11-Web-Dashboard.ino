#include "config.h"
#include "dht_sensor.h"
#include "oled_display.h"
#include "wifi_manager.h"
#include "async_server.h"

//variabel global
float currentTemp = 0.0;
float currentHum = 0.0;
unsigned long bootMillis = 0;
static unsigned long lastSensorMillis = 0;

void setup() {
    Serial.begin(SERIAL_BAUD);
    delay(1000);
    bootMillis = millis();

    serial.println();
    serial.println("==================================================");
    serial.println("PROYEK 4: DHT11 ASYNC WEB DASHBOARD (LITTLEFS)");
    serial.println("==================================================");

    //1.inisialisasi layar OLED
    initOLED();
    showConnectingWiFi(WIFI_SSID);

    //2. inisialisasi sensor DHT11
    initDHT();

    //3. mount file system LittleFS
    initLittleFS();

    //4. koneksi wi-fi
    bool connected = connectToWiFi();

    //5. inisialisasi Asynchronous web server
    if (connected) {
        initAsyncWebServer();
    }

    //6. baca data awal
    readDHT(currentTemp, currentHum);
    drawDashboardOled(currentTemp, currentHum, connected, localIPAddress);
}

void loop() {
    unsigned long now = millis();

    if (now - lastSensorMillis >= SENSOR_READ_INTERVAL) {
        lastSensorMillis = now;

        if (readDHT(currentTemp, currentHum)) {
            Serial.print("[ASYNC NODE] Suhu: ");
            Serial.print(currentTemp, 1);
            Serial.print(" C | Hum: ");
            Serial.print(currentHum, 1);
            Serial.println("%");

            //perbarui tampilan OLED fisik
            drawDashboardOled(currentTemp, currentHum, wifiConnected, localIPAddress);
        }
    }
}