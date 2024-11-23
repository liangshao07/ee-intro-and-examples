/*
  LCD I2C Example - 16x2 Display for STM32F103C8T6 (Blue Pill)

  This example demonstrates how to control a 16x2 LCD using the I2C protocol with STM32F103C8T6.
  It prints "Hello world!" on the first row and "LCD Tutorial" on the second row.

  Circuit:
  - An I2C LCD display is connected to the STM32F103C8T6.

  Diagram:
  
      STM32F103C8T6      I2C LCD
     ------------------------------
    |  5V   | ------> |   VCC    |
    |  GND  | ------> |   GND    |
    |  PB7  | ------> |   SDA    |
    |  PB6  | ------> |   SCL    |
     -----------------------------

  created 2024
  by Liang
*/

#include <Wire.h>               // Include Wire library for I2C
#include <LiquidCrystal_I2C.h>   // Include the LiquidCrystal_I2C library for controlling the LCD

// Initialize the LCD with the I2C address (0x20), 16 columns, and 2 rows
LiquidCrystal_I2C lcd(0x20, 16, 2);

void setup() {
  lcd.init();           // Initialize the LCD
  lcd.clear();          // Clear the LCD screen
  lcd.backlight();      // Turn on the LCD backlight

  // Print a message on the first row of the LCD
  lcd.setCursor(2, 0);  // Set cursor to column 2 of row 0 (first row)
  lcd.print("Hello world!");  // Print "Hello world!" on the first row

  // Print a message on the second row of the LCD
  lcd.setCursor(2, 1);  // Move cursor to column 2 of row 1 (second row)
  lcd.print("LCD Tutorial");  // Print "LCD Tutorial" on the second row
}

void loop() {
  // No operation needed in loop for this example
}