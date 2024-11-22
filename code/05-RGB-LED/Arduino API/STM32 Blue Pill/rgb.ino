/*
  RGB LED Control for STM32F103C8T6 (Blue Pill)

  This code allows you to control the brightness of an RGB LED's red, green, and blue components using PWM.
  The RGB LED is connected to pins PA8, PA9, and PA10 of the STM32 for red, green, and blue colors respectively.

  Circuit:
  - Red pin of RGB LED connected to pin PA8 through a 220Ω resistor.
  - Green pin of RGB LED connected to pin PA9 through a 220Ω resistor.
  - Blue pin of RGB LED connected to pin PA10 through a 220Ω resistor.
  - Common cathode pin connected to GND.

  Diagram:

      STM32F103C8T6       RGB LED
     ------------------------------
    |   GND   | ------> | Cathode (Common) |
    |   PA8   | ------> | Red Anode        |
    |   PA9   | ------> | Green Anode      |
    |   PA10  | ------> | Blue Anode       |
     ------------------------------

  created 2024
  by Liang
*/

// Define pins for the RGB LED on STM32
const int redPin = PA8;  // Red pin connected to PA8
const int greenPin = PA9;  // Green pin connected to PA9
const int bluePin = PA10;  // Blue pin connected to PA10

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