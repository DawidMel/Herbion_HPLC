#include <Arduino.h>
#include "defined_const.hpp"

#include"dzielnik_napięcia.hpp"
#include"czujnik_hala.hpp"
#include"czujnik_odleglosci.hpp"
#include"czujnik_rgb.hpp"

hallSensor hall_sensor1(PIN_HAL_SENSOR);

void setup() 
{
Serial.begin(9600);

hall_sensor1.init();

}

void loop() 
{

}
