#include "Variables.h"
#include "RtosFunctions.h"

void setup() {
  Serial.begin(115200);
  ledcSetup(0, LED_FREQUENCY, LED_RESOLUTION);
  ledcAttachPin(18, 0);
  constructSineTable();
  setupI2S();
  dataPointer = &value;

  //Distributing the task amoung two available processing cores using RTOS funtions
  
  xTaskCreatePinnedToCore(
    writeI2S,                    // Function to be called
    "I2S WRITE",                 // Name of task
    8192,                        // Stack size (bytes in ESP32, words in FreeRTOS)
    NULL,                        // Parameter to pass to function
    configMAX_PRIORITIES - 1,    // Task priority (0 to configMAX_PRIORITIES - 1)
    NULL,                        // Task handle
    0);

  xTaskCreatePinnedToCore(
    pwmHandle,                     // Function to be called
    "LED PWM HANDLER",             // Name of task
    4096,                          // Stack size (bytes in ESP32, words in FreeRTOS)
    NULL,                          // Parameter to pass to function
    configMAX_PRIORITIES - 1,      // Task priority (0 to configMAX_PRIORITIES - 1)
    NULL,                          // Task handle
    1);                      // Run on one core for demo purposes (ESP32 only)
}

void loop() {
  //Let the RTOS handel all the tasks
}
