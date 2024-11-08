#include <Arduino.h>
#include "defined_const.hpp"

#include "dzielnik_napiecia.hpp"
#include "czujnik_hala.hpp"
#include "czujnik_odleglosci.hpp"

#include "czujnik_rgb.hpp"

#include "stearing_funct.hpp"

//global variable
uint8_t exercise = 99;  //not selected
uint8_t state = 99; //not selected


//creating sensor object

hallSensor hall_sensor1(PIN_HAL_SENSOR);
rgbSensor rgb_sensor(PIN_RGB_SENSOR_S0,PIN_RGB_SENSOR_S1,PIN_RGB_SENSOR_S2,PIN_RGB_SENSOR_S3,PIN_RGB_SENSOR_LED,PIN_RGB_SENSOR_OUT);

voltageDivider column1(COLUMN_PIN, COLUMN_REFFERENCE_RESISTOR, COLUMN_1_BUILD_IN_RESISTOR, COLUMN_1_VOLTAGE_TOLERANCE);
voltageDivider column2(COLUMN_PIN, COLUMN_REFFERENCE_RESISTOR, COLUMN_2_BUILD_IN_RESISTOR, COLUMN_2_VOLTAGE_TOLERANCE);

voltageBlocker filter1(FILTER_PIN);

void setup() 
{
Serial.begin(9600);


hall_sensor1.init();
rgb_sensor.init();
column1.init();
column1.init();

}

void loop() 
{
if(Serial.available()>0)   //sprawdzamy czy dostaliśmy informację o rozpoczęciu danego ćwieczenia
{
    exercise = Serial.parseInt();  //jeśli tak, ustawiamy mikrokontroler do obsługi ćwiczenia
}

switch (exercise)
{
case exercise_type::tube:
    tube_state_funct(hall_sensor1);
    break;

case exercise_type::bottle:
    bottle_state_funct();
    break;

default:
    break;
}



}
