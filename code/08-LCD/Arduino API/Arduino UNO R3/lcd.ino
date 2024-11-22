/*
  LCD I2C Example - 16x2 Display

  This example demonstrates how to control a 16x2 LCD using the I2C protocol with Arduino.
  It prints "Hello world!" on the first row and "LCD Tutorial" on the second row.

  Circuit:
  - An I2C LCD display is connected to the Arduino.

  Diagram:
  
      Arduino       I2C LCD
     ------------------------
    |  5V   | --> |   VCC    |
    |  GND  | --> |   GND    |
    |  A4   | --> |   SDA    |
    |  A5   | --> |   SCL    |
     ------------------------

  created 2024
  by Liang
*/

#include <LiquidCrystal_I2C.h>  // Include the LiquidCrystal_I2C library for controlling the LCD

// Initialize the LCD with address 0x20, 16 columns, and 2 rows
// The first parameter is the I2C address (0x20 in this case)
// The second and third parameters specify that it is a 16x2 LCD
LiquidCrystal_I2C lcd(0x20, 16, 2);

void setup()
{
  lcd.init();           // Initialize the LCD, setting it up for use
  lcd.clear();          // Clear the LCD screen to ensure it's empty
  lcd.backlight();      // Turn on the LCD backlight

  // Print a message on the first row of the LCD
  lcd.setCursor(2, 0);  // Set the cursor to column 2 of row 0 (first row)
  lcd.print("Hello world!");  // Print "Hello world!" on the first row
  
  // Print a message on the second row of the LCD
  lcd.setCursor(2, 1);  // Move the cursor to column 2 of row 1 (second row)
  lcd.print("LCD Tutorial");  // Print "LCD Tutorial" on the second row
}

void loop()
{
  // No operation needed in loop for this simple example
  // The messages on the LCD will remain static
}