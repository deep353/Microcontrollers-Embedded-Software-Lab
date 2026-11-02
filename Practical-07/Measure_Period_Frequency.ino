// Practical 07: Measure period and frequency of an external square wave
// Board: Arduino Uno
// Function generator signal OUT -> 1 kOhm series resistor -> D2
// Function generator GND -> Arduino GND
// Use a 0-5 V digital-compatible square wave only.

const byte SIGNAL_PIN = 2;
const unsigned long PULSE_TIMEOUT_US = 1000000UL;

void setup() {
  pinMode(SIGNAL_PIN, INPUT);
  Serial.begin(9600);
  Serial.println("External Signal Period and Frequency Measurement");
}

void loop() {
  unsigned long highTime = pulseIn(SIGNAL_PIN, HIGH, PULSE_TIMEOUT_US);
  unsigned long lowTime  = pulseIn(SIGNAL_PIN, LOW, PULSE_TIMEOUT_US);

  // A zero duration means pulseIn timed out or no complete pulse was detected.
  if (highTime > 0 && lowTime > 0) {
    unsigned long period = highTime + lowTime;
    float frequency = 1000000.0 / (float)period;

    Serial.print("Period: ");
    Serial.print(period);
    Serial.print(" us  Frequency: ");
    Serial.print(frequency, 2);
    Serial.println(" Hz");
  } else {
    Serial.println("No valid signal detected. Check generator, wiring and voltage.");
  }

  delay(500);
}
