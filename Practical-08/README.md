# Practical 08: Transmit and Receive a String Using UART with Interrupt-Based Reception

**Course:** Microcontrollers & Embedded Software Lab  
**Course Code:** ET24MDM309  
**Assignment:** 08

## Aim
To demonstrate full-duplex UART string transmission and interrupt-buffered reception using Arduino Uno and ESP32, with a separate implementation and procedure for each board.

## Problem Statement
Demonstrate UART string transmission and reception using Arduino Uno and ESP32. Received bytes are buffered by the platform UART driver using hardware receive interrupts and then processed as a complete string by the application.

## Apparatus
- Arduino Uno (ATmega328P, 5 V UART logic)
- ESP32 DevKit (ESP32-WROOM-32, 3.3 V UART logic)
- Computer with Arduino IDE 2.x and Serial Monitor
- USB cables suitable for each board
- 3.3 V TTL USB-to-UART adapter (CP2102/CH340/FT232 compatible) for ESP32 external UART
- Jumper wires

## Theory
UART (Universal Asynchronous Receiver/Transmitter) is a full-duplex asynchronous serial interface. Each character is transmitted as a frame containing a START bit, usually eight data bits, an optional parity bit, and one or more STOP bits. Both ends must use matching settings. This practical uses 9600 baud, 8 data bits, no parity and 1 stop bit (8N1). TX of one device connects to RX of the other, and both share a common ground.

On Arduino Uno, `Serial` uses USART0 on D0 (RX) and D1 (TX), connected to the onboard USB-to-serial interface. The Arduino core USART receive interrupt copies arriving bytes into a receive ring buffer. `Serial.available()` reports buffered bytes and `Serial.read()` removes them. The sketch therefore uses interrupt-buffered reception without writing a custom ISR.

On ESP32-WROOM-32, `Serial2` can use GPIO16 (RX2) and GPIO17 (TX2). The Arduino-ESP32 serial driver uses hardware interrupts and driver-managed buffers. The program checks `Serial2.available()` and reads buffered bytes. The onboard USB serial (`Serial`) is used separately for diagnostic output.

The sketches collect incoming characters until newline (`\n`) or carriage return (`\r`). A fixed-length character array limits the message to 63 characters plus the terminating null character.

## Part A: Arduino Uno

### Connections
The computer Serial Monitor communicates through the Uno's onboard USB-to-serial bridge and USART0 (D0/RX, D1/TX). No external jumper wires are required for this part. Keep D0 and D1 free of external devices during upload.

### Program
Open `UART_Arduino_Uno.ino`.

### Procedure
1. Connect Arduino Uno to the computer using USB.
2. Open Arduino IDE and select Arduino Uno and its COM port.
3. Open `UART_Arduino_Uno.ino`, verify and upload it. Do not connect external devices to D0/D1 during upload.
4. Open Serial Monitor and choose 9600 baud and **Newline** as the line ending.
5. Type `HELLO UNO` and click Send.
6. Observe the received string, its length and the acknowledgment.
7. Send other test strings (up to 63 characters).

### Expected output
Input: `HELLO UNO`

The Serial Monitor displays the received message and a reply similar to:
- `UNO received: HELLO UNO`
- `UNO; Length: 9; UNO TX: Message acknowledged`

## Part B: ESP32

### Connections
Use a 3.3 V TTL USB-to-UART adapter for the external UART terminal.

| USB-to-UART adapter | ESP32 DevKit |
|---|---|
| TX | GPIO16 (RX2) |
| RX | GPIO17 (TX2) |
| GND | GND |

The ESP32 built-in USB port connects to the computer for programming and debug Serial Monitor. Do not connect a 5 V logic-level adapter to ESP32 GPIOs. Do not connect an RS-232 voltage-level port directly.

### Program
Open `UART_ESP32.ino`.

### Procedure
1. Connect ESP32 through its normal USB cable. Select ESP32 Dev Module (or the exact board) and the correct COM port in Arduino IDE.
2. With power disconnected, connect the external 3.3 V USB-UART adapter: TX to GPIO16, RX to GPIO17 and GND to GND.
3. Verify and upload `UART_ESP32.ino`.
4. Open the ESP32 onboard-port Serial Monitor at 115200 baud.
5. Open a second serial terminal for the external USB-UART adapter at 9600 baud, 8N1, with newline as the line ending. A second terminal application may be necessary because Arduino IDE Serial Monitor commonly uses one port per window.
6. Enter `HELLO ESP32` in the external terminal.
7. Confirm that the acknowledgment appears in the external terminal and the received text appears on the ESP32 debug terminal.
8. Repeat with other strings and compare the transmitted and received characters.

### Expected output
External adapter terminal input: `HELLO ESP32`

- External terminal: `ESP32 TX: Received -> HELLO ESP32`
- ESP32 onboard debug terminal: `ESP32 received: HELLO ESP32`

## Precautions
- TX and RX wires must be crossed, and the devices must share GND.
- ESP32 GPIO inputs are 3.3 V only; a 5 V UART source requires suitable level shifting.
- Use matching baud rate and 8N1 framing at both ends.
- Arduino Uno pins D0/D1 share the USB serial channel and should remain free during upload.
- The software reads bytes from an interrupt-filled ring buffer; `Serial.available()` is not itself an interrupt service routine.
- Do not connect an RS-232 voltage-level port directly to either board.

## Conclusion
String transmission and reception using UART were demonstrated on Arduino Uno USART0 and ESP32 UART2. Received bytes were collected by the platform UART driver using interrupt-based buffering and processed into complete strings by the application.

## Viva Questions
1. What is UART, and why is it called asynchronous?
2. What is the meaning of 9600 baud and 8N1?
3. Why must UART TX and RX pins be cross-connected?
4. What is the difference between UART hardware receive interrupts and `Serial.available()`?
5. Which pins implement UART0 on Arduino Uno?
6. Why is a second UART (UART2) useful on ESP32?
7. What is a receive ring buffer?
8. Why should an ESP32 not receive 5 V UART logic directly?
9. What happens if UART baud rates differ?
10. Why do the examples terminate a string at newline?
