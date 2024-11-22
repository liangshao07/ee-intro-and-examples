"""
Button Controlled LED

此代码演示了如何使用按钮控制连接到 GPIO2 引脚的 LED 的开关状态。

电路连接：
- 按钮连接到 GPIO14 和地线（GND），并通过一个上拉电阻（例如 10kΩ）连接到 3.3V。
- LED 连接到 GPIO2 和地线（GND），并通过一个限流电阻（例如 330Ω）连接到 GND。

电路图：
    ESP32          Button           LED
   ---------      ---------       -----
  |         |    |     |        |     |
  |    2    |----|>|---+--------|>|---+---- GND
  |         |    (A)  (B)       (Anode) (Cathode)
  |         |                  (通过 330Ω 电阻)
  |    14   |----|<|---+---- 3.3V (通过 10kΩ 上拉电阻)
  |         |    (C)  (D)
  |         |  
  |         |  

创建于 2024
作者：Liang
"""

from machine import Pin
import time

# 初始化 LED 引脚为输出模式
led = Pin(2, Pin.OUT)

# 初始化按钮引脚为输入模式，并启用内部上拉电阻
button = Pin(14, Pin.IN, Pin.PULL_UP)

def main():
    """
    主函数，循环检测按钮状态并控制 LED。
    """
    while True:
        # 读取按钮的状态
        button_state = button.value()
        
        # 如果按钮被按下（低电平）
        if button_state == 0:
            # 翻转 LED 的状态
            led.value(not led.value())
            # 延时 200ms 以防止按钮抖动
            time.sleep_ms(200)
        else:
            # 如果按钮没有被按下，继续循环
            pass

# 调用主函数开始执行
main()