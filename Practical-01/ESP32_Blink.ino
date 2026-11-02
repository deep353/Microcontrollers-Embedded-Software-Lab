// Practical 01: ESP32 development environment test
// Target: Common ESP32 DevKit V1 (ESP32-WROOM-32)
// GPIO 2 is common for the onboard LED, but the LED pin varies by board.
// Change LED_PIN to match your board if required.

const int LED_PIN = 2;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);  // LED ON
  delay(1000);

  digitalWrite(LED_PIN, LOW);   // LED OFF
  delay(1000);
}
