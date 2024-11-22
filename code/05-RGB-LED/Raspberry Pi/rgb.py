from gpiozero import RGBLED
from time import sleep

led = RGBLED(red=9, green=10, blue=11)

led.red = 1  # full redsleep(1)
led.red = 0.5  # half redsleep(1)

led.color = (0, 1, 0)  # full greensleep(1)
led.color = (1, 0, 1)  # magentasleep(1)
led.color = (1, 1, 0)  # yellowsleep(1)
led.color = (0, 1, 1)  # cyansleep(1)
led.color = (1, 1, 1)  # whitesleep(1)

led.color = (0, 0, 0)  # offsleep(1)

# slowly increase intensity of bluefor n in range(100):
    led.blue = n/100
    sleep(0.1)