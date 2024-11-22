// Serial Control of LED
// This code enables you to control an LED through serial communication.
// You can send commands via the serial monitor to turn the LED on or off.

// Circuit:
// - The LED is connected to pin 13 through a 220Ω resistor.
// - Serial communication is set at a baud rate of 9600.

// Diagram:
// 
//      STM32 Blue Pill         LED
//     -----------------       -----
//    |                 |     |     |
//    |         13      |-----|>|---+---- GND
//    |                 |     (Anode) (Cathode)
//    |                 |
// 
// The anode (the longer leg) of the LED is connected to pin 13, and the cathode (the shorter leg) is connected to the ground (GND) through a 220Ω resistor.

// Created in 2024
// By Liang

// Include the necessary Arduino framework header file. For STM32 Blue Pill development, it's compatible with the Arduino framework.

// Define the pin to which the LED is connected. Here it's pin 13.
const int ledPin = 13;

void setup() {
    // Initialize the LED pin as an output mode, which is used to control the on/off state of the LED.
    pinMode(ledPin, OUTPUT);

    // Initialize serial communication with a baud rate of 9600, so that it can receive and send serial data.
    Serial.begin(9600);

    // Print a message to the serial monitor to inform the user how to operate.
    Serial.println("Enter 'on' to turn the LED on, 'off' to turn the LED off:");
}

void loop() {
    // Check if there is any data available to be read from the serial port. That is, check if any characters have been received from the serial port.
    if (Serial.available() > 0) {
        // Read the incoming data as a string until a newline character '\n' is encountered.
        String command = Serial.readStringUntil('\n');

        // Trim any white space characters (such as newline characters, etc.) at both ends of the string to standardize the command.
        command.trim();

        // Check if the received command is "on". If so, perform the operation to turn on the LED.
        if (command == "on") {
            // Set the LED pin to high level to turn on the LED.
            digitalWrite(ledPin, HIGH);
            Serial.println("LED is ON");
        }
        // Check if the received command is "off". If so, perform the operation to turn off the LED.
        else if (command == "off") {
            // Set the LED pin to low level to turn off the LED.
            digitalWrite(ledPin, LOW);
            Serial.println("LED is OFF");
        }
        else {
            // If the received command is neither "on" nor "off", it's considered an invalid command. Send an error message to the serial port.
            Serial.println("Invalid command. Enter 'on' or 'off'.");
        }
    }
}