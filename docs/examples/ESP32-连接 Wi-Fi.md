# ESP32-连接 Wi-Fi

# Arduino API

## ESP32-DevKitC

```arduino

```

# MicroPython API

## ESP32-DevKitC

```python
"""
ESP32 Wi-Fi Connection

此代码演示了如何使用 MicroPython 将 ESP32 连接到指定的 Wi-Fi 网络。

创建于 2024
作者：Liang
"""

import network
import time

# 配置 Wi-Fi SSID 和密码
WIFI_SSID = "your_wifi_ssid"
WIFI_PASSWORD = "your_wifi_password"

# 初始化 Wi-Fi 接口
wlan = network.WLAN(network.STA_IF)

def connect_to_wifi():
    """
    连接到指定的 Wi-Fi 网络。
    
    返回:
        bool: 如果连接成功返回 True，否则返回 False。
    """
    # 激活接口
    wlan.active(True)
    # 连接到 Wi-Fi 网络
    wlan.connect(WIFI_SSID, WIFI_PASSWORD)
    
    # 等待连接
    timeout = 10  # 设置超时时间（秒）
    start_time = time.time()
    while not wlan.isconnected() and (time.time() - start_time) < timeout:
        print("正在连接到 Wi-Fi...")
        time.sleep(1)
    
    if wlan.isconnected():
        print("Wi-Fi 连接成功！")
        print("网络配置:", wlan.ifconfig())
        return True
    else:
        print("Wi-Fi 连接失败！")
        return False

def main():
    """
    主函数，尝试连接到 Wi-Fi 并处理结果。
    """
    if connect_to_wifi():
        print("已成功连接到 Wi-Fi 网络。")
    else:
        print("无法连接到 Wi-Fi 网络，请检查 SSID 和密码。")

# 调用主函数开始执行
main()
```

# ESP-IDF API

## ESP32-DevKitC

```c

```

# 原理

# **1. 设置工作模式**

`Wi-Fi`是基于`IEEE 802.11`标准的无线网络技术 让联网设备以无线电波的形式，加入采用`TCP/IP`通信协议的网络

`Wi-Fi`网络环境通常有两种设备

- Access Point(`AP`) 无线接入点，提供无线接入的设备，家里的光猫就是结合WiFi和internet路由功能的AP。AP和AP可以相互连接。
- Station(`STA`) 无线终端，连接到AP的装置，手机，电脑等需要联网的设备都是出于STA模式，这个模式不允许其他设备接入

# **3. SSID**

**BSSID**就是无线路由器的MAC地址（本质是**一个MAC地址**）

**SSID**就是手机上搜索到的wifi名字（本质是**一串字符**）

**ESSID**是一个比较抽象的概念，它实际上就和ssid相同（本质也是**一串字符**）。如果有好几个无线路由器都叫这个名字，那么我们就相当于把这个ssid**扩大**了，所以这几个无线路由器共同的这个名字就叫ESSID

打个比方：

- SSID就好比是每个连锁店的门口**招牌**上写的字（例如：阿迪达斯）
- ESSID就是连锁店的牌子（例如：阿迪达斯）
- BSSID就是每个连锁店的地址（比如万达广场店，襄阳路店）

连锁店的品牌名与写到招牌上的名就相当于ESSID和SSID

- 当前的`ESP32`不支持`5G`路由器，所以链接的时候要注意这一点，否则连不上
- 可以将自己的手机开热点让`ESP32`链接