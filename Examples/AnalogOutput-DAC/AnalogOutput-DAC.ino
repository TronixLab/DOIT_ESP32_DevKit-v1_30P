/********************************************* ESP32 DAC EXAMPLE *************************************************
  ESP32 has two 8-bit DAC (digital to analog converter) channels, connected to GPIO25 (Channel 1) and GPIO26 (Channel 2).
  An 8-bit DAC has 256 discreet values ranges from 0-255 (0-3.3V).
  DACs are used to convert digital signals into analog signals.DACs has many applications like voltage control.
*******************************************************************************************************************/

#define DAC_1 25
#define DAC_2 26

void setup() {
}

void loop() {
  // increase the LED brightness
  for (int voltStep = 0; voltStep <= 255; voltStep++) {
    // changing the LED brightness with DAC
    dacWrite(DAC_1, voltStep);
    delay(10);
  }

  // decrease the LED brightness
  for (int voltStep = 255; voltStep >= 0; voltStep--) {
    // changing the LED brightness with DAC
    dacWrite(DAC_1, voltStep);
    delay(10);
  }
}
