// Practical 05: Timer1 periodic LED task with pushbutton and I2C LCD
// Board: Arduino Uno (ATmega328P)
// Onboard LED: D13 (PB5)
// Pushbutton: D7 to GND using INPUT_PULLUP
// I2C LCD: VCC->5V, GND->GND, SDA->A4, SCL->A5
// Install a compatible LiquidCrystal_I2C library.
// Change LCD_ADDRESS if your I2C scanner reports a different address.

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const byte LCD_ADDRESS = 0x27;
const byte BUTTON_PIN = 7;
const unsigned long DEBOUNCE_MS = 50;

LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);

volatile bool ledState = false;

int lastRawReading = HIGH;
int stableButtonState = HIGH;
unsigned long lastDebounceTime = 0;

ISR(TIMER1_COMPA_vect) {
  // D13 is PB5 on Arduino Uno. Toggle the output pin directly.
  PINB = _BV(PB5);
  ledState = !ledState;
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Timer1 Task");
  lcd.setCursor(0, 1);
  lcd.print("Button: RELEASED");

  // Configure Timer1 in CTC mode for approximately 1.5 seconds.
  noInterrupts();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  OCR1A = 23437;
  TCCR1B |= (1 << WGM12);              // CTC mode
  TCCR1B |= (1 << CS12) | (1 << CS10); // Prescaler 1024
  TIMSK1 |= (1 << OCIE1A);             // Enable compare-match A interrupt
  interrupts();
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);

  if (reading != lastRawReading) {
    lastDebounceTime = millis();
    lastRawReading = reading;
  }

  if ((millis() - lastDebounceTime) >= DEBOUNCE_MS) {
    if (reading != stableButtonState) {
      stableButtonState = reading;

      // Update LCD only when the debounced state changes.
      lcd.setCursor(0, 1);
      if (stableButtonState == LOW) {
        lcd.print("Button: PRESSED ");
      } else {
        lcd.print("Button: RELEASED");
      }
    }
  }
}
