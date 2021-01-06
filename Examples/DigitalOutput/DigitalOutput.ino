/********************************************* ESP32 GPIO OUTPUT PINS *************************************************
  The ESP32 chip comes with 48 pins with multiple functions. Not all pins are exposed in all ESP32 development boards,
  and there are some pins that cannot be used. ESP32 devkit has 36 pins and 18 on each side of the board. It has 34 GPIO
  pins and each pin has multiple functionalities which can be configured using specific registers.

  As it said, GPIO’s cannot be used freely, as they are already assigned to module peripherals or have special functions
  during booting:

  GPIO 0 pin is used as a bootstrapping pin, and should be low to enter UART download mode. Make sure it is not pulled
  low by a peripheral device during boot or the firmware will not start!

  GPIO 2 pin is used as a bootstrapping pin, and should be low to enter UART download mode. Make sure it is not pulled
  high by a peripheral device during boot or you will not be able to flash a firmware to the module!

  GPIO 12 is used as a bootstrapping pin to select output voltage of an internal regulator which powers the flash chip (VDD_SDIO).
  This pin has an internal pulldown so if left unconnected it will read low at reset (selecting default 3.3V operation).
  Make sure it is not pulled high by a peripheral device during boot or the module might not be able to start!

  GPIO 15 can be used to stop debug output on Serial during boot. If pulled low there will be no output on the Serial port during
  the boot process. This can be helpful in battery powered applications where you do not want to use the Serial port at all
  to reduce power consumption.

  GPIO 34-39 pins which can be used as digital input pins only. They cannot be configured as digital output pins.
  They do not have internally connected push pull resistors. They can only be used as digital input pins:
  GPIO 34
  GPIO 35
  GPIO 36
  GPIO 37 and 38 are not available on most boards
  GPIO 39

  GPIO 6 to GPIO 11 are exposed in some ESP32 development boards. However, these pins are connected to the integrated SPI
  flash on the ESP-WROOM-32 chip and are not recommended for other uses. So, don’t use these pins in your projects:
  GPIO 6 (SCK/CLK)
  GPIO 7 (SDO/SD0)
  GPIO 8 (SDI/SD1)
  GPIO 9 (SHD/SD2)
  GPIO 10 (SWP/SD3)
  GPIO 11 (CSC/CMD)

  Some GPIOs change its state to HIGH or output PWM signals at boot or reset. This means that if you have outputs
  connected to these GPIOs you may get unexpected results when the ESP32 resets or boots:
  GPIO 1
  GPIO 3
  GPIO 5
  GPIO 6 to GPIO 11 (connected to the ESP32 integrated SPI flash memory – not recommended to use).
  GPIO 14
  GPIO 15

  *Note:
  Connect LED to GPIO subject for testing
***********************************************************************************************************************/

int GPIO_pins[] = {2, 4, 5, 12, 13, 14, 15, 16, 17, 18, 19, 21, 22, 23, 25, 26, 27, 32, 33};
int GPIO_count = (sizeof(GPIO_pins) / sizeof(GPIO_pins[0]));

bool GPIOstate = false;

void setup() {
  Serial.begin(115200);
  for (int thisPin = 0; thisPin < GPIO_count; thisPin++) {
    pinMode(GPIO_pins[thisPin], OUTPUT);
  }
}

void loop() {
  static unsigned long timer = millis();
  if (millis() - timer > 1000) {
    timer = millis();
    GPIOstate = !(GPIOstate);
    
    for (int thisPin = 0; thisPin < GPIO_count; thisPin++) {
      Serial.println("GPIO: " + String(GPIO_pins[thisPin]) + " Logic State: " + String(GPIOstate));
      digitalWrite(GPIO_pins[thisPin], GPIOstate);
    }
  }
}
