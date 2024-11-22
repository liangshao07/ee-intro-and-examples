/*
  LED Push Button with Debouncing

  This example demonstrates the use of a pushbutton to turn on and off an LED, with a debounce routine 
  to eliminate jitter caused by mechanical noise in the button.

  The circuit:
  - LED attached from pin 11 to ground
  - Pushbutton attached to pin 5 with internal pull-up enabled (using INPUT_PULLUP)

  When the button is pressed, the LED will turn on; when released, the LED will turn off.

  Diagram:

      Arduino         LED                   Pushbutton
     ---------       -----                --------------
    |         |     |     |              |              |
    |     11  |-----|>|---+---- GND      |     5        |
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

boolean pushButtonState = HIGH;    // Variable to store the current button state
boolean lastButtonState = HIGH;    // Variable to store the last button state
unsigned long lastDebounceTime = 0; // Variable to store the last time the button state changed
unsigned long debounceDelay = 50;   // Debounce delay time (50ms)

void setup() {
  // Set up pin modes for input and output
  pinMode(5, INPUT_PULLUP);  // Set pin 5 as input with internal pull-up resistor
  pinMode(11, OUTPUT);       // Set pin 11 as output for controlling the LED
}

void loop() {
  // Read the current state of the button
  int reading = digitalRead(5);

  // If the button state has changed, reset the debounce timer
  if (reading != lastButtonState) {
    lastDebounceTime = millis();  // Reset the debounce timer
  }

  // If the button state has been stable for longer than the debounce delay, register the button state
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // If the button state has changed (from HIGH to LOW or vice versa)
    if (reading != pushButtonState) {
      pushButtonState = reading;  // Update the current button state

      // Control the LED: if the button is pressed (LOW), turn on the LED, otherwise turn it off
      if (pushButtonState == LOW) {
        digitalWrite(11, HIGH);  // Turn on the LED
      } else {
        digitalWrite(11, LOW);   // Turn off the LED
      }
    }
  }

  // Save the current reading for the next iteration to detect state changes
  lastButtonState = reading;
}