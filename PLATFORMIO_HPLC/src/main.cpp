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
distanceSensor dist_sensot(PIN_DIGITAL_DISTANCE_SENSOR,PIN_ANALOG_DISTANCE_SENSOR);
rgbSensor rgb_sensor(PIN_RGB_SENSOR_S0,PIN_RGB_SENSOR_S1,PIN_RGB_SENSOR_S2,PIN_RGB_SENSOR_S3,PIN_RGB_SENSOR_LED,PIN_RGB_SENSOR_OUT);


voltageDivider wrong_column1(COLUMN_PIN, COLUMN_REFFERENCE_RESISTOR, COLUMN_1_BUILD_IN_RESISTOR, COLUMN_1_VOLTAGE_TOLERANCE);
voltageDivider right_column1(COLUMN_PIN, COLUMN_REFFERENCE_RESISTOR, COLUMN_2_BUILD_IN_RESISTOR, COLUMN_2_VOLTAGE_TOLERANCE);

voltageBlocker filter1(FILTER_PIN);

void setup() 
{
Serial.begin(9600);


hall_sensor1.init();
dist_sensot.init();
rgb_sensor.init();

wrong_column1.init();
wrong_column1.init();

}

void loop() 
{
if(Serial.available()>0)   //sprawdzamy czy dostaliśmy informację o rozpoczęciu danego ćwieczenia
{
    exercise = Serial.parseInt();  //jeśli tak, ustawiamy mikrokontroler do obsługi ZADANEGO ćwiczenia
}



switch (exercise)
{
case exercise_type::tube:
    tube_state_funct(hall_sensor1);
    break;

case exercise_type::bottle:
    bottle_state_funct(dist_sensot);
    break;

case exercise_type::column:
    column_state_funct(right_column1, wrong_column1);
    break;

case exercise_type::filter:
    break;

case exercise_type::uv_lamp:
    break;

case exercise_type::sample_probe_care:
    break;

case exercise_type::try_different_sample:
    break;



default:
    break;
}


delay(1000); //OPÓŹNIENIE co sekundę potem się poprawi
}
