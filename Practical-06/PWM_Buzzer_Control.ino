// Practical 06 - Part B: PWM drive demonstration for a low-current active buzzer
// Arduino Uno D6 -> buzzer positive (+); buzzer negative (-) -> GND.
// Direct connection is only for a low-current buzzer within GPIO limits.
// Use a transistor driver if the buzzer current is too high.
//
// NOTE: A passive piezo buzzer's pitch is controlled by frequency.
// For a passive piezo, use tone(BUZZER_PIN, frequency) instead.

const int BUZZER_PIN = 6;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // Demonstrate changing PWM duty values on a low-current active buzzer.
  analogWrite(BUZZER_PIN, 64);
  delay(1000);

  analogWrite(BUZZER_PIN, 128);
  delay(1000);

  analogWrite(BUZZER_PIN, 192);
  delay(1000);

  analogWrite(BUZZER_PIN, 255);
  delay(1000);

  analogWrite(BUZZER_PIN, 0);
  delay(1000);
}

/*
For a passive piezo buzzer, replace loop() with:
void loop() {
  tone(BUZZER_PIN, 1000); delay(500);
  tone(BUZZER_PIN, 1500); delay(500);
  noTone(BUZZER_PIN);     delay(500);
}
*/
