// Practical 08 - Part A: UART string receive and reply on Arduino Uno
// Connect Uno to the computer using USB.
// Serial Monitor: 9600 baud, line ending = Newline.
// Serial uses USART0 (D0/RX and D1/TX) through the USB-to-serial bridge.
// The Arduino core receive interrupt fills the Serial receive ring buffer.

const byte MAX_MESSAGE_LENGTH = 64;
char receivedMessage[MAX_MESSAGE_LENGTH];
byte messageIndex = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Arduino Uno UART String Test");
  Serial.println("Type a message and press Send (Newline).");
}

void loop() {
  while (Serial.available() > 0) {
    char incomingChar = (char)Serial.read();

    if (incomingChar == '\n' || incomingChar == '\r') {
      if (messageIndex > 0) {
        receivedMessage[messageIndex] = '\0';

        Serial.print("UNO received: ");
        Serial.println(receivedMessage);

        Serial.print("UNO; Length: ");
        Serial.print(messageIndex);
        Serial.println("; UNO TX: Message acknowledged");

        messageIndex = 0;
      }
    } else if (messageIndex < MAX_MESSAGE_LENGTH - 1) {
      receivedMessage[messageIndex++] = incomingChar;
    }
    // Extra characters beyond the buffer capacity are ignored.
  }
}
