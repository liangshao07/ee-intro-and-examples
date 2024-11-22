/*
  Serial Control of LED

  This code allows you to control an LED using serial communication.
  You can send commands via the serial monitor to turn the LED on or off.
  
  Circuit:
  - LED connected to pin 13 through a 220Ω resistor
  - Serial communication at 9600 baud rate

  Diagram:

      Arduino         LED
     ---------       -----
    |         |     |     |
    |     13  |-----|>|---+---- GND
    |         |     (Anode) (Cathode)
    |         |
  
  The LED's anode (longer leg) is connected to pin 13, and the cathode (shorter leg) is connected to ground (GND) through a 220Ω resistor.

  created 2024
  by Liang
*/

// Define the pin where the LED is connected
const int ledPin = 13;

void setup() {
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);

  // Initialize serial communication at a baud rate of 9600
  Serial.begin(9600);

  // Print a message to the serial monitor
  Serial.println("Enter 'on' to turn the LED on, 'off' to turn the LED off:");
}

void loop() {
  // Check if any data is available to read from the serial port
  if (Serial.available() > 0) {
    // Read the incoming data as a string
    String command = Serial.readStringUntil('\n');

    // Trim any whitespace characters (e.g., newlines)
    command.trim();

    // Check if the command is "on"
    if (command == "on") {
      // Turn the LED on
      digitalWrite(ledPin, HIGH);
      Serial.println("LED is ON");
    }
    // Check if the command is "off"
    else if (command == "off") {
      // Turn the LED off
      digitalWrite(ledPin, LOW);
      Serial.println("LED is OFF");
    } else {
      // If an unknown command is received, print an error message
      Serial.println("Invalid command. Enter 'on' or 'off'.");
    }
  }
}