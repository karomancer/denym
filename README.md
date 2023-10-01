# Neopatch

Arduino code for a cyberpunk-styled jacket with programmable embroidered snap-on RFID patches that control LED lighting effects & animations.

https://github.com/karomancer/jacket/assets/482817/d7755bc2-908b-44b0-81dd-d488e4cf00c5

---

See the full project documentation here!
https://karinachowtime.vercel.app/portfolio/neopatch

----

In short, we have a `jacket` file that instantiates all variables to be used in the rest of the project. Pin numbers, num of lights, NeoPixel instantiations…the works.

`animation_x` files include the animations for each light strand and matrix per type.

`helpers_light` includes light helpers that are not specific to any animation; such as setting up lights as the NeoPixel library requires via setup(), casing on what is read through the NTAGs and playing the appropriate animation, clearing all lights, etc.

`helpers_nfc` is where all the reading of the NFC magic is stored. It reads page by page and constructs a message, then looks for a delimiter (, in our case) and strips that message of extraneous characters.

`main` is where we have our setup() and loop() functions and call methods within helpers_x to read NTAGs and update lights.

