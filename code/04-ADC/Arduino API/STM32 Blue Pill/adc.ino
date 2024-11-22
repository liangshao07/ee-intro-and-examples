/*
  STM32F103C8T6 (Blue Pill) ADC with PWM LED Control

  This code reads the analog value from a potentiometer or analog sensor connected to PA0 (A0) 
  and converts it to a PWM signal that controls the brightness of an LED connected to PB1 using PWM.

  Circuit:
  - Analog input (e.g., potentiometer) connected to PA0 (A0).
  - One side of the potentiometer connected to 3.3V, the other side connected to GND.
  - Middle pin of the potentiometer connected to PA0 (A0).
  - LED connected to PB1 through a 220Ω resistor.
  
  Diagram:
  
       +3.3V ----[Potentiometer]---- GND
                     |
                    PA0 (Analog input)
  
       STM32         LED
     -----------     -----
    |           |   |     |
    |   PB1  ---|---|>|---+---- GND
    | (PWM Pin) |   (Anode) (Cathode)
    |           |
    
  The analog input from PA0 (A0) is read, and its value is mapped to control the brightness of an LED using PWM on PB1.

  created 2024
  by Liang
*/

const int potPin = PA0;   // Potentiometer connected to PA0 (A0) for ADC
const int ledPin = PB1;   // LED connected to PB1 (PWM-capable pin)

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Configure the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read the analog input from PA0 (12-bit resolution, values between 0 and 4095)
  int analogInputVal = analogRead(potPin);

  // Map the analog input (0-4095) to the PWM range (0-255)
  int brightness = map(analogInputVal, 0, 4095, 0, 255);

  // Print the raw analog input value to the Serial Monitor for debugging
  Serial.print("Analog Input Value: ");
  Serial.println(analogInputVal);

  // Print the mapped brightness value to the Serial Monitor for debugging
  Serial.print("LED Brightness Value: ");
  Serial.println(brightness);

  // Write the mapped brightness to the LED using PWM on PB1
  analogWrite(ledPin, brightness);  // analogWrite() works with PWM on STM32duino
}