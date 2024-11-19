# STM32 Blue Pill（STM32F103C8T6）

##### 相关

> For more insights about the technical specifcations refer to the [official datsheet](https://www.st.com/resource/en/datasheet/stm32f103c8.pdf) and [reference manual](https://www.st.com/content/ccc/resource/technical/document/reference_manual/59/b9/ba/7f/11/af/43/d5/CD00171190.pdf/files/CD00171190.pdf/jcr:content/translations/en.CD00171190.pdf) by STMicroelectronics.
>
> - https://stm32-base.org/boards/STM32F103C8T6-Blue-Pill.html#USB-connector
> - [Schematic](https://stm32-base.org/assets/pdf/boards/original-schematic-STM32F103C8T6-Blue_Pill.pdf)
> - [3D printable mount](https://www.thingiverse.com/thing:4061855)

![STM32 Blue Pill-1](../images/STM32 Blue Pill-1.png)

![STM32 Blue Pill-2](../images/STM32 Blue Pill-2.png)

## Naming Convention of STM microcontrollers

| **Parameter** | **Meaning**                                   |
| ------------- | --------------------------------------------- |
| STM           | name of the manufacturer (STMicroelectronics) |
| 32            | 32 bit ARM architecture                       |
| F             | Foundation                                    |
| 1             | Core (ARM Cortex M3)                          |
| 03            | Line (describes peripherals and speed)        |
| C             | 48 pins                                       |
| 8             | 64 KB flash memory                            |
| T             | LQFP package (Low Profile Quad Flat Pack)     |
| 6             | Operating Temperature Range (-40 °C to 85 °C) |

## Technical Specifications of STM32

| **Parameter**       | **Meaning**            |
| ------------------- | ---------------------- |
| Architecture        | 32 bit ARM Cortex M3   |
| Operating Voltage   | 2.7V to 3.6V           |
| CPU Frequency       | 72 MHz                 |
| Number of GPIO pins | 37                     |
| Number of PWM pins  | 12                     |
| Analog Input Pins   | 10 (12 bit resolution) |
| I2C Peripherals     | 2                      |
| SPI Peripherals     | 2                      |
| CAN 2.0 Peripheral  | 1                      |
| Timers              | 3(16-bit), 1           |
| Flash Memory        | 64KB                   |
| RAM                 | 20kB                   |

## **User LED**

| **Name**         | PC13 |
| ---------------- | ---- |
| **Reference**    | -    |
| **Type**         | LED  |
| **Connected to** | PC13 |
| **Mode**         | Sink |

## **SWD header pins**

| **#** | **Name** | **Function** | **Connected to** |
| ----- | -------- | ------------ | ---------------- |
| 1     | 3V3      | VCC          | +3.3V rail       |
| 2     | DIO      | SWDIO        | PA13             |
| 3     | CLK      | SWCLK        | PA14             |
| 4     | GND      | GND          | Ground plane     |

# Other

- **Trivia:** This board got its name from a forum post at the STM32duino forums and is a reference to the movie [The Matrix](https://www.imdb.com/title/tt0133093/).

