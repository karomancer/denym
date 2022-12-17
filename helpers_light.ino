/**
    Light helpers
*/

void playAnimation() {
  if (animationType == "TWINKLE") {    
    twinkle();
  } else if (animationType == "FLAMES") {
    flames();
  } else if (animationType == "SAKURA") {
    sakura();
  } else {
    clearAllLights();
  }
}

void clearAllLights() {
  strip.clear();
  strip.show();

  strip2.clear();
  strip2.show();

  strip3.clear();
  strip3.show();

  strip4.clear();
  strip4.show();

  hoodStrip.clear();
  hoodStrip.show();

  flex.clear();
  flex.show();
}

void setupLights() {
  strip.begin();
  strip2.begin();
  strip3.begin();
  strip4.begin();
  hoodStrip.begin();
  
  flex.begin();
  flex.setBrightness(50);

  setupTwinkle();
  setupSakura();
}
