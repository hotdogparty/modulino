/*
 * Plug and Make Kit - Starter sketch: using the Modulino library
 *
 * The smallest useful Modulino sketch. Press button A on the Modulino
 * Buttons module to light the first pixel on the Modulino Pixels module
 * green; press button B to turn it off again.
 *
 * If an I2C 1602 LCD is connected, the sketch also shows a message on it
 * ("Starter sketch" / "A=on  B=off"). The LCD is optional - without it the
 * sketch works exactly the same.
 *
 * Wiring: plug the Modulino Buttons and Modulino Pixels into the Uno R4's
 * Qwiic connector (chain them together). For the optional LCD, connect its
 * SDA, SCL, 5V and GND to the Arduino's header pins (not the Qwiic connector).
 *
 * Requires the "Arduino_Modulino" and "LiquidCrystal_I2C" libraries
 * (Library Manager).
 */

#include <Arduino_Modulino.h>
#include <LiquidCrystal_I2C.h>

// One object per module. There is only one of each type in the kit, so the
// library finds each module on the Qwiic bus by itself - no addresses needed.
ModulinoButtons buttons;
ModulinoPixels pixels;

// The LCD is optional, so it is only created if we find one (see setup()).
// Its backpack is at address 0x27 or 0x3F depending on the make.
LiquidCrystal_I2C* lcd = nullptr;

// Returns true if something answers on the header I2C bus (Wire) at this address.
bool i2cDevicePresent(byte address) {
  Wire.beginTransmission(address);
  return Wire.endTransmission() == 0;
}

void setup() {
  Serial.begin(115200);

  Modulino.begin();  // start the Qwiic bus - always do this first

  // Each module's begin() returns false if that module isn't found.
  if (!buttons.begin()) Serial.println("Buttons module not found - check the Qwiic cable");
  if (!pixels.begin())  Serial.println("Pixels module not found - check the Qwiic cable");

  // The LCD is on the header pins (Wire), separate from the Qwiic bus.
  Wire.begin();
  byte lcdAddress = 0;
  if (i2cDevicePresent(0x27)) lcdAddress = 0x27;
  else if (i2cDevicePresent(0x3F)) lcdAddress = 0x3F;

  if (lcdAddress != 0) {
    lcd = new LiquidCrystal_I2C(lcdAddress, 16, 2);  // address, columns, rows
    lcd->init();
    lcd->backlight();
    lcd->setCursor(0, 0);  // column, row (both start at 0)
    lcd->print("Starter sketch");
    lcd->setCursor(0, 1);
    lcd->print("A=on  B=off");
  } else {
    Serial.println("LCD not found - skipping (optional)");
  }
}

void loop() {
  // update() returns true only when a button has just been pressed or released.
  if (buttons.update()) {
    if (buttons.isPressed('A')) {
      pixels.set(0, GREEN, 40);  // pixel number, color, brightness (0-100)
      pixels.show();             // nothing changes until you call show()
    } else if (buttons.isPressed('B')) {
      pixels.clear(0);           // turn pixel 0 off
      pixels.show();
    }
  }
}
