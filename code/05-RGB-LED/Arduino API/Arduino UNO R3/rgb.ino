/*
  RGB LED Control

  This code allows you to control the brightness of an RGB LED's red, green, and blue components using PWM.
  The RGB LED is connected to pins 9, 10, and 11 of the Arduino for red, green, and blue colors respectively.

  Circuit:
  - Red pin of RGB LED connected to pin 9 through a 220Ω resistor.
  - Green pin of RGB LED connected to pin 10 through a 220Ω resistor.
  - Blue pin of RGB LED connected to pin 11 through a 220Ω resistor.
  - Common cathode pin connected to GND.
    
  Diagram:

      Arduino       RGB LED
     ------------------------
    |   5V   | --> |  + (Cathode)   |
    |   GND  | --> |  GND (Common Cathode)  |
    |  Pin 9 | --> |  Red Anode     |
    |  Pin 10| --> |  Green Anode   |
    |  Pin 11| --> |  Blue Anode    |
     ------------------------------

  The common cathode pin of the RGB LED is connected to GND, and each color pin (red, green, and blue) is connected 
  to a corresponding PWM pin on the Arduino (pins 9, 10, 11) through a 220Ω current-limiting resistor.

  created 2024
  by Liang
*/

// Define pins for the RGB LED
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

void setup() {
  // Set RGB LED pins as output
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Display different colors by adjusting RGB values

  // Set the LED to red
  setColor(255, 0, 0);  // Red full brightness
  delay(1000);          // Wait for 1 second

  // Set the LED to green
  setColor(0, 255, 0);  // Green full brightness
  delay(1000);          // Wait for 1 second

  // Set the LED to blue
  setColor(0, 0, 255);  // Blue full brightness
  delay(1000);          // Wait for 1 second

  // Set the LED to yellow
  setColor(255, 255, 0);  // Red + Green = Yellow
  delay(1000);            // Wait for 1 second

  // Set the LED to cyan
  setColor(0, 255, 255);  // Green + Blue = Cyan
  delay(1000);            // Wait for 1 second

  // Set the LED to magenta
  setColor(255, 0, 255);  // Red + Blue = Magenta
  delay(1000);            // Wait for 1 second

  // Set the LED to white
  setColor(255, 255, 255);  // Red + Green + Blue = White
  delay(1000);              // Wait for 1 second

  // Turn off the LED (black)
  setColor(0, 0, 0);  // No color
  delay(1000);        // Wait for 1 second
}

// Function to set the color of the RGB LED using PWM
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);    // Set the red brightness
  analogWrite(greenPin, green);  // Set the green brightness
  analogWrite(bluePin, blue);   // Set the blue brightness
}