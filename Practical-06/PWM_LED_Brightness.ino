// Practical 06 - Part A: LED brightness control using PWM
// Arduino Uno: D9 (PWM) -> 220-330 ohm resistor -> LED anode
// LED cathode -> GND

const int LED_PIN = 9;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Increase brightness from OFF to maximum.
  for (int value = 0; value <= 255; value += 5) {
    analogWrite(LED_PIN, value);
    delay(40);
  }

  // Decrease brightness from maximum to OFF.
  for (int value = 255; value >= 0; value -= 5) {
    analogWrite(LED_PIN, value);
    delay(40);
  }
}
