#include "dzielnik_napiecia.hpp"


voltageDivider::voltageDivider(const uint8_t voltage_read_pin, const float refernce_resistor,
                                const float build_in_resistor,const float voltage_tolerance):
m_voltage_read_pin(voltage_read_pin),
m_refernce_resistor(refernce_resistor),
m_build_in_resistor(build_in_resistor),
m_voltage_tolerance(voltage_tolerance)
{

}


void voltageDivider::init()
{
    pinMode(m_voltage_read_pin,INPUT);
}

void voltageDivider::check_polarity()
{
    if(((analogRead(m_voltage_read_pin)/1023)*5.0)>MAX_FORVARD_VOLTAGE)
    {
        m_reverse_direction = 1; //conected in wrong direction
        m_mount_state = 0;
    } 
    else
    {m_reverse_direction = 0;}  //conected right
}


int voltageDivider::get_polarity()
{
    return m_reverse_direction;
}


void voltageDivider::check_is_column_mount()
{
    float measure_voltage = analogRead(m_voltage_read_pin)/1023*5.0;
    float teoretical_voltage = m_refernce_resistor/(m_refernce_resistor+m_build_in_resistor);

    if(abs(measure_voltage-teoretical_voltage)>m_voltage_tolerance)
    {
        m_mount_state = 0;
    }
    else
    {
        m_mount_state = 1;
    }
    
}


int voltageDivider::get_mount_state()
{
    return m_mount_state;
}


voltageBlocker::voltageBlocker(uint8_t voltage_read_pin):
m_voltage_read_pin(voltage_read_pin)
{
}

void voltageBlocker::init()
{
    pinMode(m_voltage_read_pin,INPUT);
}
int voltageBlocker::check_is_circuit_open()
{
    return analogRead(m_voltage_read_pin);
}