"""
LED Brightness Control with PWM

此代码演示了如何使用 `machine.PWM` 类来控制连接到 GPIO2 引脚的 LED 的亮度。

电路连接：
- LED 连接到 GPIO2 和地线（GND）
- 串联一个限流电阻（例如 330Ω）

电路图：
    ESP32          LED
   ---------      -----
  |         |    |     |
  |    2    |----|>|---+---- GND
  |         |    (Anode) (Cathode)
  |         |  
  |         |

LED 的阳极（较长的脚）连接到 GPIO2 引脚，阴极（较短的脚）通过限流电阻连接到地线（GND）。

创建于 2024
作者：Liang
"""

from machine import Pin, PWM
import time

# 初始化 LED 引脚
led_pin = Pin(2)

# 创建 PWM 对象
pwm = PWM(led_pin)

# 设置 PWM 频率（单位为 Hz），这里设置为 1000Hz
pwm.freq(1000)

# 循环改变占空比，从而改变 LED 的亮度
while True:
    # 逐渐增加亮度
    for duty in range(0, 1024):
        pwm.duty(duty)  # 设置占空比
        time.sleep_ms(1)  # 等待 1 毫秒

    # 逐渐减少亮度
    for duty in range(1023, -1, -1):
        pwm.duty(duty)  # 设置占空比
        time.sleep_ms(1)  # 等待 1 毫秒