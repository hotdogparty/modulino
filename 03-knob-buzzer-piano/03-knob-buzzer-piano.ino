/*
 * Plug and Make Kit - Project 3: Knob-Controlled Buzzer Piano
 *
 * Turn the Modulino Knob to pick one of 8 musical notes (C4 through C5),
 * shown by name on the I2C LCD. Press the knob's built-in button to play
 * the currently selected note on the Modulino Buzzer.
 *
 * Wiring:
 *   Modulino Knob   - Qwiic/I2C bus
 *   Modulino Buzzer - Qwiic/I2C bus
 *   I2C 1602 LCD    - SDA/SCL/5V/GND to the header pins (not Qwiic)
 *   (same LCD wiring as project 2 - see that project's schematic)
 *
 * Requires "Arduino_Modulino" and "LiquidCrystal_I2C" (both from Library Manager).
 */

#include <Arduino_Modulino.h>

void setup() {
  Serial.begin(115200);
  Modulino.begin();
}

void loop() {
  Serial.println("loop");
  delay(1000);
}
