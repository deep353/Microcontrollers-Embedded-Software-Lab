// Practical 02 - Part A: LED blink using software delay
// Arduino Uno: LED anode via 220-330 ohm resistor to D13; cathode to GND
const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}
