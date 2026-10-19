/*
 * Plug and Make Kit - Project 5: Shake Alarm
 *
 * The alarm is always armed. The Modulino Movement module watches for a
 * shake (a big change in rotation rate). A shake trips the alarm: the
 * Pixels strip flashes red and the buzzer beeps for a few seconds, then the
 * alarm re-arms itself.
 *
 * Wiring:
 *   Modulino Movement - Qwiic/I2C bus
 *   Modulino Pixels   - Qwiic/I2C bus
 *   Modulino Buzzer   - Qwiic/I2C bus
 *   I2C 1602 LCD      - SDA/SCL/5V/GND to the header pins (not Qwiic)
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
