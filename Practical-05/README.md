# Practical 05: Timer1-Based Periodic LED Task with Pushbutton and I2C LCD

**Course:** Microcontrollers & Embedded Software Lab  
**Course Code:** ET24MDM309  
**Assignment:** 05

## Aim
To configure Arduino Uno Timer1 in CTC mode so that the onboard LED toggles periodically through a compare-match interrupt, while the main program reads a pushbutton and displays its state on a 16x2 I2C LCD.

## Apparatus
- Arduino Uno (ATmega328P)
- 16x2 LCD with I2C backpack (HD44780-compatible, commonly PCF8574)
- Momentary pushbutton switch
- Breadboard and jumper wires
- Computer with Arduino IDE 2.x
- USB cable

## Theory
Timer1 is a 16-bit hardware timer in the ATmega328P. In Clear Timer on Compare Match (CTC) mode, the counter is cleared when it matches OCR1A. With a 16 MHz Arduino Uno clock and prescaler 1024, the timer tick frequency is 15,625 Hz and each tick is 64 microseconds.

For an interrupt interval of approximately 1.5 seconds, OCR1A is set to 23,437. Each interrupt toggles the onboard LED, so a complete ON-OFF blink cycle takes approximately 3 seconds.

The pushbutton is connected between D7 and GND and configured as INPUT_PULLUP. Therefore, released = HIGH and pressed = LOW. The main loop debounces the button and updates the LCD only when the state changes. The Timer1 interrupt continues independently.

## Circuit Connections

| Component pin | Arduino Uno connection | Purpose |
|---|---|---|
| Onboard LED | D13 | Periodic output toggled by Timer1 ISR |
| Pushbutton terminal 1 | D7 | Digital input with INPUT_PULLUP |
| Pushbutton terminal 2 | GND | Pressed state produces LOW |
| LCD SDA | A4 / SDA | I2C data |
| LCD SCL | A5 / SCL | I2C clock |
| LCD VCC | 5V | LCD power |
| LCD GND | GND | Common ground |

## Required library
Install a compatible `LiquidCrystal_I2C` library using Arduino IDE Library Manager. The `Wire` library is included with Arduino IDE.

## Timer Calculation
- Arduino Uno clock = 16 MHz
- Prescaler = 1024
- Timer tick frequency = 16,000,000 / 1024 = 15,625 Hz
- Timer tick period = 1 / 15,625 = 64 microseconds
- OCR1A = (16,000,000 x 1.5 / 1024) - 1, approximately 23,437

## Algorithm
1. Configure D13 as output and D7 as INPUT_PULLUP.
2. Initialize the 16x2 I2C LCD and show the initial button state.
3. Configure Timer1 in CTC mode with prescaler 1024.
4. Set OCR1A to 23,437 and enable the Timer1 Compare Match A interrupt.
5. In the ISR, toggle the onboard LED only.
6. In the main loop, read and debounce the pushbutton.
7. When the stable button state changes, update the LCD with PRESSED or RELEASED.
8. Repeat continuously while Timer1 independently toggles the LED.

## Procedure
1. Switch OFF Arduino Uno before making external connections.
2. Connect the pushbutton between D7 and GND. No external pull-up resistor is required because INPUT_PULLUP is used.
3. Connect the I2C LCD: VCC to 5V, GND to GND, SDA to A4 and SCL to A5.
4. Connect Arduino Uno to the computer and select Arduino Uno and the correct COM port in Arduino IDE.
5. Install a compatible LiquidCrystal_I2C library if it is not already installed.
6. Open `Timer1_Button_LCD.ino`. Change LCD address 0x27 if an I2C scanner identifies a different address.
7. Verify and upload the program. Adjust the LCD contrast potentiometer if the text is not visible.
8. Observe the onboard LED. It should change state approximately every 1.5 seconds.
9. Press and release the pushbutton. Observe `Button: PRESSED` and `Button: RELEASED` on the LCD.
10. Verify that LED timing continues while the button is operated and the LCD is updated.

## Expected Output / Observation
- The onboard LED changes state approximately every 1.5 seconds; one complete blink cycle is approximately 3 seconds.
- The LCD shows `Button: PRESSED` when D7 is connected to GND through the pressed switch.
- The LCD shows `Button: RELEASED` when the switch is released.
- Button reading and LCD updating do not stop the Timer1-based periodic LED task.

## Precautions
- Switch OFF power before changing LCD or pushbutton connections.
- Confirm the LCD I2C address and do not interchange SDA and SCL.
- Keep Arduino Uno and LCD grounds common.
- Do not call `lcd.print()`, `delay()`, `Serial.print()` or other lengthy functions inside the ISR.
- Declare data shared with an ISR as `volatile`.
- Do not use Timer1-dependent libraries or PWM on pins 9 and 10 simultaneously without considering register conflicts.
- Do not modify Timer0 registers; Timer0 supports `millis()` and `delay()`.

## Conclusion
Timer1 is configured in CTC mode to generate a compare-match interrupt approximately every 1.5 seconds. The ISR toggles the onboard LED, while the main program independently reads a pushbutton and displays its state on the I2C LCD. This demonstrates hardware-timer-based periodic operation alongside foreground tasks.

## Viva Questions
1. What is the difference between `delay()`, a `millis()`-based software timer and a hardware timer interrupt?
2. Why is Timer1 suitable for generating a 1.5-second interval?
3. What is the purpose of the prescaler?
4. What does CTC mode mean?
5. What are the functions of TCNT1 and OCR1A?
6. Which bits select CTC mode and a prescaler of 1024 in this program?
7. Why must data shared with an ISR be declared `volatile`?
8. Why should LCD operations and `delay()` not be placed inside the ISR?
9. Why does the button read LOW when pressed with INPUT_PULLUP?
10. Why does one complete LED blink cycle take approximately 3 seconds although the interrupt interval is 1.5 seconds?
