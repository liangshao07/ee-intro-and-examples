/*
  Serial Control of Servo Motor using ESP32-DevKitC and ESPServo Library

  This code allows you to control a servo motor using serial communication with the ESP32-DevKitC board.
  You can send an angle (ranging from 0 to 180) via the serial monitor to set the position of the servo motor.

  Circuit:
  - The servo motor's signal wire is connected to pin 18 of the ESP32-DevKitC. (The pin can be adjusted based on your specific hardware setup. Here, pin 18 is used as an example.)
  - The servo's power can be connected to 5V (if the power requirements are within the capacity of the ESP32's power supply) or an external power source if more power is needed. The ground wire is connected to the GND pin of the ESP32-DevKitC.
  - Serial communication is set at a baud rate of 9600.

  Diagram:

      ESP32-DevKitC          Servo Motor
     --------------        -------------
    |              |       |           |
    |     18       |-------| Signal     |
    |              |       |           |
    |    5V (or external power) | VCC        |
    |   GND        |-------| GND        |
    |              |       |           |

  The servo's signal wire is connected to pin 18, the power supply is connected as described above, and the ground wire is connected to GND. If the servo demands more power than what the ESP32 can supply, an external power source should be used.

  created 2024
  by Liang
*/

#include <ESP32Servo.h>  // Include the ESPServo library for controlling servo motors with ESP32

const int servoPin = 18;  // Define the pin where the servo motor's signal wire is connected. Here, we use pin 18.

Servo servo;  // Create a Servo object to represent and control the servo motor

void setup() {
    // Attach the servo object to the specified pin (pin 18 in this case).
    // The additional parameters 500 and 2400 are the minimum and maximum pulse widths (in microseconds) respectively.
    // These values might need to be adjusted depending on the specific servo motor you are using.
    servo.attach(servoPin, 500, 2400);

    // Initialize the serial communication with a baud rate of 9600. This enables sending and receiving data through the serial monitor.
    Serial.begin(9600);

    Serial.println("Enter a value between 0 and 180 to set the servo angle:");
}

void loop() {
    // Check if there is any incoming data available in the serial input buffer.
    if (Serial.available() > 0) {
        // Read the incoming serial data and convert it into an integer representing the angle.
        int angle = Serial.parseInt();

        // Ensure the angle is within the valid range (from 0 to 180 degrees).
        if (angle >= 0 && angle <= 180) {
            // Move the servo to the specified angle.
            servo.write(angle);

            // Provide feedback to the user via the serial monitor, confirming the servo angle that has been set.
            Serial.print("Servo angle set to: ");
            Serial.println(angle);
        }
        else {
            // If the angle is out of range, print an error message to the serial monitor.
            Serial.println("Invalid angle. Please enter a value between 0 and 180.");
        }
    }
}