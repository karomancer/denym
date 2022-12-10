#include <Wire.h>
#include <SPI.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_PN532.h>

void setup(void) {
  Serial.begin(9600);
  setupLights();
  setupNFCReader();
}

void loop(void) {
  playAnimation();
  readNFC();
}
