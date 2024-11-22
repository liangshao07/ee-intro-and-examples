// Serial Control of LED
// This code enables you to control an LED via serial communication with ESP32-DevKitC.
// You can send commands through the serial monitor to switch the LED on or off.

// Circuit Description:
// - The LED is connected to pin 13 of ESP32-DevKitC through a 220Ω resistor.
// - The serial communication is set to a baud rate of 9600.

// Diagram Illustration:
// 
//      ESP32-DevKitC         LED
//     --------------        -----
//    |              |      |     |
//    |      13      |------|>|---+---- GND
//    |              |      (Anode) (Cathode)
//    |              |
// 
// The anode (the longer leg) of the LED is connected to pin 13, and the cathode (the shorter leg) is connected to the ground (GND) through a 220Ω resistor.

// Created in 2024
// By Liang

// Include the necessary header files for using the Arduino framework with ESP32-DevKitC.

// Define the pin number where the LED is connected. In this case, it's pin 13.
const int ledPin = 13;

void setup() {
    // Initialize the LED pin as an output. This allows us to control the voltage level on this pin to turn the LED on or off.
    pinMode(ledPin, OUTPUT);

    // Initialize the serial communication with a baud rate of 9600. This enables communication with external devices (like a computer's serial monitor).
    Serial.begin(9600);

    // Print a prompt message to the serial monitor to inform the user about the valid commands for controlling the LED.
    Serial.println("Enter 'on' to turn the LED on, 'off' to turn the LED off:");
}

void loop() {
    // Check if there is any data available to be read from the serial port. If data is available, it means a command has been sent from the serial monitor.
    if (Serial.available() > 0) {
        // Read the incoming data as a string until a newline character ('\n') is encountered. This reads the complete command entered by the user.
        String command = Serial.readStringUntil('\n');

        // Trim any whitespace characters (such as spaces or newlines) from the beginning and end of the command string to clean up the input.
        command.trim();

        // Check if the command entered by the user is "on". If it is, we'll turn on the LED.
        if (command == "on") {
            // Set the LED pin to HIGH (which provides voltage to the LED) to turn it on.
            digitalWrite(ledPin, HIGH);
            Serial.println("LED is ON");
        }
        // Check if the command is "off". If so, we'll turn off the LED.
        else if (command == "off") {
            // Set the LED pin to LOW (which removes voltage from the LED) to turn it off.
            digitalWrite(ledPin, LOW);
            Serial.println("LED is OFF");
        }
        else {
            // If the command received is neither "on" nor "off", it's considered an invalid command. So, print an error message to the serial monitor.
            Serial.println("Invalid command. Enter 'on' or 'off'.");
        }
    }
}