# Arduino API

## Arduino UNO R3

```arduino
/*
  PIR Motion Sensor Control Example

  This code allows you to detect motion using a PIR motion sensor and control an LED based on the sensor's output.
  When motion is detected, the LED will turn on.

  Circuit:
  - PIR sensor VCC connected to 5V on Arduino.
  - PIR sensor GND connected to GND on Arduino.
  - PIR sensor OUT connected to digital pin 2 on Arduino.
  - Built-in LED (pin 13) is used to indicate motion detection.

  Diagram:
  
       PIR Sensor         Arduino
     --------------      ---------
    |              |    |         |
    |   VCC -------|----|   5V    |
    |   GND -------|----|   GND   |
    |   OUT -------|----|   2     |
    |              |    |         |
    |              |    |         |
     --------------      ---------
  
  The PIR sensor detects motion and sends a HIGH signal to pin 2 of the Arduino when motion is detected. The built-in LED on pin 13 will light up when motion is detected.

  created 2024
  by Liang
*/

const int pirPin = 2;   // PIR sensor output pin
const int ledPin = 13;  // Built-in LED pin (pin 13)

void setup() {
  // Set up the PIR sensor pin as an input
  pinMode(pirPin, INPUT);

  // Set up the LED pin as an output
  pinMode(ledPin, OUTPUT);

  // Start the serial communication for monitoring sensor output
  Serial.begin(9600);
}

void loop() {
  // Read the state of the PIR sensor (HIGH when motion is detected, LOW when no motion)
  int pirState = digitalRead(pirPin);

  // Print the state of the PIR sensor to the serial monitor
  Serial.println(pirState);

  // If motion is detected, turn on the LED
  if (pirState == HIGH) {
    digitalWrite(ledPin, HIGH);  // Turn on LED
    Serial.println("Motion detected");
  } else {
    digitalWrite(ledPin, LOW);  // Turn off LED
    Serial.println("No motion");
  }

  delay(100);  // Short delay for sensor stability
}
```

## STM32F103C8T6 Bule Pill

```arduino
/*
  PIR Motion Sensor Control Example for STM32F103C8T6

  This code allows you to detect motion using a PIR motion sensor and control an LED based on the sensor's output.
  When motion is detected, the built-in LED (PC13) will turn on.

  Circuit:
  - PIR sensor VCC connected to 5V on STM32.
  - PIR sensor GND connected to GND on STM32.
  - PIR sensor OUT connected to digital pin PA0 on STM32.
  - Built-in LED (PC13) is used to indicate motion detection.

  Diagram:
  
       PIR Sensor         STM32F103C8T6
     --------------      ---------------
    |              |    |               |
    |   VCC -------|----|   5V          |
    |   GND -------|----|   GND         |
    |   OUT -------|----|   PA0         |
    |              |    |               |
    |              |    |               |
     --------------      ---------------
  
  The PIR sensor detects motion and sends a HIGH signal to PA0 of the STM32 when motion is detected. The built-in LED on PC13 will light up when motion is detected.

  created 2024
  by Liang
*/

const int pirPin = PA0;   // PIR sensor output pin (PA0 on STM32)
const int ledPin = PC13;  // Built-in LED pin (PC13 on STM32)

void setup() {
  // Set up the PIR sensor pin as an input
  pinMode(pirPin, INPUT);

  // Set up the built-in LED pin as an output
  pinMode(ledPin, OUTPUT);

  // Start the serial communication for monitoring sensor output
  Serial.begin(9600);
}

void loop() {
  // Read the state of the PIR sensor (HIGH when motion is detected, LOW when no motion)
  int pirState = digitalRead(pirPin);

  // Print the state of the PIR sensor to the serial monitor
  Serial.println(pirState);

  // If motion is detected, turn on the LED
  if (pirState == HIGH) {
    digitalWrite(ledPin, LOW);  // Turn on LED (PC13 is active LOW)
    Serial.println("Motion detected");
  } else {
    digitalWrite(ledPin, HIGH);  // Turn off LED (PC13 is active LOW)
    Serial.println("No motion");
  }

  delay(100);  // Short delay for sensor stability
}
```

## ESP32-DevKitC

```arduino
/*
  PIR Motion Sensor Control Example for ESP32

  This code allows you to detect motion using a PIR motion sensor and control an LED based on the sensor's output.
  When motion is detected, the LED (GPIO 2) will turn on.

  Circuit:
  - PIR sensor VCC connected to 5V on ESP32.
  - PIR sensor GND connected to GND on ESP32.
  - PIR sensor OUT connected to digital pin GPIO 23 on ESP32.
  - Built-in LED (GPIO 2) is used to indicate motion detection.

  Diagram:
  
       PIR Sensor         ESP32
     --------------      ---------------
    |              |    |               |
    |   VCC -------|----|   5V          |
    |   GND -------|----|   GND         |
    |   OUT -------|----|   GPIO 23     |
    |              |    |               |
    |              |    |               |
     --------------      ---------------
  
  The PIR sensor detects motion and sends a HIGH signal to GPIO 23 of the ESP32 when motion is detected. The built-in LED on GPIO 2 will light up when motion is detected.

  created 2024
  by Liang
*/

const int pirPin = 23;   // PIR sensor output pin (GPIO 23 on ESP32)
const int ledPin = 2;    // Built-in LED pin (GPIO 2 on ESP32)

void setup() {
  // Set up the PIR sensor pin as an input
  pinMode(pirPin, INPUT);

  // Set up the built-in LED pin as an output
  pinMode(ledPin, OUTPUT);

  // Start the serial communication for monitoring sensor output
  Serial.begin(9600);
}

void loop() {
  // Read the state of the PIR sensor (HIGH when motion is detected, LOW when no motion)
  int pirState = digitalRead(pirPin);

  // Print the state of the PIR sensor to the serial monitor
  Serial.println(pirState);

  // If motion is detected, turn on the LED
  if (pirState == HIGH) {
    digitalWrite(ledPin, HIGH);  // Turn on LED
    Serial.println("Motion detected");
  } else {
    digitalWrite(ledPin, LOW);  // Turn off LED
    Serial.println("No motion");
  }

  delay(100);  // Short delay for sensor stability
}
```

# MicroPython API

## ESP32-DevKitC

# Raspberry Pi

## **Motion sensor**

!https://gpiozero.readthedocs.io/en/stable/_images/motion_sensor_bb.svg

Light an [**`LED`**](https://gpiozero.readthedocs.io/en/stable/api_output.html#gpiozero.LED) when a [**`MotionSensor`**](https://gpiozero.readthedocs.io/en/stable/api_input.html#gpiozero.MotionSensor) detects motion:

```python
**from** **gpiozero** **import** MotionSensor, LED
**from** **signal** **import** pause

pir = MotionSensor(4)
led = LED(16)

pir.when_motion = led.on
pir.when_no_motion = led.off

pause()
```

# ESP-IDF API

## ESP32-DevKitC