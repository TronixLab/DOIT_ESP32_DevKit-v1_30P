/***********************ESP32 Wroom32 DevKit Analog Read Example***********************
  The ESP32 has an analog to a digital converter built into it with a resolution of up to
  12 bits, which is 4096 different values. This means that 0 volts will produce a digital
  value of 0 while the maximum voltage will produce a digital value of 4095 and the correspondingly
  scaled digital value will be produced between these voltage ranges.

  ADCs supports up to 18 analog channels, which means that 18 analog sensors can be attached to this
  board at a time. However, ADC2 is shared among the other tools of this Development Board. So we've got
  two ADCs in ESP32, ADC1 and ADC2.

  ESP32 ADC1 Pin Mapping:
  ADC1_CH0 >>> GPIO36
  ADC1_CH1 >>> Not available on this board Devkit DoIT ( 30 pins version )
  ADC1_CH2 >>> NA
  ADC1_CH3 >>> GPIO39
  ADC1_CH6 >>> GPIO34
  ADC1_CH7 >>> GPIO35
  ADC1_CH4 >>> GPIO32
  ADC1_CH5 >>> GPIO33

  ESP32 ADC2 Pin Mapping:
  ADC2_CH0 >>> GPIO0
  ADC2_CH1 >>> This channel is not available on Devkit DOIT board
  ADC2_CH2 >>> GPIO2
  ADC2_CH3 >>> GPIO15
  ADC2_CH4 >>> GPIO13
  ADC2_CH5 >>> GPIO12
  ADC2_CH6 >>> GPIO14
  ADC2_CH7 >>> GPIO27
  ADC2_CH8 >>> GPIO25
  ADC2_CH9 >>> GPIO26
*****************************************************************************************/

#define ADC1_CH0 36   // VP
#define ADC1_CH3 39   // VN
#define ADC1_CH4 32   // D32
#define ADC1_CH5 33   // D33
#define ADC1_CH6 34   // D34
#define ADC1_CH7 35   // D35

#define ADC2_CH0 4    // D4
#define ADC2_CH2 2    // D2
#define ADC2_CH3 15   // D15
#define ADC2_CH4 13   // D13
#define ADC2_CH5 12   // D12
#define ADC2_CH6 14   // D14
#define ADC2_CH7 27   // D27
#define ADC2_CH8 25   // D25
#define ADC2_CH9 26   // D26

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  // Read the input on analog ADC2_CH2:
  int sensorValue = analogRead(ADC2_CH2);

  // Convert the analog reading (which goes from 0 - 4095) to a voltage (0 - 3.3V):
  float voltage = sensorValue * (3.3 / 4095.0);

  // Print out the value you read:
  Serial.print("ADC val: ");
  Serial.print(sensorValue);
  Serial.print(", ");
  Serial.print(voltage);
  Serial.println("mV");
  delay(100);
}
