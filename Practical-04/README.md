# Practical 04: Interface a 16x2 LCD and Display Text Messages

**Course:** Microcontrollers & Embedded Software Lab  
**Course Code:** ET24MDM309  
**Assignment:** 04

## Aim
To interface a 16x2 LCD with an I2C backpack to Arduino Uno and display text messages using I2C communication.

## Apparatus / Requirements
- Arduino Uno (ATmega328P)
- 16x2 HD44780-compatible LCD
- I2C backpack (commonly PCF8574)
- Jumper wires (male-to-female)
- Breadboard (optional)
- Computer with Arduino IDE 2.x
- USB-A to USB-B cable

## Theory
A 16x2 LCD displays 16 characters on each of two rows. An I2C backpack reduces the required connections to four: VCC, GND, SDA and SCL. The PCF8574 I/O expander on many backpacks converts I2C serial data into the parallel signals required by the LCD controller.

On Arduino Uno, SDA is A4 and SCL is A5. Common I2C addresses include 0x27 and 0x3F; the actual address depends on the backpack.

## Connections

| I2C LCD pin | Arduino Uno | Purpose |
|---|---|---|
| GND | GND | Common ground |
| VCC | 5V | Power |
| SDA | A4 / SDA | I2C data |
| SCL | A5 / SCL | I2C clock |

## Required library
In Arduino IDE, open **Tools > Manage Libraries** (or Library Manager), search for `LiquidCrystal I2C`, and install a compatible library. The `Wire` library is included with Arduino IDE.

## Program
Open `LCD_16x2_I2C.ino`.

The sketch below uses I2C address `0x27`. If your LCD backpack has a different address, change `LCD_ADDRESS` to the address found using an I2C scanner (common alternative: `0x3F`).

## Procedure
1. Switch OFF Arduino power before making or changing connections.
2. Connect LCD GND to Arduino GND and LCD VCC to Arduino 5V.
3. Connect LCD SDA to Arduino A4/SDA and LCD SCL to Arduino A5/SCL.
4. Connect Arduino Uno to the computer and open Arduino IDE.
5. Select **Tools > Board > Arduino AVR Boards > Arduino Uno** and select the correct COM port.
6. Install a compatible `LiquidCrystal_I2C` library if it is not already available. `Wire` is included with Arduino IDE.
7. Confirm the LCD backpack I2C address. Use the address for your module or an I2C scanner if required.
8. Open `LCD_16x2_I2C.ino`, verify and upload it.
9. Adjust the contrast potentiometer on the I2C backpack slowly until characters are clearly visible.
10. Observe the message on both rows. Change the text or cursor position in the program to test the display.

## Expected Output / Observation
- The LCD powers ON and displays the programmed text on the required rows and columns.
- Only four connections are required: VCC, GND, SDA and SCL.
- The displayed text changes when the message or cursor position in the program is modified.

## Precautions
- Check VCC and GND connections before powering the LCD.
- Do not interchange SDA and SCL.
- Use the correct I2C address for the backpack.
- Adjust contrast gradually; a blank display may be caused by contrast rather than a wiring fault.
- Do not connect or disconnect the module while the circuit is powered.

## Conclusion
A 16x2 LCD is interfaced with Arduino Uno through an I2C backpack. I2C communication reduces the required Arduino connections to four wires, and text messages are displayed at the required positions on the LCD.

## Viva Questions
1. What does 16x2 mean for an LCD?
2. What is the function of the HD44780 controller?
3. Why is an I2C backpack used with a 16x2 LCD?
4. What is the function of the PCF8574 on the I2C backpack?
5. Which Arduino Uno pins are used for SDA and SCL?
6. How many wires are required to connect an I2C LCD to Arduino Uno?
7. What is an I2C address?
8. Why may address 0x27 not work for every LCD backpack?
9. What is the use of the contrast potentiometer on the LCD module?
10. What are the roles of the Wire and LiquidCrystal_I2C libraries?
