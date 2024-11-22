/*
  STM32F103C8T6 (Blue Pill) 7-Segment Display Digit Control

  This code controls a 7-segment display connected to an STM32.
  It loops through the digits 0 to 9 and displays each digit for 1 second using individual pins for each segment.

  Circuit:
  - A common cathode 7-segment display is connected to PA0-PA6 of the STM32.
  - Each segment (a-g) is controlled by a specific pin.
  - 220Ω resistors are placed in series with each segment to limit the current.

  Diagram:

         STM32         7-Segment Display
        --------       -----------------
       |        |     |   a            |
       |   PA0  |-----|   o---/\/\/----| (220Ω resistor to segment a)
       |   PA1  |-----|   o---/\/\/----| (220Ω resistor to segment b)
       |   PA2  |-----|   o---/\/\/----| (220Ω resistor to segment c)
       |   PA3  |-----|   o---/\/\/----| (220Ω resistor to segment d)
       |   PA4  |-----|   o---/\/\/----| (220Ω resistor to segment e)
       |   PA5  |-----|   o---/\/\/----| (220Ω resistor to segment f)
       |   PA6  |-----|   o---/\/\/----| (220Ω resistor to segment g)
       |   GND  |-----| GND (Common Cathode) |
       |        |     --------------------
  
  The LED segments are connected to PA0-PA6, and the common cathode is connected to GND.

  created 2024
  by Liang
*/

// Define the pin mappings for each segment of the 7-segment display
const int segmentA = PA0;
const int segmentB = PA1;
const int segmentC = PA2;
const int segmentD = PA3;
const int segmentE = PA4;
const int segmentF = PA5;
const int segmentG = PA6;

void setup() {
  // Initialize all segment pins as output to control the display
  pinMode(segmentA, OUTPUT);
  pinMode(segmentB, OUTPUT);
  pinMode(segmentC, OUTPUT);
  pinMode(segmentD, OUTPUT);
  pinMode(segmentE, OUTPUT);
  pinMode(segmentF, OUTPUT);
  pinMode(segmentG, OUTPUT);
}

// Function to turn off all segments (clearing the display before showing a new digit)
void clearDisplay() {
  digitalWrite(segmentA, LOW);
  digitalWrite(segmentB, LOW);
  digitalWrite(segmentC, LOW);
  digitalWrite(segmentD, LOW);
  digitalWrite(segmentE, LOW);
  digitalWrite(segmentF, LOW);
  digitalWrite(segmentG, LOW);
}

// Function to display a specific digit on the 7-segment display
void displayDigit(int digit) {
  clearDisplay();  // Clear the display to avoid leftover segments from previous digit

  // Determine which segments to light up for the specified digit
  switch (digit) {
    case 0:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, HIGH);
      break;
    case 1:
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      break;
    case 2:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
    case 3:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
    case 4:
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
    case 5:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
    case 6:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
    case 7:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      break;
    case 8:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
    case 9:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
  }
}

void loop() {
  // Loop through digits 0 to 9 and display each for 1 second
  for (int i = 0; i <= 9; i++) {
    displayDigit(i);
    delay(1000);  // Wait for 1 second before moving to the next digit
  }
}