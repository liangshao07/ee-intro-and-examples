"""
LED Blinking

此代码演示了如何使用 `machine.Pin` 类和 `time.sleep()` 函数使连接到 GPIO2 引脚的 LED 每隔 1 秒闪烁一次。

电路连接：
- LED 连接到 GPIO2 和地线（GND）

电路图：
    ESP32          LED
   ---------      -----
  |         |    |     |
  |    2    |----|>|---+---- GND
  |         |    (Anode) (Cathode)
  |         |  
  |         |

LED 的阳极（较长的脚）连接到 GPIO2 引脚，阴极（较短的脚）连接到地线（GND）。

创建于 2024
作者：Liang
"""

from machine import Pin
import time

# 初始化 LED 引脚为输出模式
led = Pin(2, Pin.OUT)

def blink():
    """
    无限循环，使 LED 以 1 秒间隔闪烁。
    
    在每次循环中，LED 将被点亮 1 秒钟，然后熄灭 1 秒钟。
    """
    while True:
        # 打开 LED
        led.value(1)  # 设置引脚为高电平
        print("LED on")
        # 延时 1 秒
        time.sleep(1)
        
        # 关闭 LED
        led.value(0)  # 设置引脚为低电平
        print("LED off")
        # 再次延时 1 秒
        time.sleep(1)

# 调用 blink 函数开始执行
blink()