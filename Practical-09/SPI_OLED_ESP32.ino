// Practical 09: SPI SSD1306 OLED - waveform graph and 16x16 bitmap
// Display: 128x64, 7-pin SPI module (NOT I2C)
// Libraries: Adafruit GFX and Adafruit SSD1306
//
// Wiring differs by board; see README.md.
// This sketch uses the hardware SPI bus and explicit CS, DC and RESET pins.

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <math.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define CS_PIN 5
#define DC_PIN 16
#define RESET_PIN 17

// 16x16 monochrome bitmap stored in program memory (32 bytes).
const unsigned char icon16x16[] PROGMEM = {
  0x03, 0xC0,
  0x0F, 0xF0,
  0x1C, 0x38,
  0x30, 0x0C,
  0x60, 0x06,
  0xC3, 0xC3,
  0xC7, 0xE3,
  0xCF, 0xF3,
  0xCF, 0xF3,
  0xC7, 0xE3,
  0xC3, 0xC3,
  0x60, 0x06,
  0x30, 0x0C,
  0x1C, 0x38,
  0x0F, 0xF0,
  0x03, 0xC0
};

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, DC_PIN, RESET_PIN, CS_PIN);

void setup() {
  if (!display.begin(SSD1306_SWITCHCAPVCC)) {
    while (true) {
      // Stop here if the OLED cannot be initialized.
    }
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(F("SPI OLED GRAPH"));
  display.drawLine(0, 12, 127, 12, SSD1306_WHITE);
  display.display();
  delay(1000);
}

void loop() {
  display.clearDisplay();

  // Heading
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(F("Sine Wave"));

  // Reference axes
  display.drawLine(4, 54, 123, 54, SSD1306_WHITE);
  display.drawLine(8, 18, 8, 58, SSD1306_WHITE);

  // Plot a sine-like waveform using line segments.
  for (int x = 9; x < 123; x++) {
    int y1 = 36 - (int)(12.0 * sin((x - 9) * 0.12));
    int y2 = 36 - (int)(12.0 * sin((x + 1 - 9) * 0.12));
    display.drawLine(x, y1, x + 1, y2, SSD1306_WHITE);
  }

  // Draw the 16x16 bitmap at the right upper area.
  display.drawBitmap(108, 0, icon16x16, 16, 16, SSD1306_WHITE);

  display.display();
  delay(250);
}
