int fade[64];

void twinkle() {
  for (int i = 0; i < 64; i++) {
    int y = fade[i];
    flex.setPixelColor(i, flex.Color(y, y, y));
    fade[i]--;
    if (fade[i] < 1) {
      fade[i] = 255;
    }
  }
  flex.show();
}
