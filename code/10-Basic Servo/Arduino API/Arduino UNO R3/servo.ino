/*
  Serial Control of Servo Motor

  This code allows you to control a servo motor using serial communication.
  You can send an angle (0-180) via the serial monitor to set the position of the servo motor.
  
  Circuit:
  - Servo motor signal wire connected to pin 9
  - Servo power connected to 5V and ground (or external power if needed)
  - Serial communication at 9600 baud rate

  Diagram:

      Arduino          Servo Motor
     ---------        -------------
    |         |       |           |
    |     9   |-------| Signal     |
    |         |       |           |
    |    5V   |-------| VCC        |
    |   GND   |-------| GND        |
    |         |       |           |
  
  The servo's signal wire is connected to pin 9, the VCC wire is connected to 5V, and the ground wire is connected to GND.
  If the servo requires more power than the Arduino can provide, use an external power source.

  created 2024
  by Liang
*/

Servo myServo;  // Create a servo object to represent and control a servo motor

const int servoPin = 9;  // Define the pin where the servo signal wire is connected

void setup() {
  // Attach the servo object to the defined PWM pin (pin 9)
  myServo.attach(servoPin);

  // Start serial communication at 9600 baud rate to send and receive data via the serial monitor
  Serial.begin(9600);

  // Print an initial message to the serial monitor, instructing the user how to control the servo
  Serial.println("Enter a value between 0 and 180 to set the servo angle:");
}

void loop() {
  // Check if there is any incoming data available in the serial input buffer
  if (Serial.available() > 0) {
    // Read the incoming serial data and convert it into an integer (angle)
    int angle = Serial.parseInt();

    // Ensure the angle is within the valid range (0 to 180 degrees)
    if (angle >= 0 && angle <= 180) {
      // Move the servo to the specified angle
      myServo.write(angle);

      // Provide feedback to the user via the serial monitor, confirming the servo angle
      Serial.print("Servo angle set to: ");
      Serial.println(angle);
    } else {
      // If the angle is out of range, print an error message to the serial monitor
      Serial.println("Invalid angle. Please enter a value between 0 and 180.");
    }
  }
}