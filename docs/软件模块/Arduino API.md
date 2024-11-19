# Arduino API

##### 相关

> - 官网 API 文档：https://docs.arduino.cc/language-reference/#functions
>     - 另一个 UI 形式：https://www.arduino.cc/reference/en/
> - Arduino 开源平台：https://projecthub.arduino.cc/

## 优质教程

【【中英字幕】油管大神Arduino基础课程】 https://www.bilibili.com/video/BV1k64y1u75j/?share_source=copy_web&vd_source=0152764925b99fadd2e9e3592e9421a8

【【太极创客】零基础入门学用Arduino 第一部分 合辑】 https://www.bilibili.com/video/BV164411J7GE/?share_source=copy_web&vd_source=0152764925b99fadd2e9e3592e9421a8

# 什么是 Arduino

Arduino 是一个基于易用硬件和软件的开源电子平台。

Arduino 诞生于伊夫雷亚交互设计学院，原本是一种便于快速制作原型的简易工具，面向那些没有电子学和编程背景的学生。当它进入更广泛的群体后，Arduino 开发板便开始做出改变以适应新的需求和挑战，其产品从简单的 8 位开发板拓展到适用于物联网应用、可穿戴设备、3D 打印以及嵌入式环境等领域的各类产品。

得益于其简单易用、容易上手的用户体验，Arduino 已被应用于数千个不同的项目和应用场景中。Arduino 软件对于初学者来说易于使用，对高级用户而言又有足够的灵活性。它可在 Mac、Windows 和 Linux 系统上运行。教师和学生用它来制作低成本的科学仪器，验证化学和物理原理，或者开启编程和机器人学的学习之旅。设计师和建筑师用它构建互动式原型，音乐家和艺术家利用它进行装置艺术创作以及尝试新乐器的研发。当然，创客们也用它来打造许多在创客节上展出的项目。Arduino 是学习新知识的关键工具。任何人 —— 儿童、业余爱好者、艺术家、程序员 —— 都可以按照套件的分步说明开始动手实践，或者在线与 Arduino 社区的其他成员分享想法。

- **价格低廉**—— 与其他微控制器平台相比，Arduino 开发板的价格相对便宜。Arduino 模块最便宜的版本可以手工组装，而且即便是预先组装好的 Arduino 模块，其售价也低于 50 美元。
- **跨平台**——Arduino 软件（集成开发环境，即 IDE）可在 Windows、Macintosh OSX 以及 Linux 操作系统上运行。大多数微控制器系统仅限于在 Windows 系统上使用。
- **编程环境简单明了**——Arduino 软件（IDE）对初学者来说易于使用，同时也足够灵活，便于高级用户充分利用。对于教师来说，它基于 Processing 编程环境，便于操作，所以在该环境中学习编程的学生将会熟悉 Arduino IDE 的工作原理。
- **开源且可扩展的软件**——Arduino 软件是以开源工具的形式发布的，可供有经验的程序员进行扩展。该语言可通过 C++ 库进行扩展，而且想要了解技术细节的人可以从 Arduino 过渡到其基于的 AVR C 编程语言。同样，如果你愿意，也可以直接将 AVR-C 代码添加到你的 Arduino 程序中。
- **开源且可扩展的硬件**——Arduino 开发板的设计方案是依据知识共享许可协议发布的，所以有经验的电路设计师可以制作自己版本的模块，对其进行扩展和改进。即便是相对缺乏经验的用户也可以搭建[模块的面包板版本](https://www.arduino.cc/en/Main/Standalone)，以便了解其工作原理并节省开支。

# Arduino API 开发 STM32

- 官方 GitHub：https://github.com/stm32duino
- 官网：https://www.stm32duino.com/

完全可行，2019 起，这方面的信息较少，也对得上官方首推自家框架。

- Arduino 框架优势在于，可以使用 arduino 的众多库；

- 劣势在于，对 STM32 的一些高级功能使用受限，或者极其麻烦。

虽然可以使用 Arduino IDE，但不太好用、不太方便，还是使用 VSC + PIO 方式开发。

- See [Supported boards](https://github.com/stm32duino/Arduino_Core_STM32/#supported-boards) section of the [Arduino_Core_STM32/README.md](https://github.com/stm32duino/Arduino_Core_STM32/#readme).
- See [API](https://github.com/stm32duino/Arduino_Core_STM32/wiki/API) references for usage of accessing the hardware with the Arduino API-functions.



参考：

https://stm32-base.org/boards/STM32F103C8T6-Blue-Pill#Header-1

https://shequ.stmicroelectronics.cn/thread-635406-1-1.html

https://blog.csdn.net/u012388993/article/details/102459027

特殊下载脚

https://github.com/stm32duino/Arduino_Core_STM32/issues/1197

https://github.com/orgs/stm32duino/discussions/1671

https://www.stm32duino.com/viewtopic.php?t=713

https://www.stm32duino.com/viewtopic.php?t=292

https://cloud.tencent.com/developer/article/2165360
