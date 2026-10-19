/*
 * Plug and Make Kit - Project 2: I2C LCD Weather Display
 *
 * Reads temperature and humidity from the Modulino Thermo module and shows
 * them on a separate I2C 1602 character LCD (2 lines, I2C backpack).
 *
 * The Modulino Thermo plugs into the Arduino's Qwiic connector (the Wire1 bus
 * on the UNO R4 WiFi). The I2C LCD is wired separately to the SDA/SCL header
 * pins (the Wire bus, same as A4/A5) and runs from 5V. The LCD backpack is
 * commonly at address 0x27 or 0x3F - see the README if the screen stays blank.
 *
 * Wiring:
 *   Modulino Thermo - plugged into the Arduino's Qwiic connector
 *   I2C LCD         - SDA, SCL, 5V and GND to the Arduino's header pins
 *
 * Requires "Arduino_Modulino" and "LiquidCrystal_I2C" (Library Manager).
 */

#include <Arduino_Modulino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  Modulino.begin();

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello!");    

}

void loop() {
  Serial.println("loop");
  delay(1000);
}
