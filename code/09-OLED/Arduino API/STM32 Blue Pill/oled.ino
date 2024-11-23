/*
  OLED Display Control with STM32F103C8T6 Blue Pill

  This code demonstrates how to control a 4-pin SSD1306 OLED display using an STM32F103C8T6 Blue Pill board with the Arduino framework.
  It initializes the OLED display and shows a static text "Hello, World!" on it.

  Connections:
  - The SSD1306 OLED display is connected to the STM32F103C8T6 Blue Pill as follows:
    - The VCC pin of the OLED is connected to the 3.3V pin on the STM32F103C8T6 Blue Pill (used for providing power to the display). Note that STM32F103C8T6 operates with 3.3V logic level.
    - The GND pin of the OLED is connected to the GND pin on the STM32F103C8T6 Blue Pill (for grounding the display).
    - The SCL pin of the OLED is connected to pin PB6 on the STM32F103C8T6 Blue Pill (which serves as the Serial Clock Line for I2C communication). In the Arduino framework for STM32, this pin is often mapped as PB6 for I2C clock.
    - The SDA pin of the OLED is connected to pin PB7 on the STM32F103C8T6 Blue Pill (which serves as the Serial Data Line for I2C communication). Similarly, PB7 is commonly used for I2C data in this context.

  Diagram:
  
       SSD1306 OLED         STM32F103C8T6 Blue Pill
     ----------------------    --------------------
    |          |            |                    |
    |   VCC ----|------------|   3.3V             |
    |   GND ----|------------|   GND               |
    |   SCL ----|------------|   PB6 (SCL)         |
    |   SDA ----|------------|   PB7 (SDA)         |
    |          |            |                    |
     ----------------------    --------------------

  The code first initializes the OLED display and then repeatedly clears the display and shows the text in the loop.

  created 2024
  by Liang
*/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Define the width of the OLED display in pixels. In this case, it's set to 128 pixels.
const int SCREEN_WIDTH = 128; 
// Define the height of the OLED display in pixels. Here, it's set to 64 pixels.
const int SCREEN_HEIGHT = 64; 

// Declaration for an SSD1306 display connected to I2C (using the SDA and SCL pins).
// The constructor takes the screen width, screen height, a pointer to the Wire object (for I2C communication), and an address offset (-1 in this case).
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
    // Initialize the serial communication with a baud rate of 9600.
    // This is mainly used for debugging purposes, like printing error messages or status information.
    Serial.begin(9600);

    // Configure the I2C pins (PB6 as SCL and PB7 as SDA) for I2C communication.
    // This is specific to the STM32F103C8T6 Blue Pill when using the Arduino framework.
    Wire.begin(PB7, PB6);

    // Try to initialize the SSD1306 OLED display.
    // The first parameter SSD1306_SWITCHCAPVCC indicates the type of power supply configuration for the display.
    // The second parameter is the I2C address of the display. Here, 0x3C is used for this particular 128x64 OLED display.
    // If the initialization fails, it prints an error message to the serial monitor and enters an infinite loop.
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
        Serial.println(F("SSD1306 allocation failed"));
        while(true);
    }
}

void loop() {
    // Clear the entire display. This erases any previous content on the OLED screen.
    display.clearDisplay();

    // Set the text size to 1. This determines the relative size of the text that will be displayed on the OLED.
    display.setTextSize(1);
    // Set the text color to WHITE. This defines the color of the text that will be shown on the display.
    display.setTextColor(WHITE);
    // Set the cursor position to column 0 and row 10 on the display.
    // The coordinates start from the top-left corner of the screen (0, 0).
    display.setCursor(0, 10);

    // Display a static text "Hello, World!" on the OLED display.
    // The text will be shown at the position specified by the cursor.
    display.println("Hello, World!");
    // Update the display to show the new content (in this case, the text).
    display.display();
}