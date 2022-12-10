#include <Adafruit_NeoPixel.h>

int matrixTwinkle[MATRIX_CNT];
int stripTwinkle[STRIP_CNT];

void twinkle() {  
  for (int i = 0; i < MATRIX_CNT; i++) {
    int y = matrixTwinkle[i];
    flex.setPixelColor(i, flex.Color(y, y, y));
    matrixTwinkle[i]--;
    if (matrixTwinkle[i] < 1) {
      matrixTwinkle[i] = 255;
    }
  }
  flex.show();

  for (int i = 0; i < STRIP_CNT; i++) {
    int y = stripTwinkle[i];
    strip.setPixelColor(i, strip.Color(y, y, y));
    stripTwinkle[i]--;
    if (stripTwinkle[i] < 1) {
      stripTwinkle[i] = 255;
    }
  }
  strip.show();  
}

void setupTwinkle() {
  for (int i = 0; i < MATRIX_CNT; i++) {
    matrixTwinkle[i] = random(255);
  }

  for (int i = 0; i < STRIP_CNT; i++) {
    stripTwinkle[i] = random(255);
  }
}
