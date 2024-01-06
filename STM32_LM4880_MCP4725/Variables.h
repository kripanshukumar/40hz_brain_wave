#include <Wire_slave.h>

//===============================================================================================================================//
#define samples 544                     //Total no of sine wave samples. If you are getting frequency lower than 40 Hz then decrease the samples, 
                                        //if you are getting frequency higher than 40Hz then increase the samples.
#define DAC_ADDRESS 0x60                //I2C address of the DAC
#define LIGHT_OUTPUT PA10               //Square wave output for the Light
#define VOL_PIN PA0                     //The output of volume potentiometer connects here
#define LIGHT_INTENSITY_PIN PA1         //The outpu of light intensity potentiometer connects here
#define SCL_DAC PB6                     //SCL PIN ON STM board
#define SDA_DAC PB7                     //SDA PIN ON STM board
#define BATTERY_PIN PA2
#define CHARGING_PIN PA3
#define CHARGING_LED PB12
#define AMP_SHUTDOWN_PIN PA9

//SoftWire dac(PB6, PB7);                 //Declaring DAC object with SCL and SDA pins respectively
//===============================================================================================================================//

int16_t sine[samples] = {0};
uint8_t secondaryArray[samples*2] {0};
volatile int iteration = 0;
float theta = 0;

uint32_t t = 0;
uint16_t itr = 0;

int16_t f = 0;
int16_t s = 0;

uint32_t timer = 0;

int toToggle = 0;

float vol = 0;
float pVol = 0;
float bright = 0;
float brightAccumulator = 0;



//===============================================================================================================================//
