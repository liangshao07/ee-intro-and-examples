/*
  LED Brightness Control

  This code gradually increases and decreases the brightness of an LED connected to pin 11 using PWM (Pulse Width Modulation).
  It also outputs the brightness values to the Serial Monitor for debugging or monitoring purposes.

  The circuit:
  - LED connected to pin 11 (PWM-capable pin) through a 220Ω resistor.
  - The cathode (shorter leg) of the LED connected to GND.
  - Serial monitor used for outputting brightness values.

  Diagram:
  
      Arduino         LED
     -----------     -----
    |           |   |     |
    |     13  --|---|>|---+---- GND
    | (PWM Pin) |   (Anode) (Cathode)
    |           |
    
  The anode (longer leg) of the LED is connected to pin 11 (PWM-capable) through a 220Ω resistor.
  The cathode (shorter leg) of the LED is connected to GND.

  created 2024
  by Liang
*/

void setup() {
  // Initialize pin 11 as an output pin to control the LED
  pinMode(13, OUTPUT);  
}

void loop() {
  // Start serial communication at a baud rate of 9600
  Serial.begin(9600);  

  // Gradually increase brightness from 0 to 255 (LED gets brighter)
  for (int brightness = 0; brightness <= 255; brightness++) {
    // Set the brightness of the LED using PWM on pin 11
    analogWrite(13, brightness);  

    // Output the current brightness value to the Serial Monitor
    Serial.println(brightness);   

    // Wait for 10 milliseconds before updating the brightness again
    delay(10);                    
  }

  // Gradually decrease brightness from 255 to 0 (LED gets dimmer)
  for (int brightness = 255; brightness >= 0; brightness--) {
    // Set the brightness of the LED using PWM on pin 11
    analogWrite(13, brightness);  

    // Output the current brightness value to the Serial Monitor
    Serial.println(brightness);   

    // Wait for 10 milliseconds before updating the brightness again
    delay(10);                    
  }
}