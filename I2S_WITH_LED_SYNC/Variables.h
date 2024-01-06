#include "driver/i2s.h"                       // Library of I2S routines, comes with ESP32 standard install

//------------------------------------------------------------------------------------------------------------------------
// I2S configuration structures

static const i2s_config_t i2s_config = {
  .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),
  .sample_rate = 48000,                            // Note, this will be changed later
  .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
  .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
  .communication_format = (i2s_comm_format_t)(I2S_COMM_FORMAT_I2S | I2S_COMM_FORMAT_I2S_MSB),
  .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,       // high interrupt priority
  .dma_buf_count = 8,                             // 8 buffers
  .dma_buf_len = 1024,                            // 1K per buffer, so 8K of buffer space
  .use_apll = 0,
  .tx_desc_auto_clear = true,
  .fixed_mclk = -1
};

// These are the physical wiring connections to our I2S decoder board/chip from the esp32, there are other connections
// required for the chips mentioned at the top (but not to the ESP32), please visit the page mentioned at the top for
// further information regarding these other connections.

static const i2s_pin_config_t pin_config = {
  .bck_io_num = 26,                                 // The bit clock connectiom, goes to pin 27 of ESP32
  .ws_io_num = 27,                                  // Word select, also known as word select or left right clock
  .data_out_num = 25,                               // Data out from the ESP32, connect to DIN on 38357A
  .data_in_num = I2S_PIN_NO_CHANGE                  // we are not interested in I2S data into the ESP32
};

//------------------------------------------------------------------------------------------------------------------------
//Defined Variables

#define defaultMultiplier 160                       //Need not to be changed
#define LED_FREQUENCY 32000                         //Need not to be changed
#define LED_RESOLUTION 10                           //Need not to be changed

//------------------------------------------------------------------------------------------------------------------------
//Variables

//I2S Related Variables
static const i2s_port_t i2s_num = I2S_NUM_0;  // i2s port number
int16_t value = 0;
float multiplier = 4000;
volatile int iteration = 0;
int16_t* dataPointer;

// Sine Table Related Variables
float radian = 0;
volatile float sine[1200];
float angleMultiplier = 0.00523598775598;

//Audio Related Variables
int vol = 0;

//Brightness Related Variables
volatile uint16_t pwm = 0;
volatile uint16_t brightness  = 0;

//------------------------------------------------------------------------------------------------------------------------
