# IDE 的选择

- Arduino IDE

    - Arduino、ESP32、STM32 等，基本主流开发板都支持

- Thonny

    - Raspberry Pi 系统自带的 IDE，可在树莓派系统里编写，VNC 连接编写

    - ESP32 MicroPython 框架支持极好

- VS code：中大型项目，免费，已经足够智能强大

    - PlatformIO：几乎所有框架、芯片平台

    - Remote - SSH：远程开发 Raspberry Pi

    - 其它芯片家插件

- Clion：中大型项目，更加智能的代码提示，体验感好

    - PlatformIO：几乎所有框架、芯片平台

    - STM32Cube 创建框架，Clion 编写代码

## PlatformIO



### 指定 ESP32 开发框架版本

https://blog.csdn.net/kzc1209/article/details/134851444

[https://zhuanlan.zhihu.com/p/509239765#:~:text=在esp32的更新日志中，可以看到，只需在platformio.ini中添加platform %3D espressif32 %40~xxx，即可指定包版本。 我的工程是基于esp32,3.5.0版本开发，所以用platform %3D espressif32 %40~3.5.0来替代原来的platform %3D espressif32，重新编译，就能编译成功。](https://zhuanlan.zhihu.com/p/509239765#:~:text=在esp32的更新日志中，可以看到，只需在platformio.ini中添加platform %3D espressif32 @~xxx，即可指定包版本。 我的工程是基于esp32,3.5.0版本开发，所以用platform %3D espressif32 @~3.5.0来替代原来的platform %3D espressif32，重新编译，就能编译成功。)

我这里选择了最新版本6.4.0，只需要在**platformio.ini** 文件中将platform = espressif32修改为platform = espressif32@^6.4.0后按下ctrl+s等待他下载完成即可

```arduino
platform = espressif32@^2.0.04
```