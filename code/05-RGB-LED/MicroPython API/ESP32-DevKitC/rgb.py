"""
ESP32的RGB LED控制

此代码允许你使用PWM来控制RGB LED的红、绿、蓝各颜色分量的亮度。
RGB LED的红色引脚连接到ESP32的GPIO 16，绿色引脚连接到GPIO 17，蓝色引脚连接到GPIO 18，它们各自通过一个220Ω电阻连接。
公共阴极引脚连接到地线（GND）。

电路示意图如下：

      ESP32            RGB LED
     -------------------------------
    |   GND   | ------> | Cathode (Common) |
    |  GPIO16 | ------> | Red Anode        |
    |  GPIO17 | ------> | Green Anode      |
    |  GPIO18 | ------> | Blue Anode       |
     ------------------------------

创建于2024
作者：Liang
"""

from machine import Pin, PWM
import time

# 初始化红色引脚对应的PWM对象，引脚为16
pwm_red = PWM(Pin(16))
# 设置PWM频率，这里设置为1000Hz，可根据实际情况调整
pwm_red.freq(1000)

# 初始化绿色引脚对应的PWM对象，引脚为17
pwm_green = PWM(Pin(17))
pwm_green.freq(1000)

# 初始化蓝色引脚对应的PWM对象，引脚为18
pwm_blue = PWM(Pin(18))
pwm_blue.freq(1000)


def set_color(red, green, blue):
    """
    使用PWM设置RGB LED的颜色的函数。

    参数：
    - red：红色分量的亮度值，取值范围0 - 1023，对应不同亮度等级。
    - green：绿色分量的亮度值，取值范围0 - 1023，对应不同亮度等级。
    - blue：蓝色分量的亮度值，取值范围0 - 1023，对应不同亮度等级。

    此函数通过将传入的各颜色分量亮度值设置到对应的PWM引脚，从而改变RGB LED显示的颜色。
    """
    # 设置红色引脚的PWM占空比，以控制红色亮度
    pwm_red.duty(red)
    # 设置绿色引脚的PWM占空比，以控制绿色亮度
    pwm_green.duty(green)
    # 设置蓝色引脚的PWM占空比，以控制蓝色亮度
    pwm_blue.duty(blue)


while True:
    """
    主循环，用于循环展示不同颜色。

    在循环中，依次调用set_color函数来设置RGB LED显示不同的颜色，每种颜色显示1秒钟，
    展示的颜色包括红、绿、蓝、黄、青、品红、白以及关闭（黑色）。
    """
    # 设置LED为红色（红色全亮，绿色和蓝色关闭）
    set_color(1023, 0, 0)
    time.sleep(1)

    # 设置LED为绿色（绿色全亮，红色和蓝色关闭）
    set_color(0, 1023, 0)
    time.sleep(1)

    # 设置LED为蓝色（蓝色全亮，红色和绿色关闭）
    set_color(0, 0, 1023)
    time.sleep(1)

    # 设置LED为黄色（红色和绿色全亮，蓝色关闭）
    set_color(1023, 1023, 0)
    time.sleep(1)

    # 设置LED为青色（绿色和蓝色全亮，红色关闭）
    set_color(0, 1023, 1023)
    time.sleep(1)

    # 设置LED为品红色（红色和蓝色全亮，绿色关闭）
    set_color(1023, 0, 1023)
    time.sleep(1)

    # 设置LED为白色（红、绿、蓝全亮）
    set_color(1023, 1023, 1023)
    time.sleep(1)

    # 关闭LED（所有颜色分量亮度为0，显示黑色）
    set_color(0, 0, 0)
    time.sleep(1)