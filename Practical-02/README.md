# Practical 02: LED Interfacing Using Delay and Non-Blocking Timing

**Course:** Microcontrollers & Embedded Software Lab (ET24MDM309)

## Aim
To interface an LED with Arduino Uno and toggle it using software delay and non-blocking timing based on `millis()`.

## Requirements
Arduino Uno, LED, 220–330 ohm resistor, breadboard, jumper wires, USB cable, Arduino IDE 2.x.

## Connections
- **Part A:** Arduino D13 → resistor → LED anode (+); LED cathode (−) → GND.
- **Part B:** Move the signal connection from D13 to **D8**; keep resistor and GND connection.
- Switch off/disconnect power before rewiring.

## Programs
1. `LED_Blink_Delay.ino` — toggles LED with `delay(1000)`; blocking method.
2. `LED_Blink_Millis.ino` — toggles LED every 1000 ms using `millis()`; non-blocking method.

## Procedure
1. Connect the LED for Part A using D13 and a current-limiting resistor.
2. In Arduino IDE, select Arduino Uno and the correct COM port.
3. Open, verify and upload `LED_Blink_Delay.ino`.
4. Observe LED ON for 1 second and OFF for 1 second repeatedly.
5. Disconnect power and move the LED signal to D8 for Part B.
6. Open, verify and upload `LED_Blink_Millis.ino`.
7. Observe LED toggling every 1000 ms while `loop()` remains free for other work.

## Expected Output
- **Delay method:** LED ON for 1 second and OFF for 1 second, repeatedly.
- **Non-blocking method:** LED changes state every 1 second without a blocking `delay()`.

## Conclusion
The LED can be toggled using both `delay()` and `millis()`. The `delay()` method blocks program execution during waiting, while the `millis()` method permits other work in the main loop.

## Evidence
Add your own circuit photos or output screenshots after testing on hardware. These programs are provided for testing; successful execution has not been independently verified.
