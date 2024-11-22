/*
  ESP32 LED Brightness Control

  This code gradually increases and decreases the brightness of an LED connected to GPIO 13 using PWM (Pulse Width Modulation).
  It also outputs the brightness values to the Serial Monitor for debugging or monitoring purposes.

  The circuit:
  - LED connected to GPIO 13 (PWM-capable pin) through a 220Ω resistor.
  - The cathode (shorter leg) of the LED connected to GND.
  - Serial monitor used for outputting brightness values.

  Diagram:

      ESP32         LED
     -----------    -----
    |           |  |     |
    |    GPIO13 |--|>|---+---- GND
    | (PWM Pin) |  (Anode) (Cathode)
    |           |

  The anode (longer leg) of the LED is connected to GPIO 13 (PWM-capable) through a 220Ω resistor.
  The cathode (shorter leg) of the LED is connected to GND.

  created 2024
  by Liang
*/

// Define the PWM channel, frequency, resolution, and pin
const int ledPin = 13;           // GPIO pin for LED
const int pwmChannel = 0;        // Use PWM channel 0
const int pwmFrequency = 5000;   // 5 kHz PWM frequency
const int pwmResolution = 8;     // 8-bit resolution, values from 0 to 255

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Configure PWM functionality on the specified pin
  ledcSetup(pwmChannel, pwmFrequency, pwmResolution);  // Set up PWM channel with frequency and resolution
  ledcAttachPin(ledPin, pwmChannel);  // Attach GPIO 13 to the PWM channel
}

void loop() {
  // Gradually increase brightness from 0 to 255 (LED gets brighter)
  for (int brightness = 0; brightness <= 255; brightness++) {
    // Set the brightness of the LED using PWM on the defined channel
    ledcWrite(pwmChannel, brightness);  

    // Output the current brightness value to the Serial Monitor
    Serial.println(brightness);   

    // Wait for 10 milliseconds before updating the brightness again
    delay(10);                    
  }

  // Gradually decrease brightness from 255 to 0 (LED gets dimmer)
  for (int brightness = 255; brightness >= 0; brightness--) {
    // Set the brightness of the LED using PWM on the defined channel
    ledcWrite(pwmChannel, brightness);  

    // Output the current brightness value to the Serial Monitor
    Serial.println(brightness);   

    // Wait for 10 milliseconds before updating the brightness again
    delay(10);                    
  }
}