# ESP-WROOM-32 (30P)

48 pins with different functions come with the ESP32 chip. However, not all pins are suitable for use in Devkit. There are also concerns about how to use the GPIOs for the ESP32. What pins are you going to use? What pins in your projects can you avoid using? The goal of this repo is to be a quick and easy reference guide for the ESP32 GPIOs to follow. If you're familiar with ESP8266, its successor is ESP32. ESP32 is a low-cost, low-power 32-bit dual-core microcontroller incorporates wireless WiFi and Bluetooth capabilities created by Espressif Systems. The ESP32 has developed a reputation as the ultimate chip or module for hobbyists and IoT developers, most frequently designed for handheld devices, wearable technology, and IoT applications.

Here’s a high-level summary of the features and specifications of the ESP32:
| ESP32  | Specifications |
| ------------- | ------------- |
| Core  | 2  |
| Architecture  | 32-bit  |
| Clock  | 160MHZ, up to 240MHz  |
| Bluetooth  | Classic & BLE 4.2  |
| Wi-Fi  | TCP/IP, full 802.11 b/g/n/e/i WLAN MAC protocol  |
| RAM  | 512 KB  |
| Flash  | 4MB, up to 16MB  |
| Peripherals  | ADC,DAC,PWM,UART,SPI,I2C,I2S,CAN,Capacitive GPIO...  |

We're going to use the ESP32 DEVKIT DOIT board as shown in the figure below, as a guide for this repo. But the information on this page is also compatible with the [ESP-WROOM-32](https://github.com/TronixLab/DOIT_ESP32_DevKit-v1_30P/blob/main/Docs/ESP-WROOM-32-DATASHEET.pdf) chip for other ESP32 development boards. The ESP32 devkit uses the module ESP-WROOM-32. But across all ESP32 development boards, the functionality of all GPIO pins is the same.

![alt text](https://startingelectronics.org/articles/ESP32-WROOM-testing/doit-esp-wroom-32-devkit.jpg)

About this development board, I see many people searching online. Are there several individuals asking questions about how to use their GPIO pins? What GPIO pin is a digital input-output pin that can be used? What GPIO pin is an analog pin that can be used? And which pin should not be used in order to safely use this board? In this post, you will get the answer to these questions. You will get the answer to these questions in this repo.

![alt text](https://github.com/TronixLab/DOIT_ESP32_DevKit-v1_30P/blob/main/Docs/DOIT_ESP32-DevkitV1_PINOUT.png?raw=true)

The image above explains all of this board's pins (version with 30 GPIOs). The chip that is used with the board has 48 GPIO pins, as I described earlier. But through these development boards, we cannot use all the pins. As seen in the image above, the ESP32 devkit has 30 pins and 15 on each side of the board, each GPIO pin has several functionalities that can be configured using specific registers. There are many types of GPIOs available, such as digital input, digital output, analog input, analog output, capacitive contact, communication with UART, and many other features mentioned above.

## ESP32 Peripherals
* 18 Analog-to-Digital Converter (ADC) channels
* 3 SPI interfaces
* 3 UART interfaces
* 2 I2C interfaces
* 16 PWM output channels
* 2 Digital-to-Analog Converters (DAC)
* 2 I2S interfaces
* 10 Capacitive sensing GPIOs

### Digital input GPIO pins
It has 6 GPIO pins that can only be used as digital input pins. It is not possible to configure them as digital output pins. Therefore, they do not have internal push-pull resistors attached to them. It is only possible to use them as digital input pins.
* GPIO34
* GPIO35
* GPIO36
* GPIO37
* GPIO38
* GPIO39

**Note:** *The maximum operating current which GPIO pins can sink and source is 40mA according to the datasheet of ESP32 chip. But it is recommended to keep it below 20mA.*
