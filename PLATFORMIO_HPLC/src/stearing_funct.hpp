
#include"czujnik_hala.hpp"
#include "defined_const.hpp"

#ifndef STEARING_FUNCT
#define STEARING_FUNCT



enum exercise_type
{
    tube = 0,
    filter = 1,
    column = 2,
    uv_lamp = 3,
    bottle = 4,
    sample_probe_care = 5,
    try_different_sample =6,

    not_selected_exercise = 99
};

enum state //to uppercase but I am not im mood to do that
{
    disconect_tube = 0,
    blocked_tube = 1,
    right_tube = 2,

    wrong_filter = 3,
    right_filter = 4,

    wrong_column = 5,
    reverse_column = 6,
    right_column = 7,

    wrong_uv_lamp = 8,
    right_uv_lamp = 9,

    closed_bootle = 10,
    open_bootle = 11,

    autosampler_wrong_probe = 12,
    autosampler_washing_probe = 13,
    autosampler_probe_1 = 14,
    autosampler_probe_2 = 15,
    autosampler_probe_3 = 16,
    autosampler_probe_4 = 17,
    autosampler_probe_5 = 18,
    autosampler_probe_6 = 19,

    not_selected_state = 99
};

void tube_state_funct(hallSensor& hall_sensor1);

void bottle_state_funct();




#endif //STEARING_FUNCT