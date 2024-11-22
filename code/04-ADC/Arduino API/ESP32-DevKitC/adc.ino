/*
  ESP32 ADC with PWM LED Control

  This code reads the analog value from a potentiometer or analog sensor connected to GPIO32 (ADC1_4) on the ESP32 and 
  converts it into a PWM signal that controls the brightness of an LED connected to GPIO15 using PWM.

  Circuit:
  - Analog input (e.g., potentiometer) connected to GPIO32 (ADC1_4).
  - One side of the potentiometer connected to 3.3V, the other side connected to GND.
  - Middle pin of the potentiometer connected to GPIO32.
  - LED connected to GPIO15 through a 220Ω resistor.
  
  Diagram:
  
       +3.3V ----[Potentiometer]---- GND
                     |
                    GPIO32 (ADC input)
  
       ESP32         LED
     -----------     -----
    |           |   |     |
    |    15  ---|---|>|---+---- GND
    | (PWM Pin) |   (Anode) (Cathode)
    |           |
    
  The analog input from GPIO32 is read, and its value is mapped to control the brightness of an LED using PWM on GPIO15.

  created 2024
  by Liang
*/

const int potPin = 32;   // Potentiometer connected to GPIO32 (ADC1_4)
const int ledPin = 15;   // LED connected to GPIO15 (PWM-capable pin)

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Configure the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read the analog input from GPIO32 (12-bit resolution, values between 0 and 4095)
  int analogInputVal = analogRead(potPin);

  // Map the analog input (0-4095) to the PWM range (0-255)
  int brightness = map(analogInputVal, 0, 4095, 0, 255);

  // Print the raw analog input value to the Serial Monitor for debugging
  Serial.print("Analog Input Value: ");
  Serial.println(analogInputVal);

  // Print the mapped brightness value to the Serial Monitor for debugging
  Serial.print("LED Brightness Value: ");
  Serial.println(brightness);

  // Write the mapped brightness to the LED using PWM on GPIO15
  ledcWrite(0, brightness);  // PWM on channel 0 with brightness value
}