"""
使用ESP32-DevKitC控制OLED显示屏

此代码展示了如何通过ESP32-DevKitC开发板利用MicroPython框架控制一个4针的OLED显示屏。
代码会对OLED显示屏进行初始化，并在显示屏上显示静态文本“Hello, World!”。

电路连接情况：
- SSD1306 OLED显示屏与ESP32-DevKitC连接如下：
    - OLED的VCC引脚连接到ESP32-DevKitC的3.3V引脚（用于给显示屏供电，注意ESP32的引脚工作电压一般是3.3V）。
    - OLED的GND引脚连接到ESP32-DevKitC的GND引脚（实现显示屏接地）。
    - OLED的SCL引脚连接到ESP32-DevKitC的22号引脚（此引脚作为I2C通信的串行时钟线）。
    - OLED的SDA引脚连接到ESP32-DevKitC的21号引脚（此引脚作为I2C通信的串行数据线）。

连接示意图如下：

       SSD1306 OLED         ESP32-DevKitC
     ----------------------    -------------
    |          |            |             |
    |   VCC ----|------------|   3.3V      |
    |   GND ----|------------|   GND        |
    |   SCL ----|------------|   22         |
    |   SDA ----|------------|   21         |
    |          |            |             |
     ----------------------    -------------

代码首先初始化OLED显示屏，然后在循环中反复清空显示屏并显示文本内容。

创建于2024
作者：Liang
"""

from machine import Pin, I2C
import ssd1306
import time

# OLED显示屏宽度，单位为像素，这里设置为128像素
SCREEN_WIDTH = 128
# OLED显示屏高度，单位为像素，这里设置为64像素
SCREEN_HEIGHT = 64
# OLED显示屏的I2C地址，常见的128x64的SSD1306 OLED屏地址一般为0x3C
OLED_ADDR = 0x3C

# 初始化I2C对象，指定SDA引脚为21，SCL引脚为22，波特率为100000（I2C常用的标准波特率）
i2c = I2C(scl=Pin(22), sda=Pin(21), freq=100000)
# 初始化OLED显示屏对象，传入I2C对象、显示屏宽度、显示屏高度以及OLED的I2C地址
oled = ssd1306.SSD1306_I2C(SCREEN_WIDTH, SCREEN_HEIGHT, i2c, OLED_ADDR)


def setup_oled():
    """
    初始化OLED显示屏的函数。

    此函数用于尝试初始化OLED显示屏，如果初始化失败，会打印错误信息。
    """
    try:
        oled.init_display()
    except:
        print("OLED显示屏初始化失败，请检查硬件连接及相关配置")


def show_text():
    """
    在OLED显示屏上显示文本的函数。

    此函数先清空显示屏内容，然后设置文本相关属性（大小、颜色、位置等），最后在指定位置显示文本“Hello, World!”。
    """
    oled.fill(0)  # 清空显示屏，将所有像素点设置为熄灭状态（值为0）
    oled.text('Hello, World!', 0, 10, 1)  # 在坐标(0, 10)位置显示文本，最后参数1表示白色（点亮像素）
    oled.show()  # 更新显示屏内容，使设置的文本显示出来


if __name__ == "__main__":
    setup_oled()
    while True:
        show_text()
        time.sleep(1)  # 适当延时，避免过于频繁地更新显示内容，这里设置为每1秒更新一次，可根据实际需求调整