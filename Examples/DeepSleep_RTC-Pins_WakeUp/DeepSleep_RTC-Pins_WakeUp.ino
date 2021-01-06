/********************************************** ESP32 GPIO RTC PINS *************************************************
  On the ESP32, there is RTC GPIO support. When the ESP32 is in a deep sleep, the GPIOs routed to the RTC low-power
  subsystem can be used. When the Ultra Low Power (ULP) co-processor is operating, these RTC GPIOs can be used to wake
  the ESP32 up from deep sleep.
  
  RTC_GPIO0 – GPIO36
  RTC_GPIO3  -GPIO39
  RTC_GPIO4 – GPIO34
  RTC_GPIO5 – GPIO35
  RTC_GPIO6 – GPIO25
  RTC_GPIO7 -GPIO26
  RTC_GPIO8 – GPIO33
  RTC_GPIO9 – GPIO32
  RTC_GPIO10 -GPIO4
  RTC_GPIO11 – GPIO0
  RTC_GPIO12 – GPIO2
  RTC_GPIO13 – GPIO15
  RTC_GPIO14 – GPIO13
  RTC_GPIO15 – GPIO12
  RTC_GPIO16 – GPIO14
  RTC_GPIO17 – GPIO27
  
***********************************************************************************************************************/

RTC_DATA_ATTR int bootCount = 0;

/*
  Method to print the reason by which ESP32
  has been awaken from sleep
*/
void print_wakeup_reason() {
  esp_sleep_wakeup_cause_t wakeup_reason;

  wakeup_reason = esp_sleep_get_wakeup_cause();

  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("EXT0 Test");

  switch (wakeup_reason) {
    case 1  : Serial.println("Wakeup caused by external signal using RTC_IO"); break;
    case 2  : Serial.println("Wakeup caused by external signal using RTC_CNTL"); break;
    case 3  : Serial.println("Wakeup caused by timer"); break;
    case 4  : Serial.println("Wakeup caused by touchpad"); break;
    case 5  : Serial.println("Wakeup caused by ULP program"); break;
    default : Serial.println("Wakeup was not caused by deep sleep"); break;
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000); 

  //Increment boot number and print it every reboot
  ++bootCount;
  Serial.println("Boot number: " + String(bootCount));

  //Print the wakeup reason for ESP32
  print_wakeup_reason();

  /*
    First we configure the wake up source
    We set our ESP32 to wake up for an external trigger.
    There are two types for ESP32, ext0 and ext1 .
    ext0 uses RTC_IO to wakeup thus requires RTC peripherals
    to be on while ext1 uses RTC Controller so doesnt need
    peripherals to be powered on.
    Note that using internal pullups/pulldowns also requires
    RTC peripherals to be turned on.
  */
  Serial.println(esp_sleep_enable_ext0_wakeup(GPIO_NUM_36, 1));   // 1 = High, 0 = Low wake-up trigger

  //Go to sleep now
  Serial.println("Going to sleep now");
  Serial.flush();
  esp_deep_sleep_start();
  Serial.println("This will never be printed");
}

void loop() {
  //This is not going to be called
}
