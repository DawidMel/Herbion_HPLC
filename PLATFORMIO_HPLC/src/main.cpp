#include <Arduino.h>
#include "defined_const.hpp"

#include"dzielnik_napięcia.hpp"
#include"czujnik_hala.hpp"
#include"czujnik_odleglosci.hpp"
#include"czujnik_rgb.hpp"

hallSensor hall_sensor1(PIN_HAL_SENSOR);
rgbSensor rgb_sensor(PIN_RGB_SENSOR_S0,PIN_RGB_SENSOR_S1,PIN_RGB_SENSOR_S2,PIN_RGB_SENSOR_S3,PIN_RGB_SENSOR_LED,PIN_RGB_SENSOR_OUT);

void setup() 
{
Serial.begin(9600);


hall_sensor1.init();
rgb_sensor.init();

}

void loop() 
{

}
