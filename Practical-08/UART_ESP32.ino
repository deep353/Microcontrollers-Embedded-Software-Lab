// Practical 08 - Part B: UART string receive and reply on ESP32
// External 3.3 V USB-UART adapter:
// Adapter TX -> ESP32 GPIO16 (RX2)
// Adapter RX -> ESP32 GPIO17 (TX2)
// Adapter GND -> ESP32 GND
//
// ESP32 onboard USB Serial Monitor: 115200 baud (debug output).
// External adapter terminal: 9600 baud, 8N1, Newline.
// The ESP32 UART driver buffers received data using hardware interrupts.

const int RX2_PIN = 16;
const int TX2_PIN = 17;
const byte MAX_MESSAGE_LENGTH = 64;

char receivedMessage[MAX_MESSAGE_LENGTH];
byte messageIndex = 0;

void setup() {
  Serial.begin(115200);  // Onboard USB serial for debug
  Serial2.begin(9600, SERIAL_8N1, RX2_PIN, TX2_PIN);

  Serial.println("ESP32 UART2 String Test");
  Serial.println("Send a message through the external UART adapter.");
}

void loop() {
  while (Serial2.available() > 0) {
    char incomingChar = (char)Serial2.read();

    if (incomingChar == '\n' || incomingChar == '\r') {
      if (messageIndex > 0) {
        receivedMessage[messageIndex] = '\0';

        Serial.print("ESP32 received: ");
        Serial.println(receivedMessage);

        Serial2.print("ESP32 TX: Received -> ");
        Serial2.println(receivedMessage);

        messageIndex = 0;
      }
    } else if (messageIndex < MAX_MESSAGE_LENGTH - 1) {
      receivedMessage[messageIndex++] = incomingChar;
    }
    // Extra characters beyond the buffer capacity are ignored.
  }
}
