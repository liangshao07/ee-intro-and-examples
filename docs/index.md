# What need to learn about ME, EE, and CS

# 全局概念简述

- ME：机械工程、机械结构
- EE：电子工程、电子硬件
- CS：计算机科学、软件工程

制作一个基本的电子产品，大致包含以上的三大领域，分别设计电子产品的结构、硬件和软件。更直接一点的说，外壳、电路、控制 APP。

# 产品设计

## 想法

- 记录：备忘录、语音备忘录、笔纸
- 思考：幕布、Notability、Goodnotes、笔纸
- 整理：Notion
- 学习使用
    - 入门，B 站直接搜教程，找播放量高的看
    - 提高，官网的文档

## “原型”

- 手画线框图：笔纸、Procreate
- 电子线框图：Figma
- 结构草图：Shapr3D、Fusion 360、TinkerCAD
- 电路实物图
    - frizing：跨平台画实物图
    - TinkCAD：Arduino实物图及仿真，简单3D建模等
    - 其它
- 学习使用
    - 入门，B站直接搜教程，找播放量高的看
    - 提高，官网的文档

## 设计

- 协作与整理：飞书、幕布、Notion
- UI/UX：Figma
- 电路板（PCB）：嘉立创 EDA
- 结构：Shapr3D、Fusion 360、TinkCAD
- 其它
    - 图像：PS、AI
    - ……
- 学习使用
    - 入门，B站直接搜教程，找播放量高的看
    - 提高，官网的文档

## 渲染

- 简单渲染：Shapr3D、Fusion 360
- 复杂渲染：Blender……
- 学习使用
    - 入门，B站直接搜教程，找播放量高的看
    - 提高，官网的文档

## 打样

- 3D 打印机：拓竹（Bamboo）几乎垄断消费级市场
- 3D 打印切片软件：Bamboo Studio
- 学习使用
    - 入门，B站直接搜教程，找播放量高的看
    - 提高，官网的文档

## EE 硬件开发、软件开发↓

# EE

## 硬件开发平台

### 系统

- Windows
- MacOS、Linux

> 原来🤡竟是 Windows，最大的自适应竟是 Windows。——Liang

> MacOS、Linux 原生终端直接调试串口。

- 学习使用
    - Windows平台，B 站直接搜教程
    - Mac Linux平台，等Liang整理好文档

### 平台

- Arduino：最佳入门和中小型项目
- Raspberry Pi：学习和实验
- ESP32：国产和WiFi物联网的最佳选择
- STM32：任何情况下都是好选择
- **PlatformIO：将其它平台聚合，省去配环境**
- 物联网平台
    - 米家
    - HomeKit

### 框架

- 跨平台（核心）
    - Arduino：Arduino 硬件、ESP32、STM32……（几乎所有）
    - MicroPython：ESP32、Raspberry Pi
    - 芯片自家框架
        - STM32Cube
        - ESP-IDF
- 其它（其它芯片家、keli5 MDK 等）

> 稚晖君，采用的是，Clion + STM32CubeX 和 VSC + PlatformIO 黑人黑科技，采用的是，Arduino IDE 和 VSC + Arduino 插件 B 站 热门的麦金塔、串口助手项目，采用的是，VSC + PlatformIO（MacOS）

### IDE

- Arduino IDE
    - Arduino、ESP32、STM32 等
- Thonny
    - Raspberry Pi 系统里编写，VNC 连接编写
    - ESP32
- VS code：中大型项目，免费，已经足够智能强大
    - **PlatformIO：几乎所有框架、芯片平台**
    - Remote - SSH：远程开发 Raspberry Pi
    - 其它芯片家插件
- Clion：中大型项目，更加智能的代码提示，体验感好
    - **PlatformIO：几乎所有框架、芯片平台**
    - STM32CubeX 创建框架，Clion 编写代码

### EDA

- 嘉立创 EDA：最佳
- AD
- 其它（企业才会使用的）
- 学习使用
    - 入门，直接看B站 嘉立创EDA 的视频教程
    - 提高，抄板和学习电路理论

## 烧录

- USB to TTL
    - 下载芯片，USB to microUSB 直连开发板下载
        - 注意：只支持 USB to microUSB/type C，C to C 需要更加高级的硬件支持
    - ch340
    - cp2102
    - ……
- J-link
- DAP-link
    - 稚晖君的 link 便是基于 DAP 的
- ST-link

## 调试

- 万用表
- 示波器
- 数控电源

## 上位机调试

### 电脑

- 串口调试
- 蓝牙调试
- 网络调试
- 开发
    - pyside6：QT 的 Python 官方库
    - 企业级开发 Java 一条龙

### 手机

- 串口调试
- 蓝牙调试
- 网络调试
- 开发
    - MIT
    - Android
    - iOS
    - 企业级开发 Java 一条龙

## 加工

### 焊接

- 焊锡丝
- 焊锡膏
- 电烙铁
- 热风枪
- 加热焊台

### 机械加工

- 其它参考 ME
- 镊子
- 热熔胶
- 热缩管

# ME

## 机械结构设计

- 嘉立创 EDA
- Fusion 360
- Shapr3D

## 3D 打印

- 拓竹 3D 打印机
- 模型网站
