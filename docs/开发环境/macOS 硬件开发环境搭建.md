#macOS 硬件开发环境搭建

> 软件开发环境见：

###### 目录

> - Arduino IDE
>     - Arduino
>     - ESP32
>     - STM32
> - STM32CubeIDE
> - VSC（VS code）
>     - PlatformIO
>     - ESP-IDF
>     - Remote - SSH
> - Clion
> - Thonny

# Arduino IDE

> Arduino 官方推出的专门用于，开发自家 Arduino 框架的 IDE，简单的配置环境、代码调试、上传烧录，非常适合初学者使用。
>
> 缺陷是，Arduino IDE 代码提示和补全能力弱，且 Arduino IDE 风格的项目，普遍项目分文件编写差，大多写在同一代码文件里。故而只适合学习和小项目（小项目的意思是你做的全部都算）使用。

- 官方下载：

## Arduino 开发环境

安装完软件后，首次打开，Arduino IDE 会自动下载 Arduino 开发板的环境依赖，耐心等待完成即可。

## ESP32 开发环境

三步走：

- 添加 ESP32 开发板
- 下载 ESP32 开发板
- 检验是否安装成功

## STM32 开发环境

三步走

- 添加 STM32 开发板
- 下载 STM32 开发板
- 检验是否安装成功

# STM32CubeIDE

> STM32CubeIDE 是 STM32 官方推出的 IDE，用于开发自家的 STM32 芯片，使用 STM32 官方最新的 STM32Cube 框架（HAL 库），与网络上 Keil5 开发使用的 STM32 标准库，同样能够开发 STM32，但是标准库已经被 STM32 停止更新，不再推崇。

- 官方下载：

全部默认，安装完成后，会出现安装依赖提示，跟随提示耐心安装即可。



# VSC（VS code）



## PlatformIO



## ESP-IDF



## Remote - SSH



# Clion



## Clion STM32-STM32Cube

> 确保已经完成了 STM32CubeIDE 的安装。

## Clion & STM32Cube（STM32CubeIDE）

- 安装 Clion、STM32CubeX（STM32CubeIDE）
- 编译环境
- 烧录环境
- 识别 stlink 驱动
- Clion 配置

每次用 Clion 烧录下载时，配置工程 cfg 文件，添加下面内容，改成（中间两行是新加的）：

```cpp
set FLASH_SIZE 0x20000

source [find interface/stlink.cfg]
transport select hla_swd

source [find target/stm32f1x.cfg]
```

```cpp
source [find interface/stlink.cfg]
transport select hla_swd
```

https://blog.csdn.net/Marslicy/article/details/132179588- 

https://blog.csdn.net/wv112406/article/details/131626594

https://www.stmcu.com.cn/Designresource/detail/software/711298?auto_download=1

## Clion 开发 ESP32



##PlatformIO



# Thonny

> Thonny 主要用于开发使用 MicroPython 框架的芯片（主要是 ESP32）。博主虽然只在少数时候使用此 IDE，不过它有时候，“只有它能做”，比如在使用 HomeAssistant 时，ESPHome 烧录 bin 时，使用它就非常便利。

- 官方下载：https://thonny.org/

## 安装 MicroPython 固件



## 配置 Thonny IDE 连接 ESP32

在 Thonny 中，点击**工具**>**解释器**，选择**MicroPython (ESP32)**，并选择与 ESP32 开发板连接的端口（Windows 下可能是`COM3`，macOS 或 Linux 上可能是`/dev/ttyUSB0`），点击 “确定” 完成连接。

## 编写与上传代码

**编写脚本**：在 Thonny 的代码编辑区编写 MicroPython 脚本，例如点亮 ESP32 上 LED 的代码：

```python
from machine import Pin
import time

led = Pin(2, Pin.OUT)

while True:
    led.value(1)  # 打开LED
    time.sleep(1)
    led.value(0)  # 关闭LED
    time.sleep(1)
```

**上传和运行代码**：点击 “运行” 按钮将代码上传并运行在 ESP32 上。若要让代码在每次启动时自动运行，将文件命名为`main.py`，Thonny 支持直接将代码保存到 ESP32 的文件系统。

