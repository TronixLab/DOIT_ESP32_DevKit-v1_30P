/********************************************** ESP32 DUAL CORE *************************************************
  2 Xtensa 32-bit LX6 microprocessors are supported with the ESP32: core 0 and core 1. It is, therefore, a dual center.
  By default, when we run code on the Arduino IDE, it runs on core 1. In this article, by creating tasks, we will teach
  you how to run code on the second core of ESP32. On both cores, you can run pieces of code simultaneously and render
  your ESP32 multitask.

  Advantages of Multi-core processor:
  1. Multi-core processors are useful when there are more than 2 processes to work simultaneously.
  2. As work is distributed among different cores, its speed increases and multiple processes can be finished at the same time.
  3. Power usage can be minimized because it can be used to shut down the peripherals that are not in use at the time if every
     core is in idle mode.
  4. Since they can handle two at once instead of one at a time, dual-core processors have to switch between separate threads
     less frequently than single-core processors.

   Note: you don’t necessarily need to run dual core to achieve multitasking.
******************************************************************************************************************/

TaskHandle_t Task1;
TaskHandle_t Task2;

const int led1 = 2;
const int led2 = 4;

void setup() {
  Serial.begin(115200);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  //create a task that will be executed in the Task1code() function, with priority 1 and executed on core 0
  xTaskCreatePinnedToCore(
    Task1code,   /* Task function. */
    "Task1",     /* name of task. */
    10000,       /* Stack size of task */
    NULL,        /* parameter of the task */
    1,           /* priority of the task */
    &Task1,      /* Task handle to keep track of created task */
    0);          /* pin task to core 0 */
  delay(500);

  //create a task that will be executed in the Task2code() function, with priority 1 and executed on core 1
  xTaskCreatePinnedToCore(
    Task2code,   /* Task function. */
    "Task2",     /* name of task. */
    10000,       /* Stack size of task */
    NULL,        /* parameter of the task */
    1,           /* priority of the task */
    &Task2,      /* Task handle to keep track of created task */
    1);          /* pin task to core 1 */
  delay(500);
}

//Task1code: blinks an LED every 1000 ms
void Task1code( void * pvParameters ) {
  for (;;) {
    Serial.print("Task1 running on core ");
    Serial.println(xPortGetCoreID());

    digitalWrite(led1, HIGH);
    delay(1000);
    digitalWrite(led1, LOW);
    delay(1000);
  }
}

//Task2code: blinks an LED every 500 ms
void Task2code( void * pvParameters ) {
  for (;;) {
    Serial.print("Task2 running on core ");
    Serial.println(xPortGetCoreID());

    digitalWrite(led2, HIGH);
    delay(500);
    digitalWrite(led2, LOW);
    delay(500);
  }
}

void loop() {

}
