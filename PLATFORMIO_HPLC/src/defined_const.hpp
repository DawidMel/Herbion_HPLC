#include<Arduino.h>

#ifndef DEFINED_CONST
#define DEFINED_CONST

//PHISICAL PIN CONNECTIONS

//hall sensor
constexpr uint8_t PIN_HAL_SENSOR = A0;

//rgb sensor
constexpr uint8_t PIN_RGB_SENSOR_OUT = 3;  // MUST SUPPORT INTERUPT!

constexpr uint8_t PIN_RGB_SENSOR_S0 = 4;
constexpr uint8_t PIN_RGB_SENSOR_S1 = 5;
constexpr uint8_t PIN_RGB_SENSOR_S2 = 6;
constexpr uint8_t PIN_RGB_SENSOR_S3 = 7;
constexpr uint8_t PIN_RGB_SENSOR_LED = 8;



//CONFIGURABLE VALUE
constexpr float RGB_S1_RED_SENSITIVITY_MULT_FACTOR = 1.0;
constexpr float RGB_S1_GREEN_SENSITIVITY_MULT_FACTOR = 1.0;
constexpr float RGB_S1_BLUE_SENSITIVITY_MULT_FACTOR = 1.0;




#endif // DEFINED_CONST
