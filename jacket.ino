#include <Wire.h>
#include <SPI.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_PN532.h>

// If using the breakout or shield with I2C, define just the pins connected
// to the IRQ and reset lines.  Use the values below (2, 3) for the shield!
#define PN532_IRQ   (2)
#define PN532_RESET (3)  // Not connected by default on the NFC Shield

#define PIN 8
#define CNT 64
#define POLLING_MS 5000

/**
 * Instantiate NFC & light components
 */
Adafruit_PN532 nfc(PN532_IRQ, PN532_RESET);
Adafruit_NeoPixel flex = Adafruit_NeoPixel(CNT, PIN, NEO_GRB + NEO_KHZ800);

/**
 * Necessary variables for animations
 */
String animationType;
int timer;
