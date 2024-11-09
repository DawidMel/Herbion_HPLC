#include "stearing_funct.hpp"


void tube_state_funct(hallSensor& hall_sensor1)
{
    hall_sensor1.make_measure();

    if(hall_sensor1.get_value()<= HAL_MAX_VALLUE_FOR_DISCONNECT)
    {
        Serial.println(state::disconect_tube);
    }

    if(hall_sensor1.get_value()<= HAL_MAX_VALUE_FOR_BLOCKED && hall_sensor1.get_value() >= HAL_MIN_VALUE_FOR_BLOCKED)
    {
        Serial.println(state::disconect_tube);
    }

    if(hall_sensor1.get_value()>=HAL_MIN_VALUE_FOR_GOOD)
    {
       Serial.println(state::right_tube);
    }

}

void bottle_state_funct(distanceSensor& dist_sensor)
{
    dist_sensor.check_is_object_near();

    if(dist_sensor.get_object_presence())
    {
        Serial.println(state::closed_bootle);
    }
    else
    {
        Serial.println(state::open_bootle);
    }
}

void column_state_funct(voltageDivider& right_column, voltageDivider & wrong_column)
{
    right_column.check_polarity();
    wrong_column.check_polarity();

    if(right_column.get_polarity()==0 && wrong_column.get_polarity()==0)  //jeśli rzadna z nich nie jest "owrócona"
    {
        if(right_column.get_mount_state()==1) //sprawdzamy czy jest właściwa kolumna
        {
            Serial.println(state::right_column);
        }

        if(wrong_column.get_mount_state()==1)
        {
            Serial.println(state::wrong_column);
        }
    }

    if(right_column.get_polarity()==1 || wrong_column.get_polarity()==1)
    {
        Serial.println(state::reverse_column);
    }

}
