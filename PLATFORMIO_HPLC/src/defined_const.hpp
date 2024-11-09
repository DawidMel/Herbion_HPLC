#include <Arduino.h>

#ifndef DEFINED_CONST
#define DEFINED_CONST


//PHISICAL PIN CONNECTIONS

//hall sensor
constexpr uint8_t PIN_HAL_SENSOR = A0;

constexpr int HAL_MAX_VALLUE_FOR_DISCONNECT = 50;
constexpr int HAL_MIN_VALUE_FOR_BLOCKED = 51;
constexpr int HAL_MAX_VALUE_FOR_BLOCKED = 599;
constexpr int HAL_MIN_VALUE_FOR_GOOD = 600;

//distace sensor

constexpr uint8_t PIN_DIGITAL_DISTANCE_SENSOR = 10;
constexpr uint8_t PIN_ANALOG_DISTANCE_SENSOR = A4;

//rgb sensor
constexpr uint8_t PIN_RGB_SENSOR_OUT = 3;  // MUST SUPPORT INTERUPT!

constexpr uint8_t PIN_RGB_SENSOR_S0 = 4;
constexpr uint8_t PIN_RGB_SENSOR_S1 = 5;
constexpr uint8_t PIN_RGB_SENSOR_S2 = 6;
constexpr uint8_t PIN_RGB_SENSOR_S3 = 7;
constexpr uint8_t PIN_RGB_SENSOR_LED = 8;

//resistance checking components

constexpr float MAX_FORVARD_VOLTAGE = 4.0;

//Columns
constexpr uint8_t COLUMN_PIN = A1;
constexpr float COLUMN_REFFERENCE_RESISTOR = 33000;

constexpr float COLUMN_1_BUILD_IN_RESISTOR = 10000;
constexpr float COLUMN_1_VOLTAGE_TOLERANCE = 0.3; //[V]

constexpr float COLUMN_2_BUILD_IN_RESISTOR = 33000;
constexpr float COLUMN_2_VOLTAGE_TOLERANCE = 0.4; //[V]



//Filters
constexpr uint8_t FILTER_PIN = A2;  //it may work on digital pin


//UV lamp
constexpr uint8_t LAMP_PIN = A3;

//CONFIGURABLE VALUE
constexpr float RGB_S1_RED_SENSITIVITY_MULT_FACTOR = 1.0;
constexpr float RGB_S1_GREEN_SENSITIVITY_MULT_FACTOR = 1.0;
constexpr float RGB_S1_BLUE_SENSITIVITY_MULT_FACTOR = 1.0;




#endif // DEFINED_CONST


//trash and temp 

// constexpr float C1_MIN_READ_VOLT = 5*(COLUMN_REFFERENCE_RESISTOR*0.95)/(COLUMN_1_BUILD_IN_RESISTOR*1.05+COLUMN_REFFERENCE_RESISTOR*0.95);
// constexpr float C1_MAX_READ_VOLT = 5*(COLUMN_REFFERENCE_RESISTOR*1.05)/(COLUMN_1_BUILD_IN_RESISTOR*0.95+COLUMN_REFFERENCE_RESISTOR*1.05);

// constexpr float calculate_min_voltage(const float ref_res, const float build_in_res, const float max_error, const float voltage)
// {
//     return  voltage*((ref_res*(1-max_error))/(ref_res*(1-max_error)+(build_in_res*(1+max_error))));
// }

// constexpr float calculate_typ_voltage(const float ref_res, const float build_in_res, const float max_error, const float voltage)
// {
//     return voltage*((ref_res)/(ref_res+(build_in_res)));
// }

// constexpr float calculate_max_voltage(const float ref_res, const float build_in_res, const float max_error, const float voltage)
// {
//     return voltage*((ref_res*(1+max_error))/(ref_res*(1+max_error)+(build_in_res*(1-max_error))));
// }