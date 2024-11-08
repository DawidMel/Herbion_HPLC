#include<Arduino.h>

#ifndef CZUJNIK_HALA
#define CZUJNIK_HALA


class hallSensor
{
private:

    uint8_t m_output_pin;
    int m_rav_meas;

public:
    hallSensor(uint8_t output_pin);
    void init();
    void make_measure();
    int get_value();

};



#endif //CZUJNIK_HALA