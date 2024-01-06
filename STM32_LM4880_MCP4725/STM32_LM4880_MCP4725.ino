#include"Variables.h"
#include "program.h"

void setup() {
  Serial.begin(115200);                                       //Initialize the serial communication
  Serial.println("Starting the Device............");
  //  delay(1000);
  Wire.begin();                                                //INITIALIZE THE I2C
  Wire.setClock(400000);                                       //Set the I2C clock at 400Khz.
  createTable();
  configLightTimer();
  pinMode(LIGHT_OUTPUT, PWM);                              //Declare Light output pin as output
  pinMode(CHARGING_LED, OUTPUT);
  pinMode(CHARGING_PIN, INPUT_PULLUP);
  pinMode(AMP_SHUTDOWN_PIN, OUTPUT);
}

void loop() {                                                  
  vol =  float(analogRead(VOL_PIN)) / 4095;                            //Take the volume input from the potentiometer
  bright = float(analogRead(LIGHT_INTENSITY_PIN)) / 4095;              //Take the brightness input from the potentiometer
  brightAccumulator = 0.98 * brightAccumulator + 0.02 * bright;

  if (!digitalRead(CHARGING_PIN)) {
    if (millis() - timer >= 500) {
      digitalWrite(CHARGING_LED, !digitalRead(CHARGING_LED));
      timer = millis();
    }
  }
  else {
    digitalWrite(CHARGING_LED, LOW);
  }

  if (abs(pVol - vol) >= 0.02) {
    updateTable();
    pVol = vol;
  }
  
  if(vol < 0.02){
    digitalWrite(AMP_SHUTDOWN_PIN, HIGH);
    Serial.println("HIGH");
  }
  else{
    digitalWrite(AMP_SHUTDOWN_PIN, LOW);
    Serial.println("LOW");
  }
  Serial.println(vol);
  pwmWrite(LIGHT_OUTPUT, 250 * brightAccumulator);
  
  Wire.beginTransmission(DAC_ADDRESS);
  Wire.write(&secondaryArray[0], samples);
  Wire.endTransmission();
  
  pwmWrite(LIGHT_OUTPUT, 0);
  
  Wire.beginTransmission(DAC_ADDRESS);
  Wire.write(&secondaryArray[samples], samples);
  Wire.endTransmission();
}
