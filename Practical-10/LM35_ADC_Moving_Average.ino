// Practical 10: Read LM35 analog temperature data using ADC
// and display a 10-sample moving-average filtered output.
// Board: Arduino Uno
// LM35: VCC -> 5V, VOUT -> A0, GND -> GND
//
// Check the exact LM35 package pinout from its datasheet before wiring.

const int SENSOR_PIN = A0;
const int NUMBER_OF_SAMPLES = 10;
const float ADC_REFERENCE_VOLTAGE = 5.0;
const float ADC_MAX_COUNT = 1023.0;
const float LM35_MV_PER_DEGREE_C = 10.0;

void setup() {
  Serial.begin(9600);
  Serial.println("LM35 ADC and Moving Average Filter");
}

void loop() {
  unsigned long total = 0;
  int rawADC = 0;

  // Read 10 consecutive ADC samples.
  for (int i = 0; i < NUMBER_OF_SAMPLES; i++) {
    rawADC = analogRead(SENSOR_PIN);
    total += rawADC;
    delay(10);
  }

  // Average the samples to reduce short-term fluctuations.
  float filteredADC = total / (float)NUMBER_OF_SAMPLES;

  // Convert filtered ADC value to voltage.
  float voltage = filteredADC * ADC_REFERENCE_VOLTAGE / ADC_MAX_COUNT;

  // LM35 sensitivity is 10 mV per degree Celsius.
  float temperatureC = voltage * 100.0;

  Serial.print("Raw ADC = ");
  Serial.print(rawADC);
  Serial.print("   Filtered ADC = ");
  Serial.print(filteredADC, 2);
  Serial.print("   Voltage = ");
  Serial.print(voltage, 3);
  Serial.print(" V   Temperature = ");
  Serial.print(temperatureC, 2);
  Serial.println(" C");

  delay(500);
}
