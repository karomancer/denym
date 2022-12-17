#include <Adafruit_NeoPixel.h>

int matrixTwinkle[MATRIX_CNT];
int stripTwinkle[STRIP_CNT];
int strip2Twinkle[STRIP2_CNT];
int strip3Twinkle[STRIP3_CNT];
int strip4Twinkle[STRIP4_CNT];
int hoodTwinkle[HOOD_CNT];

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

  for (int i = 0; i < HOOD_CNT; i++) {
    int y = stripTwinkle[i];
    int x = strip2Twinkle[i];
    int z = strip3Twinkle[i];
    int a = strip4Twinkle[i];
    int b = hoodTwinkle[i];

    strip.setPixelColor(i, strip.Color(y, y, y));
    strip2.setPixelColor(i, strip.Color(x,x,x));
    strip3.setPixelColor(i, strip.Color(z,z,z));
    strip4.setPixelColor(i, strip.Color(a,a,a));
    hoodStrip.setPixelColor(i, strip.Color(a,a,a));

    stripTwinkle[i]--;
    strip2Twinkle[i]--;
    strip3Twinkle[i]--;
    strip4Twinkle[i]--;
    hoodTwinkle[i]--;

    if (stripTwinkle[i] < 1) {
      stripTwinkle[i] = 255;
    }
    if(strip2Twinkle[i] < 1){
      strip2Twinkle[i] = 255;
    }
    if(strip3Twinkle[i] < 1){
      strip3Twinkle[i] = 255;
    }
    if(strip4Twinkle[i] < 1){
      strip4Twinkle[i] = 255;
    }
    if(hoodTwinkle[i] < 1) {
      hoodTwinkle[i] = 255;
    }
  }
  strip.show();  
  strip2.show();
  strip3.show();
  strip4.show();
  hoodStrip.show();
}

void setupTwinkle() {
  for (int i = 0; i < MATRIX_CNT; i++) {
    matrixTwinkle[i] = random(255);
  }

  for (int i = 0; i < STRIP_CNT; i++) {
    stripTwinkle[i] = random(255);
    strip2Twinkle[i] = random(255);
    strip3Twinkle[i] = random(255);
    strip4Twinkle[i] = random(255);
  }

  for (int i = 0; i < HOOD_CNT; i++) {
    hoodTwinkle[i] = random(255);
  }
}
