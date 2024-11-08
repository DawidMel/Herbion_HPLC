

/*
TCS3200D has different sensitivities to red, green, and blue. As a result, the RGB output of pure white is not always 255.
Therefore, a white balance adjustment is required after power-up within 2 seconds. Here are the processes.

Place a white paper at the top of the sensor at a distance of 1cm, and input a High-level voltage to the LED port to light up 4 bright white LED indicators.
The program selects R, G, and B filters respectively, and measures the corresponding RGB values of red, green, and blue.
Calculate 3 adjustment parameters corresponding to red, green, and blue respectively, and perform automatic white balance adjustment.

DOC: https://www.waveshare.com/wiki/Color_Sensor


The typical output frequency of TCS3200D is in a range of 2Hz to 500KHz. 

*/



/*

int s0 = 3, s1 = 4, s2 = 5, s3 = 6; //piny modułu połączone z Arduino
int out = 2;                      //pin 2 Arduino i OUT od czujnika
int flag = 0;
byte counter = 0;
byte countR = 0, countG = 0, countB = 0;
void setup()
{
  Serial.begin(9600);             //inicjalizacja monitora szeregowego
  pinMode(s0, OUTPUT);            //ustawienie pinów jako wyjścia
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
 
}
void TCS()
{
  flag = 0;
  digitalWrite(s1, HIGH);
  digitalWrite(s0, HIGH);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  attachInterrupt(0, ISR_INTO, LOW);
  timer0_init();
 
}
void ISR_INTO()
{
  counter++;
}
void timer0_init(void)
{
  TCCR2A = 0x00;
  TCCR2B = 0x07; //częstotliwość zegara - 1024
  TCNT2 = 100;   //przepełnienie 10 ms
  TIMSK2 = 0x01; //pozwolenie na przerwanie
}


int i = 0;
ISR(TIMER2_OVF_vect)           //timer 2, 10ms przepełnienie 10ms. funkcja przerwanie wewnętrzengo przepełnienia
{
  TCNT2 = 100;
  flag++;
  if (flag == 1)                 //pobranie i wyświetlenie na ekranie składowych RGB
  {
    countR = counter;
    Serial.print("red=");
    Serial.print(countR, DEC);
    Serial.print("tt");
    digitalWrite(s2, HIGH);
    digitalWrite(s3, HIGH);
  }
  else if (flag == 2)
  {
    countG = counter;
    Serial.print("green=");
    Serial.print(countG, DEC);
    Serial.print("t");
    digitalWrite(s2, LOW);
    digitalWrite(s3, HIGH);
  }
  else if (flag == 3)
  {
    countB = counter;
    Serial.print("blue=");
    Serial.print(countB, DEC);
    Serial.print("t");
    Serial.println("n");
    digitalWrite(s2, LOW);
    digitalWrite(s3, LOW);
 
  }
  else if (flag == 4)
  {
    flag = 0;
  }
  counter = 0;
}
void loop()                    //główna pętla programu
{
  TCS();
  delay(500);
  while (1);
 
}



*/

#include"czujnik_rgb.hpp"


volatile int RGB_counter=0;
volatile uint8_t rgb_measure_lock=1;



void timer2_start(void)  
//licznik zliczający od 100 (wartość TCNT2) do 255 (maxymalna wartość dla licznika)
//zwiększenie wartości licznika z częśtotliwością ok 15,6 KHZ (zegar 16MHZ prescaler 1024)
{
  TCCR2A = 0x00;
  TCCR2B = 0x07; //częstotliwość zegara podzielona przez 1024
  TCNT2 = 100;   //przepełnienie 10 ms
  TIMSK2 = 0x01; //pozwolenie na przerwanie
}

void timer2_stop(void)
{
  TCCR2B = 0x00; //wyłączamy zegar
}


void ISR_SENSOR_PIN()
{
  RGB_counter++;
}

ISR(TIMER2_OVF_vect) //obsługa przerwania wywołanego przez licznik
{
  rgb_measure_lock = 0;
}


rgbSensor::rgbSensor(uint8_t s0_pin, uint8_t s1_pin, uint8_t s2_pin, uint8_t s3_pin,uint8_t led_pin, uint8_t out_pin):
m_s0_pin(s0_pin),
m_s1_pin(s1_pin),
m_s2_pin(s2_pin),
m_s3_pin(s3_pin),
m_led_pin(led_pin),
m_out_pin(out_pin)
{
}

void rgbSensor::init()
{
  pinMode(m_s0_pin,OUTPUT);
  pinMode(m_s1_pin,OUTPUT);
  pinMode(m_s2_pin,OUTPUT);
  pinMode(m_s3_pin,OUTPUT);

  pinMode(m_led_pin,OUTPUT);
  pinMode(m_out_pin,INPUT);

  // set prescaler to 20%  mean max frequency is 100 KHZ
  digitalWrite(m_s0_pin,HIGH);
  digitalWrite(m_s1_pin,LOW);
}


void rgbSensor::measure_red_intensivity()
{
  digitalWrite(m_s2_pin,LOW); 
  digitalWrite(m_s3_pin,LOW); 

  //TODO cały poniższy kod wpieprzyć do jakiejś funkcji bo będzie copy paste
  //i tutaj dzieje się czarna magia, aby przerwania nie działały w całym programie zrobiłem ich pewnego rodzaju "ograniczenie"
  // timer0 jest ustawiony by zliczał przez 10 ms w tym czasie w przerwaniach dodawana jest wartość do countera
  // gdy licznik skończy liczyć zmieniana jest (w przerwaniu rgb_measure_lock) co pozwala opuścić pętle pomiarową

  timer2_start();
  attachInterrupt(digitalPinToInterrupt(m_out_pin),ISR_SENSOR_PIN,RISING);
  while(rgb_measure_lock == 1)
  {}
  detachInterrupt(digitalPinToInterrupt(m_out_pin));
  timer2_stop();
  rgb_measure_lock = 1;


  m_red_intesivity = RGB_counter;
  RGB_counter = 0;
}
void rgbSensor::measure_green_intensivity()
{
  digitalWrite(m_s2_pin,HIGH); 
  digitalWrite(m_s3_pin,HIGH); 

}
void rgbSensor::measure_blue_intensivity()
{
  digitalWrite(m_s2_pin,LOW); 
  digitalWrite(m_s3_pin,HIGH); 

}


int rgbSensor::get_red_intensivity()
{
  return m_red_intesivity;
}
int rgbSensor::get_green_intensivity()
{
  return m_green_intesivity;
}
int rgbSensor::get_blue_intensivity()
{
  return m_blue_intesivity;
}