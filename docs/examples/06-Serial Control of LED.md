# 串口控制 LED

###### 目录

> - Arduino API
>     - Arduino UNO R3
>     - STM32F103C8T6 Bule Pill
>     - ESP32-DevKitC
> - MicroPython API
>     - ESP32-DevKitC
> - STM32Cube（待补充）

# Arduino API

## Arduino UNO R3

![Clipboard - 2024-10-08 20.55.59](../images/Clipboard - 2024-10-08 20.55.59-2266108.png)

```arduino
/*
  Serial Control of LED

  This code allows you to control an LED using serial communication.
  You can send commands via the serial monitor to turn the LED on or off.
  
  Circuit:
  - LED connected to pin 13 through a 220Ω resistor
  - Serial communication at 9600 baud rate

  Diagram:

      Arduino         LED
     ---------       -----
    |         |     |     |
    |     13  |-----|>|---+---- GND
    |         |     (Anode) (Cathode)
    |         |
  
  The LED's anode (longer leg) is connected to pin 13, and the cathode (shorter leg) is connected to ground (GND) through a 220Ω resistor.

  created 2024
  by Liang
*/

// Define the pin where the LED is connected
const int ledPin = 13;

void setup() {
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);

  // Initialize serial communication at a baud rate of 9600
  Serial.begin(9600);

  // Print a message to the serial monitor
  Serial.println("Enter 'on' to turn the LED on, 'off' to turn the LED off:");
}

void loop() {
  // Check if any data is available to read from the serial port
  if (Serial.available() > 0) {
    // Read the incoming data as a string
    String command = Serial.readStringUntil('\\n');

    // Trim any whitespace characters (e.g., newlines)
    command.trim();

    // Check if the command is "on"
    if (command == "on") {
      // Turn the LED on
      digitalWrite(ledPin, HIGH);
      Serial.println("LED is ON");
    }
    // Check if the command is "off"
    else if (command == "off") {
      // Turn the LED off
      digitalWrite(ledPin, LOW);
      Serial.println("LED is OFF");
    } else {
      // If an unknown command is received, print an error message
      Serial.println("Invalid command. Enter 'on' or 'off'.");
    }
  }
}
```

## STM32F103C8T6 Bule Pill

```arduino
// Serial Control of LED
// This code enables you to control an LED through serial communication.
// You can send commands via the serial monitor to turn the LED on or off.

// Circuit:
// - The LED is connected to pin 13 through a 220Ω resistor.
// - Serial communication is set at a baud rate of 9600.

// Diagram:
// 
//      STM32 Blue Pill         LED
//     -----------------       -----
//    |                 |     |     |
//    |         13      |-----|>|---+---- GND
//    |                 |     (Anode) (Cathode)
//    |                 |
// 
// The anode (the longer leg) of the LED is connected to pin 13, and the cathode (the shorter leg) is connected to the ground (GND) through a 220Ω resistor.

// Created in 2024
// By Liang

// Include the necessary Arduino framework header file. For STM32 Blue Pill development, it's compatible with the Arduino framework.

// Define the pin to which the LED is connected. Here it's pin 13.
const int ledPin = 13;

void setup() {
    // Initialize the LED pin as an output mode, which is used to control the on/off state of the LED.
    pinMode(ledPin, OUTPUT);

    // Initialize serial communication with a baud rate of 9600, so that it can receive and send serial data.
    Serial.begin(9600);

    // Print a message to the serial monitor to inform the user how to operate.
    Serial.println("Enter 'on' to turn the LED on, 'off' to turn the LED off:");
}

void loop() {
    // Check if there is any data available to be read from the serial port. That is, check if any characters have been received from the serial port.
    if (Serial.available() > 0) {
        // Read the incoming data as a string until a newline character '\n' is encountered.
        String command = Serial.readStringUntil('\n');

        // Trim any white space characters (such as newline characters, etc.) at both ends of the string to standardize the command.
        command.trim();

        // Check if the received command is "on". If so, perform the operation to turn on the LED.
        if (command == "on") {
            // Set the LED pin to high level to turn on the LED.
            digitalWrite(ledPin, HIGH);
            Serial.println("LED is ON");
        }
        // Check if the received command is "off". If so, perform the operation to turn off the LED.
        else if (command == "off") {
            // Set the LED pin to low level to turn off the LED.
            digitalWrite(ledPin, LOW);
            Serial.println("LED is OFF");
        }
        else {
            // If the received command is neither "on" nor "off", it's considered an invalid command. Send an error message to the serial port.
            Serial.println("Invalid command. Enter 'on' or 'off'.");
        }
    }
}
```



## ESP32-DevKitC

```arduino
// Serial Control of LED
// This code enables you to control an LED via serial communication with ESP32-DevKitC.
// You can send commands through the serial monitor to switch the LED on or off.

// Circuit Description:
// - The LED is connected to pin 13 of ESP32-DevKitC through a 220Ω resistor.
// - The serial communication is set to a baud rate of 9600.

// Diagram Illustration:
// 
//      ESP32-DevKitC         LED
//     --------------        -----
//    |              |      |     |
//    |      13      |------|>|---+---- GND
//    |              |      (Anode) (Cathode)
//    |              |
// 
// The anode (the longer leg) of the LED is connected to pin 13, and the cathode (the shorter leg) is connected to the ground (GND) through a 220Ω resistor.

// Created in 2024
// By Liang

// Include the necessary header files for using the Arduino framework with ESP32-DevKitC.

// Define the pin number where the LED is connected. In this case, it's pin 13.
const int ledPin = 13;

void setup() {
    // Initialize the LED pin as an output. This allows us to control the voltage level on this pin to turn the LED on or off.
    pinMode(ledPin, OUTPUT);

    // Initialize the serial communication with a baud rate of 9600. This enables communication with external devices (like a computer's serial monitor).
    Serial.begin(9600);

    // Print a prompt message to the serial monitor to inform the user about the valid commands for controlling the LED.
    Serial.println("Enter 'on' to turn the LED on, 'off' to turn the LED off:");
}

void loop() {
    // Check if there is any data available to be read from the serial port. If data is available, it means a command has been sent from the serial monitor.
    if (Serial.available() > 0) {
        // Read the incoming data as a string until a newline character ('\n') is encountered. This reads the complete command entered by the user.
        String command = Serial.readStringUntil('\n');

        // Trim any whitespace characters (such as spaces or newlines) from the beginning and end of the command string to clean up the input.
        command.trim();

        // Check if the command entered by the user is "on". If it is, we'll turn on the LED.
        if (command == "on") {
            // Set the LED pin to HIGH (which provides voltage to the LED) to turn it on.
            digitalWrite(ledPin, HIGH);
            Serial.println("LED is ON");
        }
        // Check if the command is "off". If so, we'll turn off the LED.
        else if (command == "off") {
            // Set the LED pin to LOW (which removes voltage from the LED) to turn it off.
            digitalWrite(ledPin, LOW);
            Serial.println("LED is OFF");
        }
        else {
            // If the command received is neither "on" nor "off", it's considered an invalid command. So, print an error message to the serial monitor.
            Serial.println("Invalid command. Enter 'on' or 'off'.");
        }
    }
}
```

# MicroPython API

## ESP32-DevKitC

```python
"""
通过串口控制LED

此代码允许你使用串口通信来控制一个LED。
你可以通过串口监视器发送命令来打开或关闭LED。

电路连接情况：
- LED通过一个220Ω电阻连接到引脚13。
- 串口通信采用9600波特率。

示意图如下：

      ESP32-DevKitC         LED
     ---------       -----
    |         |     |     |
    |     13  |-----|>|---+---- GND
    |         |     (Anode) (Cathode)
    |         |

LED的阳极（较长引脚）连接到引脚13，阴极（较短引脚）通过一个220Ω电阻连接到地（GND）。

创建于2024
作者：Liang
"""

from machine import Pin, UART
import time

# 定义LED所连接的引脚，这里对应ESP32-DevKitC的引脚13
led_pin = Pin(13, Pin.OUT)
# 初始化串口通信，波特率设置为9600，用于接收和发送数据
uart = UART(1, 9600)

while True:
    # 判断串口是否有数据可读，如果可读字节数大于0则表示有数据
    if uart.any() > 0:
        # 读取串口接收到的数据，以字符串形式返回，这里读取到换行符为止
        command = uart.readline().decode('utf-8').strip()

        # 检查接收到的命令是否为"on"
        if command == "on":
            # 将LED引脚设置为高电平，点亮LED
            led_pin.value(1)
            # 通过串口发送消息告知LED已打开
            uart.write('LED is ON\n')
        # 检查接收到的命令是否为"off"
        elif command == "off":
            # 将LED引脚设置为低电平，关闭LED
            led_pin.value(0)
            # 通过串口发送消息告知LED已关闭
            uart.write('LED is OFF\n')
        else:
            # 如果接收到的命令不是"on"或者"off"，则认为是无效命令，通过串口发送错误提示信息
            uart.write('Invalid command. Enter \'on\' or \'off\'.\n')
    # 适当延时，避免过于频繁地检查串口数据，这里延时0.1秒，可根据实际情况调整
    time.sleep(0.1)
```





