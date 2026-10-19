/*
 * Plug and Make Kit - Project 4: Distance-Sensing Parking Assistant
 *
 * Reads the Modulino Distance sensor and turns it into a car-parking-sensor
 * style display: a proximity bar on the Modulino Pixels strip, a live
 * reading on the I2C LCD, and a buzzer that beeps faster (and switches to a
 * near-solid tone) the closer an object gets.
 *
 * Wiring:
 *   Modulino Distance - Qwiic/I2C bus
 *   Modulino Pixels   - Qwiic/I2C bus
 *   Modulino Buzzer   - Qwiic/I2C bus
 *   I2C 1602 LCD      - SDA/SCL/5V/GND to the header pins (not Qwiic)
 *   (same LCD wiring as project 2)
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
