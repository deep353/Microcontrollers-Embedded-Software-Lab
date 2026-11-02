// Practical 06 - Part C: DC motor speed control using L293D
// Arduino Uno D9 (PWM) -> L293D EN1 (pin 1)
// Arduino Uno D8 -> L293D IN1 (pin 2)
// Arduino Uno D7 -> L293D IN2 (pin 7)
// Motor -> L293D OUT1 (pin 3) and OUT2 (pin 6)
// L293D Vcc1 pin 16 -> Arduino 5V
// L293D Vcc2 pin 8 -> external motor supply positive (within ratings)
// L293D GND pins 4,5,12,13 -> common GND
// Arduino GND and motor supply negative must be connected together.
// Never connect a motor directly to an Arduino GPIO pin.

const int ENABLE_PIN = 9;  // PWM
const int IN1_PIN = 8;
const int IN2_PIN = 7;

void setup() {
  pinMode(ENABLE_PIN, OUTPUT);
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);

  // Select one fixed direction.
  digitalWrite(IN1_PIN, HIGH);
  digitalWrite(IN2_PIN, LOW);
}

void loop() {
  analogWrite(ENABLE_PIN, 80);
  delay(3000);

  analogWrite(ENABLE_PIN, 150);
  delay(3000);

  analogWrite(ENABLE_PIN, 255);
  delay(3000);

  analogWrite(ENABLE_PIN, 0);  // Stop motor
  delay(3000);
}
