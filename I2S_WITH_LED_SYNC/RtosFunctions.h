void setupI2S() {
  i2s_driver_install(i2s_num, &i2s_config, 0, NULL);        // ESP32 will allocated resources to run I2S
  i2s_set_pin(i2s_num, &pin_config);                        // Tell it the pins you will be using
  i2s_set_sample_rates(i2s_num, 48000);      //set sample rate
}

void writeI2S(void *parameter) {                                            //Write the data to the I2S Device
  while (1) {                                                               //Infinite loop
    size_t BytesWritten;                                                    //Returns the no of written bytes
    value = multiplier * sine[iteration];                                   //Calculates the current value of the sine wave which is to be transmitted
    pwm = brightness * (sine[iteration] + 1);                               //Calculates the corresponding PWM values for the LED
    i2s_write(i2s_num, dataPointer, 2, &BytesWritten, portMAX_DELAY);       //Writes the computed data to I2S DMA Buffer
    ledcWrite(0, pwm);                                                      //Writes the PWM value for the LED
    iteration++;                                                            //Increments the current Iteration counter
    if (iteration >= 1200) {                                                //IF the iteration reaches the end of sine wave then this condition resets the iteration variable
      iteration = 0;                                                        //RESET ITERATION
      vol = analogRead(33) / 41;                                            //Calculate the volume intensity from the potentiometer
      brightness = analogRead(32) / 8;                                      //Calculate the Brightneew from the potentiometer
      multiplier = vol * defaultMultiplier;                                 //Calculate the sine multiplier for the wav data.
    }
  }
}

void constructSineTable() {                                                 //This function constructs the sine table in advance so that computation can be reduced later
  for (int i = 0; i < 1200; i++) {
    radian = angleMultiplier * (i + 1);
    sine[i] = sin(radian);
  }
}

void pwmHandle(void *parameter) {                                           //This Function writes the PWM vlaues and is running on the other core.
  while (1) {
    ledcWrite(0, pwm);
    delayMicroseconds(10);
  }
}
