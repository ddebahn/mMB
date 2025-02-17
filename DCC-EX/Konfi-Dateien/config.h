// Meine Hardware
// WiFi - Shield - Mega2560 Stellwerk --> 192.168.178.101
// WiFi - Shield - Mega2560 --> 192.168.178.88
// WiFi - ESP32 --> 192.168.178.58

// Der IP-Port, um mit einem WIFI- oder Ethernet-Shield zu kommunizieren.
#define IP_PORT 2560

// Scroll-Modus als 0, 1 oder 2 definieren
//  *  #define SCROLLMODE 0 ist kontinuierliches Scrollen (Bildschirm füllen, wenn möglich),
//  *  #define SCROLLMODE 1 ist pro Seite (abwechselnd zwischen den Seiten),
//  *  #define SCROLLMODE 2 ist pro Reihe (jeweils 1 Reihe nach oben).
#define SCROLLMODE 1

#define MOTOR_SHIELD_TYPE STANDARD_MOTOR_SHIELD

// LCD_DRIVER für I2C-Adresse 0x27, 16 Spalten, 2 Zeilen
// #define LCD_DRIVER 0x27, 16, 2

// LCD_DRIVER für I2C-Adresse 0x27, 20 Spalten, 4 Zeilen
#define LCD_DRIVER 0x27, 20, 4

// OLED_DRIVER [Adresse], Weite, Höhe in Pixeln (Adresse wird automatisch erkannt, wenn sie nicht angegeben wird)
// I2C-basierte Geräte mit 128 x 32 oder 128 x 64 SSD1306 I2C werden unterstützt.
// Verwenden Sie 132, 64 für ein SH1106-basiertes I2C-Gerät mit einem 128x64-Display.
// #define OLED_DRIVER 0x3c, 128, 64

// WIFI_SSID ist der Netzwerkname, WENN Sie Ihr vorhandenes Heimnetzwerk verwenden möchten.
// Ändern Sie dies NICHT, wenn Sie das WLAN im Access Point (AP)-Modus verwenden möchten.
//
// Wenn Sie die WIFI_SSID NICHT und die WIFI_PASSWORD NICHT festlegen,
// dann versucht der WLAN-Chip zunächst, sich mit dem zuvor
// konfiguriertes Netzwerk und wenn dies fehlschlägt, fallen Sie in den Access Point-Modus zurück.
// Die SSID des Access Points wird automatisch auf DCCEX_* gesetzt.
//
// Wenn Sie die WIFI_SSID einstellen, versucht der WLAN-Chip, eine Verbindung herzustellen
// an dieses (Heim-)Netzwerk im Stationsmodus (Client). Wenn ein WIFI_PASSWORD
// festgelegt ist (empfohlen), wird dieses Kennwort für den AP-Modus verwendet.
// Das Kennwort für den AP-Modus muss mindestens 8 Zeichen lang sein.
// #define WIFI_SSID "Your network name"            // Router SSID --> Heimnetzwerk
//													// AP-Modus --> (// entfernen, und den Namen so lassen)
// #define WIFI_PASSWORD "WiFi_Passwort"            // Router Passwort --> Heimnetzwerk
//													// AP-Modus --> (// entfernen + Password benennen))
#include <d:\DCC-EX.h>                              // meine SSID und Passwort, von meinem Router (Heimnetzwerk) (// im AP-Modus)

// WiFi - Shield - Access Point (192.168.4.1)
#define WIFI_HOSTNAME "dccex"

// #define ENABLE_WIFI true = USB und Wifi // false nur USB
// #define WIFI_CHANNEL 1
#define ENABLE_WIFI true
#define WIFI_CHANNEL 1


