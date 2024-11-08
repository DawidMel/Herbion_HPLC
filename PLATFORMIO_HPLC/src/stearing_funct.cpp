#include "stearing_funct.hpp"
#

void tube_state_funct(hallSensor& hall_sensor1)
{
    hall_sensor1.make_measure();

    if(hall_sensor1.get_value()<= HAL_MAX_VALLUE_FOR_DISCONNECT)
    {
        //tube disconnect
    }

    if(hall_sensor1.get_value()<= HAL_MAX_VALUE_FOR_BLOCKED && hall_sensor1.get_value() >= HAL_MIN_VALUE_FOR_BLOCKED)
    {
        //tube blocked
    }

    if(hall_sensor1.get_value()>=HAL_MIN_VALUE_FOR_GOOD)
    {
        //hall good
    }

}