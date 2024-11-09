#include <Arduino.h>

#ifndef CZUJNIK_ODLEGLOSCI
#define CZUJNIK_ODLEGLOSCI


/*
int Obstacles_din=2;
int Obstacles_ain=A0;
int ad_value;
void setup()
{
  pinMode(Obstacles_din,INPUT);
  pinMode(Obstacles_ain,INPUT);
  Serial.begin(9600);
}
void loop()
{
  ad_value=analogRead(Obstacles_ain);

  {
    Serial.println("Near the Obstacles");
    Serial.println(ad_value);
  }
  else
  {
    Serial.println("Far the Obstacles");
  }
  delay(500);
}


*/

class distanceSensor
{
private:
    uint8_t m_digital_pin;
    uint8_t m_analog_pin;

    uint8_t m_is_object_near = 0;
public:
    distanceSensor(uint8_t digital_pin, uint8_t analog_pin);
    void init();
    void check_is_object_near();
    int get_object_presence(); //zwraca czy coś jest wykrytę
    
};






#endif //CZUJNIK_ODLEGLOSCI