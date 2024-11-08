#include<Arduino.h>

#ifndef CZUJNIK_RGB
#define CZUJNIK_RGB


//global variable

volatile extern int RGB_counter;
volatile extern uint8_t rgb_measure_lock;



//function
void timer2_start(void);
void timer2_stop(void);
void ISR_SENSOR_PIN();


class rgbSensor
{
private:
    //configurable pins
    uint8_t m_s0_pin;
    uint8_t m_s1_pin;
    uint8_t m_s2_pin;
    uint8_t m_s3_pin;

    uint8_t m_led_pin;
    uint8_t m_out_pin;

    // inner object state variable
    int m_red_intesivity;
    int m_green_intesivity;
    int m_blue_intesivity;

public:
    rgbSensor(uint8_t s0_pin, uint8_t s1_pin, uint8_t s2_pin, uint8_t s3_pin, uint8_t led_pin, uint8_t out_pin);
    void init();
    void measure_red_intensivity();
    void measure_green_intensivity();
    void measure_blue_intensivity();


    int get_red_intensivity();
    int get_green_intensivity();
    int get_blue_intensivity();


};





#endif //CZUJNIK_RGB