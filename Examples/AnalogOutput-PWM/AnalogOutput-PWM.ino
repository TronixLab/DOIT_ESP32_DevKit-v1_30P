/********************************************* ESP32 GPIO PWM PINS *************************************************
  PWM or pulse width modulation pins of the ESP32 development board with ESP32 DOIT devkit. You can see how to create
  PWM using this development board's GPIO pins. To get the PWM signal, all GPIO pins from this development board can be
  used. All we need to do is specify a PIN that we want to get a PWM signal from.

  All general purpose input output pins can be used to generate PWM except for digital input pins from GPIO pins 34-39.
  These pins cannot be used as digital output pins. PWM signals are digital input signals. The maximum frequency for these
  PWM pins is 80 MHz. You may configure every other pin as a PWM pin by following the following steps:
  - Select a frequency for pulse width modulation.
  - Select the duty cycle or pulse width.
  - Select the PWM channel. ESP32 provides 16 PWM channels.
  - Assign a digital pin to select the PWM channel.

  different function is used to produce PWM signal for ESP32 in Arduino IDE.  Follow these step to set parameters for all 
  channels of pulse width modulation:

  - There are 16 PWM channels available. You need to choose any channel between 0 and 15.
  - The second step is to choose the frequency of the digital signal. The maximal frequency is 80000000 / 2^bit_num
  - ESP32 boards support PWM resolution between 1 bit to 16 bits. But remember the frequency and resolution of the PWM 
    signal has an inverse effect on each other. So to achieve maximum frequency, the optimal resolution is 8 bit.
  - 8-bit resolution, and duty cycle value will vary between 0-255. Duty cycle defines the width of the signal or on time 
    of the signal. For duty resolution of 8 bits, the maximal frequency is 312.5 kHz.
    The available duty levels are (2^bit_num)-1, where bit_num can be 1-15.
  - Attach the GPIO PIN with a PWM channel of your own choice.
 *******************************************************************************************************************/

#define D2 2
#define D4 4
#define D5 5
#define D12 12
#define D13 13
#define D14 14
#define D15 15
#define RX2 16
#define TX2 17
#define D18 18
#define D19 19
#define D21 21
#define D22 22
#define D23 23
#define D25 25
#define D26 26
#define D27 27
#define D32 32
#define D33 33

int PWM_FREQUENCY = 1000;  
int PWM_CHANNEL = 0;       
int PWM_RESOUTION = 8; 
int dutyCycle = 127;

const int GPIOPIN = D2; 

void setup() {
ledcSetup(PWM_CHANNEL, PWM_FREQUENCY, PWM_RESOUTION);
ledcAttachPin(GPIOPIN, PWM_CHANNEL);
}

void loop() {
  // increase the LED brightness
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // changing the LED brightness with PWM
    ledcWrite(PWM_CHANNEL, dutyCycle);
    delay(10);
  }

  // decrease the LED brightness
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // changing the LED brightness with PWM
    ledcWrite(PWM_CHANNEL, dutyCycle);   
    delay(10);
  }
}
