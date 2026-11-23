#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

//kredensial wi-fi
#define WIFI_SSID   "RPL SMK MVP"  //Ganti dengan SSID anda
#define WIFI_SSID   "*#Mufa161073*#"  //Ganti dengan password anda

//pinout sensor dht11
#define DHT_PIN 4
#define DHT_TYPE dht11

//pinout layar oled I2C
#define OLED_SDA    21
#define OLED_SCL    22
#define OLED_I2C_ADDR    0x3c
#define SCREEN_WIDHT    128
#define SCREEN_HEIGHT    64
#define OLED_RESET    -1

//KONFIGURASI SISTEM
#define SERIAL_BAUD     115200
#define SENSOR_READ_INTERVAL     2000 //BACA SENSOR SETIAP 2 DETIK

#endif //config_h