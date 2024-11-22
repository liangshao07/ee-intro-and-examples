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