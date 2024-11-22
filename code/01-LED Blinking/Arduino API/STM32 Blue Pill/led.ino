/*
  STM32F103C8T6 (Blue Pill) LED Blinking

  This code demonstrates how to make an LED blink on and off at a 1-second interval using the digitalWrite() and delay() functions.

  The circuit:
  - LED attached from PB0 to ground

  Diagram:

      STM32         LED
     ---------     -----
    |         |   |     |
    |    PB0  |---|>|---+---- GND
    |         |   (Anode) (Cathode)
    |         |  
    |         |
  
  The LED's anode (longer leg) connects to PB0, and the cathode (shorter leg) connects to ground (GND).

  created 2024
  by Liang
*/

void setup() {
  // Set PB0 as an output pin, which will control the LED
  pinMode(PB0, OUTPUT);
}

void loop() {
  // Turn the LED on by setting PB0 to HIGH
  digitalWrite(PB0, HIGH);

  // Wait for 1 second (1000 milliseconds) while the LED is on
  delay(1000);

  // Turn the LED off by setting PB0 to LOW
  digitalWrite(PB0, LOW);

  // Wait for 1 second (1000 milliseconds) while the LED is off
  delay(1000);
}