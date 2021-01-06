/********************************************* ESP32 GPIO INPUT PINS *************************************************
  We will show you how to use ESP32 GPIO pins as digital input pins in this ESP32 tutorial series and how to connect a push
  button with the ESP32 development board. The push button is used to control machinery when the push button is pressed or not,
  such as turning on and off a light emitting diode (LED).

  ESP32 can be attached to the push button either via the pull-up resistor or the pull-down resistor. When the push button is not
  pressed in the Pull up resistor mode, the input to the GPIO pin is logically high or vice versa.

  - When the push button is pressed in pull-down resistor mode, input to the GPIO pin will be low state logic and high state logic
    otherwise.

  - In pull-down resistor mode, when the push button is pressed, input to GPIO pin will be logic low state and otherwise logic
    high state.

  All GPIO pins have pull-up and pull-down resistor internally in the ESP32 except GPIO 34, 35, 36, 39 pins, 
  internal pull-down resistor only.

  You can connect 3.3V pin directly to emulate pushbutton pin, if you are using internal pull-up, wire with ground pin,
  for pull-down resistor, wire with 3.3V pin.

  *NOTE:
  If INPUT, GPIO 5 IS ALWAYS LOGIC HIGH
  If INPUT_PULLUP, GPIO 2 IS ALWAYS LOGIC LOW
  If INPUT_PULLDOWN, GPIO 5 IS ALWAYS LOGIC HIGH
***********************************************************************************************************************/

int GPIO_pins[] = {2, 4, 5, 12, 13, 14, 15, 16, 17, 18, 19, 21, 22, 23, 25, 26, 27, 32, 33, 34, 35, 36, 39};
int GPIO_count = (sizeof(GPIO_pins) / sizeof(GPIO_pins[0]));

void setup() {
  Serial.begin(115200);

  // This statement will declare GPIO as digital input
  // pinMode(pin, INPUT);

  // Configuration of the GPIO input pin with the internal pullup resistor:
  // pinMode(pin, INPUT_PULLUP);

  // Unlike the Arduino, on the ESP32 there are internal pulldown resistors in addition.
  // Configuration of the GPIO pin at the input with the internal pulldown resistor:
  // pinMode(pin, INPUT_PULLDOWN);

  for (int thisPin = 0; thisPin < GPIO_count; thisPin++) {
    // Input pin configuration: INPUT, INPUT_PULLUP, INPUT_PULLDOWN
    pinMode(GPIO_pins[thisPin], INPUT_PULLDOWN);
  }
}

void loop() {
  for (int thisPin = 0; thisPin < GPIO_count; thisPin++) {
    Serial.println("GPIO: " + String(GPIO_pins[thisPin]) + " Logic State: " + String(digitalRead(GPIO_pins[thisPin])));
  }
  Serial.println();
  Serial.println();
  delay(1000);
}
