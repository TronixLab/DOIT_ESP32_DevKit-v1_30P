/********************************************* ESP32 HALL SENSOR *********************************************
  Every ESP32 chips have a hall-effect sensor built-in. It must have an ESP32 chip with an integrated hall effect
  sensor, whatever kind of ESP32 development board you use. To test the magnetic field, Hall effect sensors are used.
  Hall effect sensors sense the magnetic field of lines in their setting and create a voltage at the sensor's output pins.
  For all ESP32 chips, the ESP32 board is placed under this metal sheet. It detects the changes in the magnetic field 
  when you carry a magnet close to this metal cover, and generates an output voltage according to the strength of the 
  magnetic field.
***************************************************************************************************************/

int hallSensorValue = 0;

void setup() {
  Serial.begin(9600);  // It defines the baud rate of 9600 bits per second to serial monitor
}

void loop() {
  hallSensorValue = hallRead();
  Serial.print("Hall sensor value = ");
  Serial.println(hallSensorValue);
  delay(100);
}
