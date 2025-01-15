# ESP32-UDP-LED

# Arduino API

## ESP32-DevKitC

```arduino

```

# MicroPython API

## ESP32-DevKitC

```python
"""
ESP32 UDP 控制 LED

此代码演示了如何使用 MicroPython 将 ESP32 连接到指定的 Wi-Fi 网络，并通过 UDP 协议接收网络数据来控制连接到 GPIO2 引脚的 LED 的开关状态。

电路连接：
- LED 阳极（较长的一脚）连接到 GPIO2。
- LED 阴极（较短的一脚）通过一个 330Ω 电阻连接到 GND。

电路图：
    ESP32          LED
   ---------      -----
  |         |    |     |
  |    2    |----|>|---+---- GND
  |         |    (Anode) (Cathode)
  |         |  (通过 330Ω 电阻)
  |         |  
  |         |  

创建于 2024
作者：Liang
"""

import socket
import time
import network
import machine

# 配置 Wi-Fi SSID 和密码
WIFI_SSID = "Wokwi-GUEST"
WIFI_PASSWORD = ""

# 初始化 LED 引脚
led = None

def do_connect():
    """
    连接到指定的 Wi-Fi 网络。
    
    返回:
        bool: 如果连接成功返回 True，否则返回 False。
    """
    wlan = network.WLAN(network.STA_IF)
    wlan.active(True)
    if not wlan.isconnected():
        print('正在连接到网络...')
        wlan.connect(WIFI_SSID, WIFI_PASSWORD)
        i = 1
        while not wlan.isconnected():
            print("正在链接...{}".format(i))
            i += 1
            time.sleep(1)
    print('网络配置:', wlan.ifconfig())
    return True

def start_udp():
    """
    启动 UDP 服务并绑定端口。
    
    返回:
        socket: 创建并绑定的 UDP 套接字。
    """
    # 创建 UDP 套接字
    udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    # 绑定本地信息
    udp_socket.bind(("0.0.0.0", 7788))
    print("UDP 服务器已启动，监听端口 7788")
    return udp_socket

def handle_data(data, sender_info):
    """
    处理接收到的数据并控制 LED。
    
    参数:
        data (str): 接收到的数据字符串。
        sender_info (tuple): 发送者的地址和端口。
    """
    global led
    print("{} 发送: {}".format(sender_info, data))
    
    if data == "light on":
        print("灯亮...")
        led.value(1)
    elif data == "light off":
        print("灯灭...")
        led.value(0)
    else:
        print("无效命令")

def main():
    """
    主函数，连接到 Wi-Fi 并启动 UDP 服务，接收并处理数据。
    """
    global led
    
    # 1. 连接到 Wi-Fi
    if not do_connect():
        print("无法连接到 Wi-Fi 网络，请检查 SSID 和密码。")
        return
    
    # 2. 创建 UDP 服务
    udp_socket = start_udp()
    
    # 3. 初始化 LED 引脚
    led = machine.Pin(2, machine.Pin.OUT)
    led.value(0)  # 初始关闭 LED
    
    # 4. 接收并处理网络数据
    while True:
        try:
            recv_data, sender_info = udp_socket.recvfrom(1024)
            recv_data_str = recv_data.decode("utf-8")
            handle_data(recv_data_str, sender_info)
        except Exception as e:
            print("发生错误:", e)

if __name__ == "__main__":
    main()
```

# ESP-IDF API

## ESP32-DevKitC

```c

```