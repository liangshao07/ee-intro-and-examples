"""
ESP32 控制 7 位数码管

此代码演示了如何使用 MicroPython 将 ESP32 连接到 7 位数码管，并显示数字 0 到 9。

电路连接：
- 共阴极数码管
- a: GPIO 12
- b: GPIO 13
- c: GPIO 14
- d: GPIO 15
- e: GPIO 16
- f: GPIO 17
- g: GPIO 18
- GND: 公共阴极连接到 GND

电路图：
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

创建于 2024
作者：Liang
"""

import machine
import time

# 定义数码管的段引脚
segments = [
    machine.Pin(5, machine.Pin.OUT),  # a
    machine.Pin(18, machine.Pin.OUT), # b
    machine.Pin(19, machine.Pin.OUT), # c
    machine.Pin(21, machine.Pin.OUT), # d
    machine.Pin(22, machine.Pin.OUT), # e
    machine.Pin(23, machine.Pin.OUT), # f
    machine.Pin(25, machine.Pin.OUT), # g
    machine.Pin(26, machine.Pin.OUT)  # dp
]

# 定义数码管显示数字 0 到 9 的段码
digit_patterns = {
    0: (1, 1, 1, 1, 1, 1, 0, 0),  # 0
    1: (0, 1, 1, 0, 0, 0, 0, 0),  # 1
    2: (1, 1, 0, 1, 1, 0, 1, 0),  # 2
    3: (1, 1, 1, 1, 0, 0, 1, 0),  # 3
    4: (0, 1, 1, 0, 0, 1, 1, 0),  # 4
    5: (1, 0, 1, 1, 0, 1, 1, 0),  # 5
    6: (1, 0, 1, 1, 1, 1, 1, 0),  # 6
    7: (1, 1, 1, 0, 0, 0, 0, 0),  # 7
    8: (1, 1, 1, 1, 1, 1, 1, 0),  # 8
    9: (1, 1, 1, 1, 0, 1, 1, 0)   # 9
}

def display_digit(digit):
    """
    显示指定的数字。
    
    参数:
        digit (int): 要显示的数字（0-9）。
    """
    if 0 <= digit <= 9:
        pattern = digit_patterns[digit]
        for i in range(len(segments)):
            segments[i].value(pattern[i])
    else:
        print("无效的数字")

def main():
    """
    主函数，循环显示 0 到 9。
    """
    while True:
        for digit in range(10):
            display_digit(digit)
            time.sleep(1)

if __name__ == "__main__":
    main()