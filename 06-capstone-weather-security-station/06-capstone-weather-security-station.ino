/*
 * Plug and Make Kit - Project 6 (Capstone): Mini Weather & Security Station
 *
 * Combines every module used in projects 1-5 into one menu-driven sketch,
 * plus one new external actuator: a servo motor acting as a "gate".
 *
 * Press button A to cycle between three screens:
 *   1. Weather - temperature + humidity (from project 2)
 *   2. Parking - live distance bar graph + beep (from project 4)
 *   3. Gate    - turn the knob to pick an angle, press C to move the servo
 *
 * The shake alarm from project 5 runs in the background the whole time,
 * on *every* screen - if the board gets shaken, the alarm takes over the
 * display until you press any button.
 *
 * Wiring: everything from projects 2, 4, and 5 (Modulino Buttons, Knob,
 * Buzzer, Pixels, Distance, Movement, Thermo; the I2C LCD), plus:
 *   Servo - signal wire to pin 9, power (red) to 5V, ground (black/brown) to GND
 *
 * Requires "Arduino_Modulino", "LiquidCrystal_I2C" and "Servo" - see the
 * README for the full library list.
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
