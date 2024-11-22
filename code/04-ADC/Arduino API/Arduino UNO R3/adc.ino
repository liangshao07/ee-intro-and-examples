/*
  Analog Input to PWM LED Brightness Control

  This code reads the analog value from an analog input (e.g., a potentiometer) connected to pin A5 
  and converts it to a PWM signal that controls the brightness of an LED connected to pin 11.

  Circuit:
  - Analog input (e.g., potentiometer) connected to A5.
  - One side of the potentiometer connected to 5V, the other side connected to GND.
  - Middle pin of the potentiometer connected to A5 (analog input).
  - LED connected to pin 11 through a 220Ω resistor.
  
  Diagram:
  
       +5V ----[Potentiometer]---- GND
                     |
                     A5 (Analog input)
  
       Arduino         LED
     -----------      -----
    |           |    |     |
    |     13  --|----|>|---+---- GND
    | (PWM Pin) |    (Anode) (Cathode)
    |           |
    
  The analog input (A5) reads the voltage from the potentiometer and converts it into a brightness value for the LED using PWM.

  created 2024
  by Liang
*/

void setup() {
  // Initialize serial communication at 9600 baud to send data to the Serial Monitor
  Serial.begin(9600);
  
  // Set pin 11 as an output for controlling the brightness of the LED
  pinMode(13, OUTPUT);
}

void loop() {
  // Read the analog input value from the potentiometer connected to pin A5
  // The analogRead() function returns a value between 0 and 1023
  int analogInputVal = analogRead(A5);

  // Map the analog input value (0-1023) to a PWM value (0-255)
  // This allows us to control the brightness of the LED using analogWrite() on pin 11
  int brightness = map(analogInputVal, 0, 1023, 0, 255);

  // Print the raw analog input value to the Serial Monitor for debugging
  Serial.print("Analog Input Value: ");
  Serial.println(analogInputVal);

  // Print the mapped brightness value to the Serial Monitor for debugging
  Serial.print("LED Brightness Value: ");
  Serial.println(brightness);

  // Set the brightness of the LED by writing the mapped PWM value to pin 11
  analogWrite(13, brightness);
}