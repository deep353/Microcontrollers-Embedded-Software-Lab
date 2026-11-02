# Practical 06: Generate PWM Signals and Control Actuators

**Course:** Microcontrollers & Embedded Software Lab  
**Course Code:** ET24MDM309  
**Assignment:** 06

## Aim
To generate PWM signals using Arduino Uno and study their use for LED brightness control, buzzer drive control, and DC motor speed control.

## Apparatus
- Arduino Uno (ATmega328P)
- 5 mm LED and 220–330 ohm resistor
- Low-current active buzzer or passive piezo buzzer
- Small DC motor (use supply voltage according to motor rating)
- L293D dual H-bridge motor driver
- External motor power supply matching the motor rating
- Breadboard and jumper wires
- Computer with Arduino IDE 2.x and USB cable

## Theory
Pulse Width Modulation (PWM) controls average power delivered to a load by switching a digital output rapidly between HIGH and LOW. Duty cycle is the percentage of one PWM period for which the signal is HIGH:

Duty Cycle (%) = (T_ON / T) x 100

Arduino Uno supports PWM on pins 3, 5, 6, 9, 10 and 11. `analogWrite()` accepts values from 0 to 255: 0 is approximately 0%, 128 approximately 50%, and 255 approximately 100%. It produces a PWM waveform, not a true analog voltage.

The LED brightness generally increases with duty cycle. A low-current active buzzer may respond to PWM drive level. A passive piezo buzzer needs an audible-frequency alternating signal; `tone()` is preferable for controlling its pitch. A DC motor must be driven through a motor driver such as the L293D, not directly from an Arduino GPIO pin.

## Part A: LED Brightness Control

### Connections
- Arduino D9 (PWM) -> 220–330 ohm resistor -> LED anode (+)
- LED cathode (-) -> GND

### Program
Open `PWM_LED_Brightness.ino`. The sketch gradually changes PWM values from 0 to 255 and back down.

## Part B: Buzzer Control

### Connections
- For a low-current active buzzer only: buzzer positive (+) -> D6; buzzer negative (-) -> GND.
- If buzzer current exceeds the safe GPIO current, use a suitable transistor driver and base/gate resistor.
- For a passive piezo buzzer, use the included `tone()` example to control frequency; pitch is mainly determined by frequency, not PWM duty cycle.

### Program
Open `PWM_Buzzer_Control.ino`. It demonstrates a low-current active buzzer with PWM values. Do not connect a higher-current buzzer directly to the Arduino pin.

## Part C: DC Motor Speed Control Using L293D

### Connections
- Arduino D9 (PWM) -> L293D EN1 (pin 1)
- Arduino D8 -> L293D IN1 (pin 2)
- Arduino D7 -> L293D IN2 (pin 7)
- Motor terminals -> L293D OUT1 (pin 3) and OUT2 (pin 6)
- L293D logic supply Vcc1 (pin 16) -> Arduino 5V
- L293D motor supply Vcc2 (pin 8) -> external motor supply positive (within the motor/driver ratings)
- L293D GND pins 4, 5, 12, 13 -> common GND
- Arduino GND -> external motor supply negative / common GND
- Place the motor supply and wiring according to the motor and L293D ratings. Do not power the motor from an Arduino GPIO pin.

### Program
Open `PWM_DC_Motor_L293D.ino`. It sets one direction and applies PWM values 80, 150 and 255 to EN1, then stops the motor.

## Typical PWM Values

| analogWrite() value | Approx. duty cycle | Typical observation |
|---:|---:|---|
| 0 | 0% | Output OFF |
| 64 | 25% | Low average drive |
| 128 | 50% | Medium average drive |
| 192 | 75% | High average drive |
| 255 | 100% | Fully ON |

## Procedure
### Part A: LED
1. Connect an LED to a PWM-capable Arduino pin through a 220–330 ohm series resistor.
2. Select Arduino Uno and the correct COM port in Arduino IDE.
3. Upload `PWM_LED_Brightness.ino`.
4. Observe the LED brightness as PWM duty cycle changes.

### Part B: Buzzer
1. Connect a low-current active buzzer as described above; use a transistor driver if required.
2. Upload `PWM_Buzzer_Control.ino`.
3. Observe the buzzer response at different PWM values.
4. For a passive piezo buzzer, use `tone()` and note that pitch is controlled mainly by frequency.

### Part C: DC motor
1. Switch OFF power and connect the L293D, Arduino Uno, DC motor and external motor supply.
2. Connect D9 (PWM) to EN1, D8 to IN1 and D7 to IN2. Connect the motor to OUT1 and OUT2.
3. Connect all required L293D ground pins and make Arduino ground common with the motor supply ground.
4. Set IN1 and IN2 for one fixed motor direction.
5. Upload `PWM_DC_Motor_L293D.ino`.
6. Observe and record motor speeds at PWM values 80, 150 and 255. If the motor does not start at a low value, increase the duty cycle gradually.
7. Set PWM to 0 and confirm that the motor stops.

## Expected Output / Observation
- LED brightness increases as PWM duty cycle increases.
- The buzzer response changes with applied PWM drive; passive-buzzer pitch is mainly determined by signal frequency.
- DC motor speed generally increases as PWM duty cycle applied to the L293D enable pin increases.

## Precautions
- Always use a current-limiting resistor with the LED.
- Do not connect a DC motor directly to an Arduino GPIO pin.
- Use a motor supply that matches the motor voltage rating and the driver limits.
- Make Arduino and external motor-supply grounds common.
- Use a transistor driver for a buzzer if its current is above the safe GPIO limit.
- Do not change Arduino timer registers during this experiment unless the effect on PWM and other Arduino functions is understood.

## Conclusion
PWM signals were generated using Arduino Uno and their effect on different loads was studied. PWM duty cycle controlled the average power delivered to an LED, buzzer and DC motor, while the L293D motor driver provided the required current path for motor control.

## Viva Questions
1. What is PWM?
2. What is duty cycle?
3. Does `analogWrite()` generate a true analog voltage on Arduino Uno?
4. What is the range of values accepted by `analogWrite()`?
5. Which Arduino Uno pins support PWM?
6. Why does LED brightness change with PWM duty cycle?
7. Why is a resistor required with an LED?
8. What is the difference between an active buzzer and a passive piezo buzzer?
9. Why should a DC motor not be connected directly to an Arduino GPIO pin?
10. What is the function of the L293D motor-driver IC?
