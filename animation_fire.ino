#include <Adafruit_NeoPixel.h>

uint32_t fire_color   = flex.Color ( 80,  35,  00);
uint32_t off_color    = flex.Color (  0,  0,  0);

class NeoFire {
    Adafruit_NeoPixel &flex;    

  public:
    NeoFire(Adafruit_NeoPixel&);
    void Draw();
    void Clear();
    void AddColor(uint8_t position, uint32_t color);
    void SubstractColor(uint8_t position, uint32_t color);
    uint32_t Blend(uint32_t color1, uint32_t color2);
    uint32_t Substract(uint32_t color1, uint32_t color2);
};

///
/// Constructor
///
NeoFire::NeoFire(Adafruit_NeoPixel& n_flex)
  : flex (n_flex) {
}

///
/// Set all colors
///
void NeoFire::Draw()
{
  Clear();

  for (int i = 0; i < flex.numPixels(); i++) {
    AddColor(i, fire_color);
    int r = random(80);
    uint32_t diff_color = flex.Color ( r, r / 2, r / 2);
    SubstractColor(i, diff_color);
  }

  flex.show();  
}

///
/// Set color of LED
///
void NeoFire::AddColor(uint8_t position, uint32_t color)
{
  uint32_t blended_color = Blend(flex.getPixelColor(position), color);
  flex.setPixelColor(position, blended_color);
}

///
/// Set color of LED
///
void NeoFire::SubstractColor(uint8_t position, uint32_t color)
{
  uint32_t blended_color = Substract(flex.getPixelColor(position), color);
  flex.setPixelColor(position, blended_color);
}

///
/// Color blending
///
uint32_t NeoFire::Blend(uint32_t color1, uint32_t color2)
{
  uint8_t r1, g1, b1;
  uint8_t r2, g2, b2;
  uint8_t r3, g3, b3;

  r1 = (uint8_t)(color1 >> 16),
  g1 = (uint8_t)(color1 >>  8),
  b1 = (uint8_t)(color1 >>  0);

  r2 = (uint8_t)(color2 >> 16),
  g2 = (uint8_t)(color2 >>  8),
  b2 = (uint8_t)(color2 >>  0);

  return flex.Color(constrain(r1 + r2, 0, 255), constrain(g1 + g2, 0, 255), constrain(b1 + b2, 0, 255));
}

///
/// Color blending
///
uint32_t NeoFire::Substract(uint32_t color1, uint32_t color2)
{
  uint8_t r1, g1, b1;
  uint8_t r2, g2, b2;
  uint8_t r3, g3, b3;
  int16_t r, g, b;

  r1 = (uint8_t)(color1 >> 16),
  g1 = (uint8_t)(color1 >>  8),
  b1 = (uint8_t)(color1 >>  0);

  r2 = (uint8_t)(color2 >> 16),
  g2 = (uint8_t)(color2 >>  8),
  b2 = (uint8_t)(color2 >>  0);

  r = (int16_t)r1 - (int16_t)r2;
  g = (int16_t)g1 - (int16_t)g2;
  b = (int16_t)b1 - (int16_t)b2;
  if (r < 0) r = 0;
  if (g < 0) g = 0;
  if (b < 0) b = 0;

  return flex.Color(r, g, b);
}

///
/// Every LED to black
///
void NeoFire::Clear() {
  for (uint16_t i = 0; i < flex.numPixels (); i++)
    flex.setPixelColor(i, off_color);
}

NeoFire fireFlex(flex);
NeoFire fireStrip(strip);
NeoFire fireStrip2(strip2);
NeoFire fireStrip3(strip3);
NeoFire fireStrip4(strip4);
NeoFire fireStrip5(hoodStrip);

void flames() {
  fireFlex.Draw();
  fireStrip.Draw();
  fireStrip2.Draw();
  fireStrip3.Draw();
  fireStrip4.Draw();
  fireStrip5.Draw();
}
