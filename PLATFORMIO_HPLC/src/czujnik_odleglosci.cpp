#include"czujnik_odleglosci.hpp"

distanceSensor::distanceSensor(uint8_t digital_pin, uint8_t analog_pin):
m_digital_pin(digital_pin),
m_analog_pin(analog_pin)
{
}

void distanceSensor::init()
{
  pinMode(m_digital_pin,INPUT);
  pinMode(m_analog_pin,INPUT);
}

  void distanceSensor::check_is_object_near()
  {
      if(digitalRead(m_digital_pin)==LOW)
      {
        m_is_object_near = 1;
      }
      else 
      {
        m_is_object_near = 0;
      }
  }

  int distanceSensor::get_object_presence()
  {
    return m_is_object_near;
  }