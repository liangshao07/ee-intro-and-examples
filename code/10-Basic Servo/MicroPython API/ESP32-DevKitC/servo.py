"""
使用ESP32-DevKitC通过MicroPython利用PWM控制舵机

此代码借助ESP32-DevKitC开发板以及MicroPython框架，运用PWM（脉冲宽度调制）的方式来控制舵机的角度。
你既可以通过串口向开发板发送0到180之间的角度值，以此控制舵机转动到指定角度，也可以运行代码中的示例循环，让舵机在0度和180度之间来回转动。

电路连接情况：
- 舵机的信号线连接到ESP32-DevKitC的2号引脚（该引脚可根据实际硬件情况进行调整，这里以2号引脚为例）。
- 舵机的电源可以连接到开发板的5V引脚（如果舵机功率需求在ESP32供电能力范围内），若舵机需要更大功率，则需使用外部电源，舵机的地线连接到ESP32-DevKitC的GND引脚。

连接示意图如下：

      ESP32-DevKitC          Servo Motor
     --------------        -------------
    |              |       |           |
    |     2        |-------| Signal     |
    |              |       |           |
    |    5V (or external power) | VCC        |
    |   GND        |-------| GND        |
    |              |       |           |


创建于2024
作者：Liang
"""

from machine import Pin, PWM
import time

# 定义舵机信号线所连接的引脚，这里使用2号引脚，你可按需更改
servo_pin = Pin(2, Pin.OUT)
# 初始化PWM对象，设置频率为50Hz（舵机通常使用50Hz的PWM信号来控制角度）
pwm = PWM(servo_pin, freq=50)

def set_servo_angle(angle):
    """
    根据传入的角度值来设置舵机角度的函数。

    参数：
    - angle：要设置的舵机角度，取值范围是0到180度，超出此范围的角度值将被视为无效。

    此函数依据舵机的PWM控制原理，将角度值转换为对应的PWM占空比值，进而控制舵机转动到指定角度。
    """
    # 判断角度值是否在有效范围内（0到180度）
    if 0 <= angle <= 180:
        # 将角度转换为对应的PWM占空比，不同的舵机可能会有细微差异，这里是常见的转换计算方式
        duty = int(((angle / 180) * 2 + 0.5) / 20 * 1023)
        pwm.duty(duty)
    else:
        print("无效角度，请输入0到180之间的值")


if __name__ == "__main__":
    # 以下是一个简单的示例，让舵机在0度和180度之间循环转动，每隔1秒切换一次角度
    while True:
        set_servo_angle(180)
        time.sleep(1)
        set_servo_angle(0)
        time.sleep(1)

    # 若要通过串口控制舵机角度，可取消以下注释，并按照注释提示添加相应代码逻辑

    # 导入串口通信相关模块（这里假设使用UART进行串口通信，你也可以根据实际情况调整）
    # from machine import UART
    # 初始化串口通信，波特率设置为9600，用于接收和发送数据（这里示例使用UART 1，可按需更改）
    # uart = UART(1, 9600)
    # while True:
    #     # 判断串口是否有数据可读，如果可读字节数大于0则表示有数据
    #     if uart.any() > 0:
    #         # 读取串口接收到的数据，以字符串形式返回
    #         data = uart.readline().decode('utf-8').strip()
    #         try:
    #             # 将接收到的字符串数据转换为整数类型的角度值
    #             angle = int(data)
    #             # 调用函数设置舵机角度
    #             set_servo_angle(angle)
    #             print("舵机角度已设置为：", angle)
    #         except ValueError:
    #             print("接收到无效数据，请输入整数角度值（0到180之间）")
    #     # 适当延时，避免过于频繁地检查串口数据，这里延时0.1秒，可根据实际情况调整
    #     time.sleep(0.1)