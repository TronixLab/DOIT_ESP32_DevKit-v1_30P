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
* 4 SPI interfaces
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

Some GPIOs called *strapping pins* change their status at boot or reset to HIGH or output PWM signals. This implies that when the ESP32 resets or boots, if you have outputs connected to these GPIOs, you can get unexpected results.
* GPIO 1
* GPIO 3
* GPIO 5
* GPIO 6 to GPIO 11 (connected to the ESP32 integrated SPI flash memory – not recommended to use).
* GPIO 14
* GPIO 15

GPIO 6 to GPIO 11 are exposed in some ESP32 development boards. However, these pins are connected to the integrated SPI flash on the ESP-WROOM-32 chip and are not recommended for other uses. So, don’t use these pins in your projects.
* GPIO 6 (SCK/CLK)
* GPIO 7 (SDO/SD0)
* GPIO 8 (SDI/SD1)
* GPIO 9 (SHD/SD2)
* GPIO 10 (SWP/SD3)
* GPIO 11 (CSC/CMD)

These are used to bring the ESP32 into the flashing mode or bootloader. You need not worry about the condition of these pins on most development boards with built-in USB/Serial. For flashing or boot mode, the board puts the pins in the right state. However, you may have difficulty trying to upload new code, flashing the ESP32 with new firmware or resetting the board if you have peripherals attached to those pins. If you have any peripherals linked to the strapping pins and you are having trouble uploading code or flashing the ESP32, it could be because the ESP32 is prevented from accessing the correct mode by those peripherals. In order to lead you in the right direction, read the [Boot Mode Selection documentation](https://github.com/espressif/esptool/wiki/ESP32-Boot-Mode-Selection). Those pins function as planned after resetting, blinking, or booting.

All GPIO pins have pull-up and pull-down resistor internally in the ESP32 except GPIO 34, 35, 36, 39 pins, internal pull-down resistor only.

**NOTES:**
* *If INPUT, GPIO 5 is always logic high*, 
* *If INPUT_PULLUP, GPIO 2 is always logic low*, 
* *If INPUT_PULLDOWN, GPIO 5 is always logic high.*

### Interrupts 
All above-mentioned GPIO pin can be configured in interrupt mode. Interrupt configuration is the same with using of [Arduino library](https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/).

### Analog GPIO pins (ADC)
There are 18 ADC channels supported by this development board. And each channel has 12 bits. And there's a better resolution there. Analog voltage, current and any analog sensor that provides output in the form of analog voltage can be calculated using it. These are the GPIOs that can be used as ADC and respective channels.
* ADC1_CH0 (GPIO 36)
* ADC1_CH1 (GPIO 37)
* ADC1_CH2 (GPIO 38)
* ADC1_CH3 (GPIO 39)
* ADC1_CH4 (GPIO 32)
* ADC1_CH5 (GPIO 33)
* ADC1_CH6 (GPIO 34)
* ADC1_CH7 (GPIO 35)
* ADC2_CH0 (GPIO 4)
* ADC2_CH1 (GPIO 0)
* ADC2_CH2 (GPIO 2)
* ADC2_CH3 (GPIO 15)
* ADC2_CH4 (GPIO 13)
* ADC2_CH5 (GPIO 12)
* ADC2_CH6 (GPIO 14)
* ADC2_CH7 (GPIO 27)
* ADC2_CH8 (GPIO 25)
* ADC2_CH9 (GPIO 26)

The ability to read a voltage level found on a pin between 0 and a certain maximum value and convert that analog value into a digital representation is an analog to digital conversion. The value read can change by varying the voltage applied to the pin. With a resolution of up to 12 bits, which is 4096 different values, the ESP32 has an analog to digital converter built into it. What that means is that 0 volts will create a digital value of 0, while a digital value of 4095 will be produced by the highest voltage (3.3V) and a correspondingly scaled digital value will be generated by the voltage ranges between these.

**NOTE:** *When Wi-Fi is used, ADC2 pins cannot be used. So, if you're using Wi-Fi and you're having trouble getting the value from an ADC2 GPIO, instead of using an ADC1 GPIO, the problem should be solved.*

### Analog to Digital GPIO pins (DAC)
There are two 8-bit integrated onboard DACs on this development board. In order to transform digital signals into analog signals, DACs are used. DACs have many uses, such as control of voltage and control of PWM. These are the DAC channels:
* DAC1 (GPIO25)
* DAC2 (GPIO26)

### Pulse Width Modulation GPIO pins (PWM)
There are 16 independent channels in the ESP32 LED PWM controller that can be programmed to generate PWM signals with various properties. As PWM pins, all pins that can act as outputs can be used (PWM can not be created by input only pin GPIOs 34 to 39). 

You need to specify these parameters in the code:
* Signal’s frequency,
* Duty cycle,
* PWM channel,
* GPIO where you want to output the signal.

### Real-Time Clock GPIO pins (RTC)
On the ESP32, there is RTC GPIO support. When the ESP32 is in a deep sleep, the GPIOs routed to the RTC low-power subsystem can be used. When the Ultra Low Power (ULP) co-processor is operating, these RTC GPIOs can be used to wake the ESP32 up from deep sleep. As an external wake up source, the following GPIOs can be used.
* RTC_GPIO0 (GPIO36)
* RTC_GPIO3 (GPIO39)
* RTC_GPIO4 (GPIO34)
* RTC_GPIO5 (GPIO35)
* RTC_GPIO6 (GPIO25)
* RTC_GPIO7 (GPIO26)
* RTC_GPIO8 (GPIO33)
* RTC_GPIO9 (GPIO32)
* RTC_GPIO10 (GPIO4)
* RTC_GPIO11 (GPIO0)
* RTC_GPIO12 (GPIO2)
* RTC_GPIO13 (GPIO15)
* RTC_GPIO14 (GPIO13)
* RTC_GPIO15 (GPIO12)
* RTC_GPIO16 (GPIO14)
* RTC_GPIO17 (GPIO27)

### Capacitive Touch GPIO pins
On board, 10 capacitive touch sensors are provided by ESP-WROOM-32. So while you are using this development board, you don't need to use separate touch sensors in your project. Like magnetic field detection, these capacitive touch sensors can be used to detect any electrical and magnetic waves around them. With these touch controls, you can use a small array of pads rather than push buttons. Those internal touch sensors are connected to these GPIOs:
* T0 (GPIO 4)
* T1 (GPIO 0)
* T2 (GPIO 2)
* T3 (GPIO 15)
* T4 (GPIO 13)
* T5 (GPIO 12)
* T6 (GPIO 14)
* T7 (GPIO 27)
* T8 (GPIO 33)
* T9 (GPIO 32)

### Built-In Hall Effect Sensor
The development board of the ESP32 features an integrated hall effect sensor that senses changes in its surroundings in the magnetic field. ESP32 produces a small voltage which can be calculated if you want this development board in the magnetic field.

### Inter-IC Communication pins (I2C)
For two-wire I2C communication, it has dedicated pins available. For data transfer, one pin is used and another pin for clock synchronization is used. When using the ESP32 with the Arduino IDE, you should use the ESP32 I2C default pins (supported by the Wire library):
* GPIO21 (SDA)
* GPIO22 (SCL)

**Note:** *In many breakout boards, the SDA line may also be labeled as SDI and the SCL line as SCK.*

### Serial Peripheral Interface GPIO pins (SPI)
SPI Master driver is a program that controls ESP32’s SPI peripherals while they function as masters. ESP32 integrates four SPI peripherals. SPI0 and SPI1 are used internally to access the ESP32’s attached flash memory. SPI2 and SPI3 are general purpose SPI controllers, sometimes referred to as HSPI and VSPI, respectively. They are open to users. SPI2 and SPI3 have independent signal buses with the same respective names. By default, the pin mapping for SPI is:
| SPI  | MOSI | MISO | CLK | CS |
| ------------- | ------------- | ------------- | ------------- | ------------- |
| **VSPI**  | GPIO 23  | GPIO 19 | GPIO 18 | GPIO 5 |
| **HSPI**  | GPIO 13  | GPIO 12 | GPIO 14 | GPIO 15 |


### Inter-IC Sound pins (I2S)
It is a serial, synchronous communication protocol that is usually used for transmitting audio data between two digital audio devices. ESP32 includes two peripherals for I2S serial communication. The I2S is used to send and receive audio between two Audino units. In a half-duplex communication mode, each I2S controller works. But to achieve full-duplex communication, we should combine these two available controllers. I2S0 output can be routed directly to the digital-to-analog converter’s (DAC) output channels (GPIO25 & GPIO26) to produce direct analog output without involving any external I2S codecs.

### Universal Asynchronous Receiver/Transmitter GPIO pins (UART)
There are three serial ports on the ESP32 known as U0UXD, U1UXD and U2UXD all work at 3.3V TTL Level. There are three hardware supported serial interfaces on the ESP32 known as UART0, UART1 and UART2. 
First Serial RX0, TX0 is used for programming,
* GPIO3 (U0RXD)
* GPIO1 (U0TXD)
Another Serial port is available on
* GPIO16 (U2RXD)
* GIIO17 (U2TXD)
When programming it is named as Serial2.

