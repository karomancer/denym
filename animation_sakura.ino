const int FLOWERS_CNT = 15;

int flowerY[FLOWERS_CNT];
int flowerX[FLOWERS_CNT];

void setupSakura() {
  for (int i = 0; i < FLOWERS_CNT; i++) {
    flowerY[i] = random(8);
    flowerX[i] = random(8);
  }
}

int getCellNumber(int row, int col) {
  return row % 2 == 0 ? 8 * row + col : 8 * row + (7-col);
}

void chase(uint32_t c, uint32_t c2) {
  for (uint16_t i = 0; i < strip.numPixels() + STRIP_CNT; i += 1) {
    strip.setPixelColor(i, c);       // Draw new pixel
    strip.setPixelColor(i - 2, c2);  // Erase pixel a few steps back
    strip.setPixelColor(i - 10, c);
    strip.setPixelColor(i - 12, c2);
    strip.setPixelColor(i - 14, c);
    strip.setPixelColor(i - 15, c2);
    flex.fill(c2);
    for (int j = 0; j < FLOWERS_CNT; j++) {
      flex.setPixelColor(getCellNumber(flowerX[j], flowerY[j]), c);
      flowerY[j] -= 1;
      flex.show();
      if (flowerY[j] < 0) {
        flowerY[j] = 8;
      }
    }
    strip.show();
    delay(100);
  }
}

void sakura() {
  chase(strip.Color(255, 120, 150), strip.Color(75, 255, 255));
}
