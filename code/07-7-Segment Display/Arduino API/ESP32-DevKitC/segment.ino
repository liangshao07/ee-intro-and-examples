/*
  ESP32 7-Segment Display Digit Control

  This code controls a 7-segment display connected to an ESP32.
  It loops through the digits 0 to 9 and displays each digit for 1 second using individual pins for each segment.

  Circuit:
  - A common cathode 7-segment display is connected to GPIO 12-18 of the ESP32.
  - Each segment (a-g) is controlled by a specific pin.
  - 220Ω resistors are placed in series with each segment to limit the current.

  Diagram:

         ESP32         7-Segment Display
        --------       -----------------
       |        |     |   a            |
       |  GPIO12|-----|   o---/\/\/----| (220Ω resistor to segment a)
       |  GPIO13|-----|   o---/\/\/----| (220Ω resistor to segment b)
       |  GPIO14|-----|   o---/\/\/----| (220Ω resistor to segment c)
       |  GPIO15|-----|   o---/\/\/----| (220Ω resistor to segment d)
       |  GPIO16|-----|   o---/\/\/----| (220Ω resistor to segment e)
       |  GPIO17|-----|   o---/\/\/----| (220Ω resistor to segment f)
       |  GPIO18|-----|   o---/\/\/----| (220Ω resistor to segment g)
       |   GND  |-----| GND (Common Cathode) |
       |        |     --------------------

  created 2024
  by Liang
*/

// Define the pin mappings for each segment of the 7-segment display
const int segmentA = 12;
const int segmentB = 13;
const int segmentC = 14;
const int segmentD = 15;
const int segmentE = 16;
const int segmentF = 17;
const int segmentG = 18;

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