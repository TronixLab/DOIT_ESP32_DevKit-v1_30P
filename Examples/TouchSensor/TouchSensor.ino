/********************************************* ESP32 TOUCH SENSOR *********************************************
   In this tutorial, you will learn how to use the ESP32 Touch Sensor Development Board
   and how to use the esp32 Touch Sensor as a pushbutton without the need to attach an
   external pushbutton. The ESP32 chip includes a 10 touch sensor. These touch sensors
   are built into an ESP32 chip. These touch sensors are a capacitive type of sensor.
   These touch sensors are shared with the ESP32 GPIO pins.

   Electrical changes to the respective GPIO pins can be sensed by the capacitive sensor.
   For instance, if you touch either of these pins, the GPIO pin will produce the electrical
   charge output on your finger. Since there is also some electrical charge retained by the
   human body. These touch sensors are, thus, also known as capacitive sensors.

   This pin mapping is for ESP32 Devkit DOIT. Devkit supports 9 touch pins out of a total of
   10 touch pins available on the ESP32 WROOM chip. This version of ESP32 does not have Touch1 enabled.
   Since Touch1 is shared with GPIO0, and on the Devkit DOIT board, it is not available.

   Touch sensor pins of Devkit:
   Touch0 >> GPIO4
   Touch1 >> GPIO0 *Not available on Devkit 30 pin version but available on Devkit 36 pin version
   Touch2 >> GPIO2 *Not working well, always gives a zero value
   Touch3 >> GPIO15
   Touch4 >> GPIO13
   Touch5 >> GPIO12
   Touch6 >> GPIO14
   Touch7 >> GPIO27
   Touch8 >> GPIO33 *Swap with D32
   Touch9 >> GPIO32 *Swap with D33
*****************************************************************************************************************/

#define Touch0 4
#define Touch3 15
#define Touch4 13
#define Touch5 12
#define Touch6 14
#define Touch7 27
#define Touch8 32
#define Touch9 33

#define LED_BUILTIN 2

int touchSensorValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("ESP32 Touch Test");
}

void loop() {
  touchSensorValue = touchRead(Touch0);
  Serial.print("Touch sensor value: ");
  Serial.println(touchSensorValue);
  delay(100);
  
  if (touchSensorValue < 20) {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}
