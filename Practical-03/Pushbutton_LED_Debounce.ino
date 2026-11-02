// Practical 03: Pushbutton and LED control with delay-based debouncing
// Board: Arduino Uno
// Pushbutton: digital pin 7 to GND
// LED: digital pin 8 through a 220-330 ohm resistor to GND
// INPUT_PULLUP means released = HIGH and pressed = LOW.

const int BUTTON_PIN = 7;
const int LED_PIN = 8;
const unsigned long DEBOUNCE_DELAY = 50;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW) {
    // Wait for possible contact bounce to settle.
    delay(DEBOUNCE_DELAY);

    // Confirm that the button is still pressed.
    if (digitalRead(BUTTON_PIN) == LOW) {
      digitalWrite(LED_PIN, HIGH);
    }
  } else {
    // Button released.
    digitalWrite(LED_PIN, LOW);
  }
}
