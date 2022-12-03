/**
 *  Light helpers
 */
 
void playAnimation() {
  if (animationType == "TWINKLE") {
    twinkle();
  } else if (animationType == "FLAMES") {
    flames();
  } else {
    clearAllLights();
  }
}

void clearAllLights() {
  flex.clear();
  flex.show();
}

void setupLights() {
  flex.begin();
  flex.setBrightness(50);

  // TWINKLE
  for (int i = 0; i < 64; i++) {
    fade[i] = random(255);
  }
}
