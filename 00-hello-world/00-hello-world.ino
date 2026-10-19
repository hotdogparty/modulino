/*
 * Plug and Make Kit - Project 0: Hello World
 *
 * A starting point and a "reset everything" sketch. On startup it switches
 * off whatever the previous sketch left running - the Modulino Pixels, the
 * Buttons' LEDs, the Buzzer and the I2C LCD - then scrolls "Hello World!"
 * across the Uno R4 WiFi's built-in 12x8 LED matrix, over and over.
 *
 * Wiring (same as the rest of the series):
 *   Modulino modules  - Qwiic/I2C bus (any that are connected get reset)
 *   I2C 1602 LCD      - SDA/SCL/5V/GND to the header pins (not Qwiic)
 *
 * Requires "Arduino_Modulino", "LiquidCrystal_I2C" and "ArduinoGraphics"
 * (all from Library Manager). The LED matrix library comes with the board.
 */

#include <Arduino_Modulino.h>
#include <LiquidCrystal_I2C.h>
#include "ArduinoGraphics.h"  // must come before Arduino_LED_Matrix.h
#include "Arduino_LED_Matrix.h"

ModulinoPixels pixels;
ModulinoButtons buttons;
ModulinoBuzzer buzzer;
LiquidCrystal_I2C lcd(0x27, 16, 2);
ArduinoLEDMatrix matrix;

void setup() {
  Modulino.begin();
  pixels.begin();
  buttons.begin();
  buzzer.begin();
  lcd.init();
  matrix.begin();

  resetEverything();
}

void loop() {
  scrollText("Hello World!");
}

// Turns off everything a previous sketch might have left on.
void resetEverything() {
  for (int i = 0; i < 8; i++) {
    pixels.clear(i);
  }
  pixels.show();

  buttons.setLeds(false, false, false);
  buzzer.noTone();

  lcd.clear();
  lcd.noBacklight();

  matrix.clear();
}

// Scrolls a message once, in from the right edge and out the left, across the
// built-in LED matrix.
void scrollText(const char* message) {
  matrix.beginDraw();
  matrix.stroke(0xFFFFFFFF);
  matrix.textScrollSpeed(80);  // milliseconds per step - bigger is slower
  matrix.textFont(Font_5x7);
  matrix.beginText(matrix.width(), 1, 0xFFFFFF);  // start just off the right edge
  matrix.print(message);
  matrix.endText(SCROLL_LEFT);
  matrix.endDraw();
}
