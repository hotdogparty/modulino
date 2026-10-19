/*
 * Plug and Make Kit - Project 1: Traffic Light Simulator
 *
 * Uses the Modulino Buttons and Modulino Pixels modules over the shared
 * Qwiic/I2C bus. Button A = green (go), Button B = red (stop), Button C =
 * yellow (caution). Pressing a button lights its own LED and fills the
 * Pixels strip with the matching color.
 *
 * Wiring: Modulino Buttons and Modulino Pixels chained together on the
 * Qwiic/I2C bus, plugged into the Arduino's Qwiic connector (or a Modulino
 * Base Qwiic breakout). No other wiring needed.
 *
 * Requires the "Arduino_Modulino" library (Library Manager).
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
