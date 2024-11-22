/*
  LED Push Button

  This example demonstrates the use of a pushbutton to turn on and off an LED using the digitalRead() function.
  
  The circuit:
  - LED attached from pin 11 to ground
  - Pushbutton attached to pin 5 with internal pull-up enabled (using INPUT_PULLUP)
  
  When the button is pressed, the LED will turn on; when released, the LED will turn off.

  Diagram:

      Arduino         LED                   Pushbutton
     ---------       -----                --------------
    |         |     |     |              |              |
    |     13  |-----|>|---+---- GND      |     5        |
    |         |     (Anode) (Cathode)    |    (Pin)     |
    |         |                          |              |
    |         |                          |---+    +-----|
    |         |                          |   |    |     |
    |     5   |--------------------------+   |    |     |
    |         |   (Internal Pull-up)      GND +    +  VCC

  The LED's anode (longer leg) connects to pin 11, and the cathode (shorter leg) connects to ground (GND).
  The pushbutton is connected to pin 5 and GND, with the internal pull-up resistor activated in the code.

  created 2024
  by Liang
*/

boolean pushButton;  // Variable to store the button state (pressed or not)

void setup() {
  // Set up pin modes for input and output

  pinMode(5, INPUT_PULLUP);  // Set pin 5 as input with internal pull-up resistor
  // The pull-up resistor ensures the pin is HIGH when the button is not pressed and LOW when pressed.

  pinMode(13, OUTPUT);  // Set pin 11 as output for controlling the LED
}

void loop() {
  // Main code to run repeatedly

  pushButton = digitalRead(5);  // Read the current state of the button (HIGH or LOW)

  if (pushButton == LOW) {  // If the button is pressed (LOW state)
    digitalWrite(13, HIGH);  // Turn on the LED (HIGH output on pin 11)
  } else {  // If the button is not pressed (HIGH state)
    digitalWrite(13, LOW);   // Turn off the LED (LOW output on pin 11)
  }
}