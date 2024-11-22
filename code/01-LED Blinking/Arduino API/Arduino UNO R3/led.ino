/*
  LED Blinking

  This code demonstrates how to make an LED blink on and off at a 1-second interval using the digitalWrite() and delay() functions.

  The circuit:
  - LED attached from pin 11 to ground

  Diagram:

      Arduino         LED
     ---------       -----
    |         |     |     |
    |     13  |-----|>|---+---- GND
    |         |     (Anode) (Cathode)
    |         |  
    |         |
  
  The LED's anode (longer leg) connects to pin 11, and the cathode (shorter leg) connects to ground (GND).

  created 2024
  by Liang
*/

void setup() {
  // Set pin 11 as an output pin, which will control the LED
  pinMode(13, OUTPUT);
}

void loop() {
  // Turn the LED on by setting pin 11 to HIGH
  digitalWrite(13, HIGH);

  // Wait for 1 second (1000 milliseconds) while the LED is on
  delay(1000);

  // Turn the LED off by setting pin 11 to LOW
  digitalWrite(13, LOW);

  // Wait for 1 second (1000 milliseconds) while the LED is off
  delay(1000);
}