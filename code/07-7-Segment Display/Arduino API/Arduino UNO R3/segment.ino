/*
  7-Segment Display Digit Control

  This code controls a 7-segment display connected to an Arduino.
  It loops through the digits 0 to 9 and displays each digit for 1 second using individual pins for each segment.

  Circuit:
  - A common cathode 7-segment display is connected to pins 2-8 of the Arduino.
  - Each segment (a-g) is controlled by a specific pin.
  - 220Ω resistors are placed in series with each segment to limit the current.

  Diagram:

         Arduino        7-Segment Display
        --------        -----------------
       |        |      |   a            |
       |     2  |------|   o---/\/\/----| (220Ω resistor to segment a)
       |     3  |------|   o---/\/\/----| (220Ω resistor to segment b)
       |     4  |------|   o---/\/\/----| (220Ω resistor to segment c)
       |     5  |------|   o---/\/\/----| (220Ω resistor to segment d)
       |     6  |------|   o---/\/\/----| (220Ω resistor to segment e)
       |     7  |------|   o---/\/\/----| (220Ω resistor to segment f)
       |     8  |------|   o---/\/\/----| (220Ω resistor to segment g)
       |        |      |                |
       |   GND  |------| GND (Common Cathode) |
       |        |      --------------------
       |        |
  
  created 2024
  by Liang
*/

// Define the pin mappings for each segment of the 7-segment display
const int segmentA = 2;
const int segmentB = 3;
const int segmentC = 4;
const int segmentD = 5;
const int segmentE = 6;
const int segmentF = 7;
const int segmentG = 8;

void setup() {
  // Initialize all segment pins as output so they can control the display
  pinMode(segmentA, OUTPUT);  // Set pin for segment A as output
  pinMode(segmentB, OUTPUT);  // Set pin for segment B as output
  pinMode(segmentC, OUTPUT);  // Set pin for segment C as output
  pinMode(segmentD, OUTPUT);  // Set pin for segment D as output
  pinMode(segmentE, OUTPUT);  // Set pin for segment E as output
  pinMode(segmentF, OUTPUT);  // Set pin for segment F as output
  pinMode(segmentG, OUTPUT);  // Set pin for segment G as output
}

// Function to turn off all segments (clearing the display before showing a new digit)
void clearDisplay() {
  digitalWrite(segmentA, LOW);  // Turn off segment A
  digitalWrite(segmentB, LOW);  // Turn off segment B
  digitalWrite(segmentC, LOW);  // Turn off segment C
  digitalWrite(segmentD, LOW);  // Turn off segment D
  digitalWrite(segmentE, LOW);  // Turn off segment E
  digitalWrite(segmentF, LOW);  // Turn off segment F
  digitalWrite(segmentG, LOW);  // Turn off segment G
}

// Function to display a specific digit on the 7-segment display
void displayDigit(int digit) {
  clearDisplay();  // Clear the display to avoid leftover segments from previous digit

  // Determine which segments to light up for the specified digit
  switch (digit) {
    case 0:
      // Display '0' by lighting up segments a, b, c, d, e, f
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, LOW);  // Segment g off
      break;
    case 1:
      // Display '1' by lighting up segments b, c
      digitalWrite(segmentA, LOW);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, LOW);
      break;
    case 2:
      // Display '2' by lighting up segments a, b, d, e, g
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, LOW);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, HIGH);
      break;
    case 3:
      // Display '3' by lighting up segments a, b, c, d, g
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, HIGH);
      break;
    case 4:
      // Display '4' by lighting up segments b, c, f, g
      digitalWrite(segmentA, LOW);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
    case 5:
      // Display '5' by lighting up segments a, c, d, f, g
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, LOW);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
    case 6:
      // Display '6' by lighting up segments a, c, d, e, f, g
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, LOW);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
    case 7:
      // Display '7' by lighting up segments a, b, c
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, LOW);
      break;
    case 8:
      // Display '8' by lighting up all segments a, b, c, d, e, f, g
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
    case 9:
      // Display '9' by lighting up segments a, b, c, d, f, g
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
  }
}

void loop() {
  // Loop through digits 0 to 9 and display each for 1 second

  for (int i = 0; i <= 9; i++) {
    displayDigit(i);  // Display the current digit
    delay(1000);      // Wait for 1 second before moving to the next digit
  }
}