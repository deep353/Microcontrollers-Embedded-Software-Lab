# Practical 09: Interface an SPI-Based Graphical OLED and Display a Graph or Bitmap Image

**Course:** Microcontrollers & Embedded Software Lab  
**Course Code:** ET24MDM309  
**Assignment:** 09

## Aim
To interface a 128 × 64 SPI SSD1306 graphical OLED with Arduino Uno and ESP32 and display a plotted waveform and a small bitmap using the Arduino IDE.

## Apparatus
- Arduino Uno (ATmega328P)
- ESP32 DevKit (ESP32-WROOM-32)
- 128 × 64 SSD1306 graphical OLED, 4-wire SPI type (7-pin variant)
- 3.3 V-compatible logic level shifter for Uno if required by the OLED module
- Jumper wires
- Computer with Arduino IDE 2.x
- Adafruit GFX Library and Adafruit SSD1306 library
- USB cables for each board

## Theory
A graphical OLED (Organic Light-Emitting Diode) is a self-emissive display capable of showing text, lines, shapes, bitmaps and graphs. A 128 × 64 monochrome SSD1306 display contains 8192 pixels and requires 1024 bytes of framebuffer memory. Graphics are first drawn in a software buffer and transferred using `display.display()`.

Serial Peripheral Interface (SPI) is a synchronous master-slave communication protocol. The microcontroller supplies SCLK (clock) and MOSI (master-out, slave-in). The OLED also uses CS (chip select), DC (data/command selection), and RST (reset). Most SSD1306 SPI modules do not require MISO because the display primarily receives data.

**Important:** This practical uses a 7-pin SPI OLED module, not a 4-pin I2C OLED.

## Connections

### Arduino Uno hardware SPI

| OLED pin | Arduino Uno |
|---|---|
| VCC | 3.3 V or module-rated supply |
| GND | GND |
| SCK / CLK | D13 (SCK) |
| SDA / DIN / MOSI | D11 (MOSI) |
| CS | D10 |
| DC | D9 |
| RES / RST | D8 |

### ESP32 VSPI (default)

| OLED pin | ESP32 DevKit |
|---|---|
| VCC | 3.3 V |
| GND | GND |
| SCK / CLK | GPIO18 (SCLK) |
| SDA / DIN / MOSI | GPIO23 (MOSI) |
| CS | GPIO5 |
| DC | GPIO16 |
| RES / RST | GPIO17 |

**Voltage warning:** OLED breakout voltage ratings vary. When using an OLED with 3.3 V-only digital inputs on 5 V Arduino Uno, use a suitable logic-level shifter on SCK, MOSI, CS, DC and RST. Some breakout boards include onboard regulation and level shifting; verify the exact module. ESP32 GPIO uses 3.3 V logic.

## Required libraries
Install **Adafruit GFX Library** and **Adafruit SSD1306** using Arduino IDE Library Manager. Install any dependencies requested by the Library Manager.

## Programs
- `SPI_OLED_Arduino_Uno.ino` — Arduino Uno implementation.
- `SPI_OLED_ESP32.ino` — ESP32 implementation.

Both sketches display a heading, reference axes, a sine-like waveform and a 16 × 16 bitmap icon.

## Procedure - Part A: Arduino Uno
1. Disconnect power, identify OLED SPI pins, and make the connections shown in the Arduino Uno table.
2. Verify the OLED supply and signal-voltage specifications. Use a level shifter if required.
3. Install Adafruit GFX Library and Adafruit SSD1306 using Arduino IDE Library Manager. Install dependencies if requested.
4. Connect Arduino Uno through USB; select Arduino Uno and the correct COM port.
5. Open `SPI_OLED_Arduino_Uno.ino`. Click Verify and then Upload.
6. Confirm that the OLED shows the title, waveform graph and 16 × 16 bitmap icon.
7. Observe how the graph redraws and identify the commands used for drawing graphics.

## Procedure - Part B: ESP32
1. Disconnect power and connect the SPI OLED to ESP32 using GPIO18, GPIO23, GPIO5, GPIO16 and GPIO17 as listed above.
2. Install the ESP32 board support package and the Adafruit GFX / SSD1306 libraries.
3. Select ESP32 Dev Module (or the exact board), its COM port, and open `SPI_OLED_ESP32.ino`.
4. Verify and upload the program. Press EN/RESET if the display needs reinitialization.
5. Observe the waveform, text heading and bitmap on the OLED. Compare with Arduino Uno output.
6. Record the display type, SPI pins and observed graphic in the practical journal.

## Output / Observation
- Arduino Uno: SPI OLED displays a plotted sine-like waveform, reference axes and a 16 × 16 bitmap.
- ESP32: SPI OLED displays a plotted sine-like waveform, reference axes and a 16 × 16 bitmap.

## Precautions
- Confirm that the OLED is the SPI type and identify its 7-pin labels correctly.
- Do not connect a 3.3 V-only OLED logic input directly to 5 V Uno pins without level shifting.
- Observe correct SCK, MOSI, CS, DC and RST wiring; MOSI is sometimes labeled SDA or DIN on SPI displays.
- Common ground is essential. Never reverse VCC and GND.
- Match library configuration to the SSD1306 display resolution of 128 × 64.
- The Arduino Uno has 2 KB SRAM; the 1 KB display buffer leaves limited memory, so avoid large additional arrays.

## Conclusion
A 128 × 64 SSD1306 graphical OLED was interfaced with Arduino Uno and ESP32 using the SPI protocol. Both platforms displayed a waveform, reference axes and a bitmap, demonstrating graphical display programming and hardware SPI communication.

## Viva Questions
1. What is the difference between an OLED and an LCD?
2. What is SPI and which signals does it use?
3. What are the functions of SCK, MOSI, CS, DC and RST?
4. Why is MISO generally unnecessary for this display?
5. What is the purpose of Adafruit_GFX and Adafruit_SSD1306?
6. What does `display.display()` perform?
7. Why must the framebuffer be considered on Arduino Uno?
8. How many pixels are present in a 128 × 64 display?
9. Why is a level shifter sometimes necessary with Arduino Uno?
10. What is the difference between SPI and I2C OLED modules?
