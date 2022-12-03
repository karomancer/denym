#include <Wire.h>
#include <SPI.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_PN532.h>

void setup(void) {
  Serial.begin(1000000);
  setupLights();
  setupNFCReader();
}

void loop(void) {
  playAnimation();

  if (++timer % POLLING_MS == 0) {
    readNFC();
  }
}
