/*
  ESP32 LED Blinking

  This code demonstrates how to make an LED blink on and off at a 1-second interval using the digitalWrite() and delay() functions.

  The circuit:
  - LED attached from GPIO 13 to ground

  Diagram:

      ESP32         LED
     ---------     -----
    |         |   |     |
    |   GPIO13|---|>|---+---- GND
    |         |   (Anode) (Cathode)
    |         |  
    |         |
  
  The LED's anode (longer leg) connects to GPIO 13, and the cathode (shorter leg) connects to ground (GND).

  created 2024
  by Liang
*/

void setup() {
  // Set GPIO 13 as an output pin, which will control the LED
  pinMode(13, OUTPUT);
}

void loop() {
  // Turn the LED on by setting GPIO 13 to HIGH
  digitalWrite(13, HIGH);

  // Wait for 1 second (1000 milliseconds) while the LED is on
  delay(1000);

  // Turn the LED off by setting GPIO 13 to LOW
  digitalWrite(13, LOW);

  // Wait for 1 second (1000 milliseconds) while the LED is off
  delay(1000);
}