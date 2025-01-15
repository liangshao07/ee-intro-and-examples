# Matlab API

- Matlab 交互命令和 m 文件：只能串口连接硬件运行代码，无法下载烧录代码进入硬件
- Matlab Simulink：通过框图仿真，可以将代码烧录进硬件

## MATLAB 交互命令和 m 文件控制 Arduino 硬件

☀️ MATLAB 提供了强大的 Arduino 硬件支持包，让我们能够通过简单的命令和程序直接控制 Arduino 开发板。

## 准备工作

- 安装 MATLAB 支持包：在 MATLAB 中使用 supportPackageInstaller 安装 Arduino 包
- 安装 Arduino IDE：用于驱动和固件更新
- 准备 Arduino 板：推荐使用 Arduino UNO 或 MEGA 开发板
- 连接硬件：使用 USB 线缆连接电脑和 Arduino

## 基础命令控制

```matlab
% 创建 Arduino 对象
a = arduino()

% LED 控制（数字输出）
writeDigitalPin(a, 'D13', 1);  % 打开板载 LED
writeDigitalPin(a, 'D13', 0);  % 关闭板载 LED

% 读取数字输入
value = readDigitalPin(a, 'D2');

% 模拟输入读取
voltage = readVoltage(a, 'A0');

% PWM 输出控制
writePWMVoltage(a, 'D3', 2.5);
```

## 使用 m 文件编程

```matlab
function arduino_blink()
    % 创建 Arduino 连接
    a = arduino();
    
    % 循环闪烁 LED
    for i = 1:10
        writeDigitalPin(a, 'D13', 1);
        pause(0.5);
        writeDigitalPin(a, 'D13', 0);
        pause(0.5);
    end
    
    clear a
end
```

## 注意事项

- 及时清理对象：使用完毕后用 clear 释放 Arduino 连接
- 检查端口冲突：确保端口未被其他程序占用
- 注意电压限制：模拟输入电压不要超过 5V
- 合理使用延时：避免过于频繁的数据读写操作