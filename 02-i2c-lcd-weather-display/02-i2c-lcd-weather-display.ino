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
ModulinoThermo thermo;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Testing Serial Monitor");

  Modulino.begin();
  // Initialize the Modulino Thermo and halt if the sensor is not detected
  if (!thermo.begin()) {
    Serial.println("- Modulino Thermo not detected! Check the Qwiic connection...");
    while (1);
  }
  Serial.println("Modulino Worked");
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
}

void loop() {
  float temperature = thermo.getTemperature();
  float humidity = thermo.getHumidity();
  lcd.setCursor(0, 0);
  lcd.print("Temperature ");
  lcd.setCursor(13, 0);
  lcd.print(temperature);
  lcd.setCursor(0, 1);
  lcd.print("Humidity ");
  lcd.setCursor(9, 0);
  lcd.print(humidity);
  Serial.println("loop");
  delay(1000);
}
