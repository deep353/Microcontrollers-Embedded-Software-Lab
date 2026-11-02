# Practical 03: Pushbutton and LED Control with Debouncing

**Course:** Microcontrollers & Embedded Software Lab  
**Course Code:** ET24MDM309  
**Assignment:** 03

## Aim
To interface a pushbutton switch and an LED with Arduino Uno and control the LED using a delay-based debounce method.

## Apparatus / Requirements
- Arduino Uno (ATmega328P)
- Momentary pushbutton switch
- 5 mm LED
- 220 ohm to 330 ohm current-limiting resistor
- Breadboard
- Jumper wires
- Computer with Arduino IDE 2.x
- USB cable

## Theory
A pushbutton is a mechanical switch used to provide a digital input to Arduino. Mechanical contacts can make and break contact several times during a press or release. This effect is called switch bouncing.

Debouncing avoids false or unstable readings. In this experiment, the program detects a LOW input, waits for 50 ms, and reads the button again. If it is still LOW, the press is accepted.

The button uses `INPUT_PULLUP`. Therefore, the input reads HIGH when the button is released and LOW when the button is pressed and connected to GND.

## Connections
- Pushbutton: connect between Arduino digital pin 7 and GND.
- LED anode (+): connect to Arduino digital pin 8 through a 220–330 ohm resistor.
- LED cathode (−): connect to GND.
- The Arduino internal pull-up resistor is enabled in the program using `INPUT_PULLUP`.

## Program
Open `Pushbutton_LED_Debounce.ino` in Arduino IDE.

## Algorithm
1. Configure digital pin 7 as `INPUT_PULLUP`.
2. Configure digital pin 8 as `OUTPUT`.
3. Read the pushbutton.
4. If the reading is LOW, wait for 50 ms and read it again.
5. If the second reading is still LOW, turn the LED ON.
6. If the button is released (HIGH), turn the LED OFF.
7. Repeat continuously.

## Procedure
1. Switch OFF or disconnect Arduino power before making connections.
2. Connect the pushbutton between pin 7 and GND.
3. Connect the LED to pin 8 through a current-limiting resistor, with its other terminal connected to GND.
4. Connect Arduino Uno to the computer using the USB cable.
5. Open Arduino IDE and select **Tools > Board > Arduino AVR Boards > Arduino Uno**.
6. Select the correct port under **Tools > Port**.
7. Open `Pushbutton_LED_Debounce.ino`.
8. Click **Verify**, then **Upload**.
9. Keep the button released; the input should be HIGH and the LED should remain OFF.
10. Press the button; after the 50 ms debounce check, the LED should turn ON.
11. Release the button; the input returns HIGH and the LED turns OFF.

## Expected Output / Observation
- Button released: input reads HIGH and LED is OFF.
- Button pressed: after debounce verification, input reads LOW and LED turns ON.
- The 50 ms delay and second reading help prevent false operation caused by switch bouncing.

## Conclusion
The pushbutton switch and LED are interfaced with Arduino Uno. `INPUT_PULLUP` provides a stable default input, and a 50 ms delay-based debounce check is used to confirm a valid button press before turning the LED ON.

## Viva Questions
1. What is a pushbutton switch?
2. What is switch bouncing?
3. Why is debouncing required?
4. What does `INPUT_PULLUP` do?
5. When `INPUT_PULLUP` is used, what is the button reading when it is released?
6. Why does the button read LOW when it is pressed in this circuit?
7. Why is a 50 ms delay used in the debounce program?
8. Why is the pushbutton read a second time after the delay?
9. Which Arduino pins are used for the button and LED in this program?
10. What happens to the LED when the button is released?

## Safety Note
Use a current-limiting resistor in series with the LED. Check the wiring before powering the circuit.
