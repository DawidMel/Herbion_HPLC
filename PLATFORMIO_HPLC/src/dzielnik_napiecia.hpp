#include "defined_const.hpp"
#include<Arduino.h>


#ifndef DZIELNIK_NAPIECIA
#define DZIELNIK_NAPIECIA


class voltageDivider //pieprzyć optymalizację bawię się z floatami
{
private:
    const uint8_t m_voltage_read_pin;

    const float m_refernce_resistor;
    const float m_build_in_resistor;
    const float m_voltage_tolerance;

    uint8_t m_reverse_direction = 0;  // 0 is normal 1 is reverse
    uint8_t m_mount_state = 0; // if mount normal 1 else if mount reverse or unplug 0


public:
    voltageDivider( const uint8_t voltage_read_pin, const float refernce_resistor,
                     const float build_in_resistor,const float voltage_tolerance);
    void init();
    void check_polarity();
    int get_polarity();
    void check_is_column_mount();
    int get_mount_state();
};

class diodeVoltageDevider : public voltageDivider
{
private:
    /* data */
public:
    diodeVoltageDevider(/* args */);
    ~diodeVoltageDevider();
};




class voltageBlocker //krążek
{
private:
    uint8_t m_voltage_read_pin;
public:
    voltageBlocker(uint8_t voltage_read_pin);
    void init();
    int check_is_circuit_open();
};







#endif //DZIELNIK_NAPIECIA