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




#endif //DZIELNIK_NAPIECIA