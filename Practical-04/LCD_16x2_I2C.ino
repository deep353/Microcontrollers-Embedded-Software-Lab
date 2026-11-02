// Practical 04: Interface a 16x2 LCD using an I2C backpack
// Board: Arduino Uno
// Connections: VCC -> 5V, GND -> GND, SDA -> A4, SCL -> A5
// Install a compatible LiquidCrystal_I2C library before compiling.

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Change 0x27 if an I2C scanner finds a different address (often 0x3F).
const byte LCD_ADDRESS = 0x27;

LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);

void setup() {
  lcd.init();       // Initialize the LCD
  lcd.backlight();  // Turn on the backlight

  lcd.setCursor(0, 0);
  lcd.print("Hello, Arduino!");

  lcd.setCursor(0, 1);
  lcd.print("I2C LCD Working");
}

void loop() {
  // The message remains displayed.
}
