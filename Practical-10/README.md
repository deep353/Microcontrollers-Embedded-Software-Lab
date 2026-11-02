# Practical 10: Read Analog Sensor Data Using ADC and Display Filtered Output

**Course:** Microcontrollers & Embedded Software Lab  
**Course Code:** ET24MDM309  
**Assignment:** 10

## Aim
To interface an LM35 analog temperature sensor with Arduino Uno, acquire the sensor output using the inbuilt ADC, apply a moving-average filter to reduce fluctuations, and display the raw and filtered temperature values on the Serial Monitor.

## Apparatus
- Arduino Uno (ATmega328P-based development board)
- LM35 temperature sensor (10 mV/°C)
- Breadboard
- Male-to-male jumper wires
- Computer with Arduino IDE 2.x and Serial Monitor
- USB-A to USB-B cable

## Theory
The Arduino Uno uses the ATmega328P microcontroller, which contains a 10-bit successive-approximation ADC. The analog input pins A0 to A5 can be used to measure analog voltages. With the default 5 V reference, `analogRead()` converts an input voltage from approximately 0 V to 5 V into a digital value from 0 to 1023.

For a 5 V reference, one ADC count represents approximately 5/1023 V = 4.89 mV.

- Voltage (V) = ADC reading × 5.0 / 1023.0
- LM35 temperature (°C) = Voltage (V) × 100

The LM35 output voltage is proportional to temperature and has a nominal scale factor of 10 mV per °C. ADC readings can fluctuate because of electrical noise, ADC quantization, supply variation and sensor noise. A moving-average filter reduces short-term changes by averaging 10 consecutive samples.

- Filtered ADC = (Sample1 + Sample2 + ... + Sample10) / 10

## Connections

| LM35 pin | Arduino Uno |
|---|---|
| VCC | 5V |
| VOUT | A0 |
| GND | GND |

**Important:** LM35 package pin order can vary by package/manufacturer. Identify the actual VCC, VOUT and GND pins from the sensor datasheet and the flat-face/pin diagram before wiring. Do not assume pin order without checking.

## Algorithm
1. Initialize serial communication at 9600 baud.
2. Read the LM35 output at analog input A0 using `analogRead()`.
3. Take 10 ADC samples and add them to a running total.
4. Calculate the average of the 10 samples to obtain the filtered ADC value.
5. Convert the filtered ADC value into voltage.
6. Convert the voltage into temperature in °C using the LM35 scale factor.
7. Display the raw ADC reading, filtered value, voltage and filtered temperature on Serial Monitor.
8. Repeat the process continuously.

## Program
Open `LM35_ADC_Moving_Average.ino` in Arduino IDE. The sketch reads ten samples from A0, averages them, converts the average to voltage and temperature, and prints the raw and filtered readings at 9600 baud.

## Procedure
1. Switch OFF the Arduino Uno before making or changing circuit connections.
2. Place the LM35 sensor on the breadboard and identify its VCC, VOUT and GND pins correctly.
3. Connect LM35 VCC to Arduino 5V, VOUT to analog input A0, and GND to Arduino GND.
4. Connect Arduino Uno to the computer using the USB cable and open Arduino IDE.
5. Select Tools → Board → Arduino AVR Boards → Arduino Uno and select the correct COM port.
6. Enter or open the program in Arduino IDE, verify it, and upload it to Arduino Uno.
7. Open Serial Monitor and set the baud rate to 9600.
8. Observe the raw ADC value and filtered ADC value. The filtered value should show less fluctuation than individual raw readings.
9. Observe the calculated voltage and temperature. Warm the LM35 gently by holding it between fingers and note the temperature rise.
10. Allow the sensor to return toward room temperature and observe the decrease in displayed temperature.
11. Record representative readings in the observation table.

## Output / Observation
Typical Serial Monitor output (illustrative values):

```text
Raw ADC = 51   Filtered ADC = 51.20   Voltage = 0.250 V   Temperature = 25.02 C
Raw ADC = 52   Filtered ADC = 51.40   Voltage = 0.251 V   Temperature = 25.12 C
Raw ADC = 50   Filtered ADC = 51.30   Voltage = 0.251 V   Temperature = 25.07 C
```

| Sr. No. | Raw ADC | Filtered ADC | Voltage (V) | Temperature (°C) |
|---:|---:|---:|---:|---:|
| 1 | | | | |
| 2 | | | | |
| 3 | | | | |
| 4 | | | | |
| 5 | | | | |

## Precautions
- Confirm the LM35 pin configuration before applying power; incorrect connection may damage the sensor.
- Do not apply an analog voltage higher than the selected ADC reference voltage to A0.
- Keep the sensor and Arduino grounds common.
- Avoid touching or moving loose jumper wires while readings are being recorded.
- Use the same ADC reference assumption in the formula as is actually used by the Arduino.
- Allow a short settling time after warming the sensor before recording a stable value.

## Conclusion
The LM35 analog temperature sensor was interfaced with Arduino Uno. Its analog output was acquired using the inbuilt 10-bit ADC, converted into voltage and temperature, and displayed on the Serial Monitor. A 10-sample moving-average filter reduced short-term fluctuations and provided a more stable temperature reading.

## Viva Questions
1. What is the resolution of the ADC in Arduino Uno?
2. How many analog input channels are available on Arduino Uno?
3. What digital range is produced by a 10-bit ADC?
4. What is the approximate ADC step size when the reference voltage is 5 V?
5. What is the purpose of `analogRead()`?
6. What is the output sensitivity of the LM35 sensor?
7. How is LM35 output voltage converted into temperature in °C?
8. Why can successive ADC readings fluctuate even when temperature is nearly constant?
9. What is a moving-average filter?
10. Why are 10 readings averaged in this experiment?
11. What is the difference between a raw ADC reading and a filtered ADC reading?
12. What happens if the ADC reference voltage is changed?
13. Why must LM35 ground and Arduino ground be common?
14. Which ADC architecture is used in the ATmega328P?
15. How can the temperature measurement resolution be improved for a limited temperature range?
