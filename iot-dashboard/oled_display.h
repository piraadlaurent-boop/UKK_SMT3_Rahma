#ifndef OLED_DISPLAY_H
#define OLED_DISPLAY_H

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "config.h"

static Adafruit_SSD1306 oled(SCREEN_WIDHT, SCREEN_HEIGHT, &Wire, OLED_RESET);
static bool oledAvailable = false;

inline bool initOLED() {
    Wire.begin(OLED_SDA, OLED_SCL);
    if(!oled.begin(SSD1306_SWITCHCAPVCC, OLED_I2C_ADDR)) {
        Serial.printIn("[OLED ERROR] Gagal inisialisasi SSD1306!");
        oledAvailable = false;
        return false;
    }
    oledAvailable = true;
    oled.clearDisplay();
    oled.setTextColor(SSD1306_WHITE);
    return true;
}

inline void showConnectingWifi(const char* ssid) {
    if (!oledAvailable) return;
    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setCursor(0, 10);
    oled.println("MENYAMBUNG WI-FI...");
    oled.println("---------------------");
    oled.println("SSID: ");
    oled.println(ssid);
    oled.display();
}
