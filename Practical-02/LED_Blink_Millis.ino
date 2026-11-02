// Practical 02 - Part B: LED blink using non-blocking millis()
// Arduino Uno: LED anode via 220-330 ohm resistor to D8; cathode to GND
const int ledPin = 8;
const unsigned long interval = 1000;
unsigned long previousMillis = 0;
bool ledState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
  }
  // Other tasks can run here without waiting for a delay.
}
