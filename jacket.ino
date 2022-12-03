#include <Wire.h>
#include <SPI.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_PN532.h>

// If using the breakout or shield with I2C, define just the pins connected
// to the IRQ and reset lines.  Use the values below (2, 3) for the shield!
#define PN532_IRQ   (2)
#define PN532_RESET (3)  // Not connected by default on the NFC Shield

#define MATRIX_PIN 8
#define MATRIX_CNT 64

#define STRIP_PIN 12
#define STRIP_CNT 90

#define STRIP2_PIN 11
#define STRIP2_CNT 90

#define POLLING_MS 500

/**
 * Instantiate NFC & light components
 */
Adafruit_PN532 nfc(PN532_IRQ, PN532_RESET);

Adafruit_NeoPixel flex = Adafruit_NeoPixel(MATRIX_CNT, MATRIX_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(STRIP_CNT, STRIP_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(STRIP2_CNT, STRIP2_PIN, NEO_GRB + NEO_KHZ800);


/**
 * Necessary variables for animations
 */
String animationType;
int timer;
