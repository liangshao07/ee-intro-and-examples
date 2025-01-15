# Raspberry Pi

- 快速入门教程

    - [Raspberry Pi Tutorial for Complete Beginners](https://www.youtube.com/playlist?list=PLLSegLrePWgLzBgQqDJvgZ4ewbpCnuare)

    - [Raspberry Pi and Python Tutorials](https://www.youtube.com/playlist?list=PLQVvvaa0QuDesV8WWHLLXW_avmTzHmJLv)

- 细致学习，与 Arduino 教程是同一个 YouTube 博主

    - [Free Raspberry Pi Tutorials for Absolute Beginners](https://www.youtube.com/playlist?list=PLGs0VKk2DiYxdMjCJmcP6jt4Yw6OHK85O)

- GPIOzero-library
- RPiGPIO-library

## 树莓派 GPIO 编程简介

在树莓派上进行硬件控制，最常用的两个 Python 库是 GPIOZero 和 RPi.GPIO。这两个库各有特色，适用于不同的开发场景。

> 注意：树莓派编程，使用的是 Python3，而不是 MicroPython。

## RPi.GPIO库

RPi.GPIO 是树莓派最早也是最基础的 GPIO 控制库，提供了直接的底层控制能力。

### 基本使用示例

```python
import RPi.GPIO as GPIO
import time

# 设置GPIO模式
GPIO.setmode(GPIO.BCM)
# 设置引脚为输出模式
GPIO.setup(18, GPIO.OUT)

try:
    while True:
        GPIO.output(18, GPIO.HIGH)  # LED打开
        time.sleep(1)
        GPIO.output(18, GPIO.LOW)   # LED关闭
        time.sleep(1)
finally:
    GPIO.cleanup()  # 清理GPIO状态
```

### RPi.GPIO特点

- 提供底层硬件控制，灵活性高
- 需要手动管理引脚状态和清理
- 代码较为复杂，需要更多样板代码
- 支持 PWM 输出和中断检测

## GPIOZero库

GPIOZero 是一个更现代的库，设计理念是简化 GPIO 编程，提供更直观的接口。

### 基本使用示例

```python
from gpiozero import LED
from time import sleep

# 创建LED对象
led = LED(18)

# LED闪烁
while True:
    led.on()    # LED打开
    sleep(1)
    led.off()   # LED关闭
    sleep(1)

# 或者更简单地：
led.blink()
```

### GPIOZero特点

- 代码简洁，易于理解和使用
- 自动管理资源，不需要手动清理
- 提供丰富的内置组件类
- 支持事件驱动编程

## 两个库的主要区别

| **特性**   | **GPIOZero** | **RPi.GPIO** |
| ---------- | ------------ | ------------ |
| 抽象层级   | 高层抽象     | 底层控制     |
| 代码复杂度 | 简单         | 相对复杂     |
| 灵活性     | 较低         | 较高         |
| 学习曲线   | 平缓         | 较陡         |
| 资源管理   | 自动         | 手动         |

## 选择建议

如何选择这两个库？这里有一些建议：

### 使用GPIOZero的场景

- 教育和学习项目
- 快速原型开发
- 简单的硬件控制需求
- 希望专注于功能实现而不是底层细节

### 使用RPi.GPIO的场景

- 需要精确控制硬件时序
- 复杂的硬件交互项目
- 特殊的 GPIO 操作需求
- 对性能要求较高的场景
