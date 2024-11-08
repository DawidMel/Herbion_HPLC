#include<Arduino.h>

#ifndef CZUJNIK_RGB
#define CZUJNIK_RGB


class rgbSensor
{
private:
    uint8_t m_s0_pin;
    uint8_t m_s1_pin;
    uint8_t m_s2_pin;
    uint8_t m_s3_pin;

public:
    rgbSensor(uint8_t s0_pin, uint8_t s1_pin, uint8_t s2_pin, uint8_t s3_pin);

};





#endif //CZUJNIK_RGB