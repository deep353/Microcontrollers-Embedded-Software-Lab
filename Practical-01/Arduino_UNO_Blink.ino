// Practical 01: Arduino Uno development environment test
// Board: Arduino Uno (ATmega328P)
// Built-in LED is normally connected to digital pin 13.

const int LED_PIN = LED_BUILTIN;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);  // LED ON
  delay(1000);

  digitalWrite(LED_PIN, LOW);   // LED OFF
  delay(1000);
}
