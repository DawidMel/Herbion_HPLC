#include"czujnik_hala.hpp"

/*

// program, który przeniesie pin 10 w stan niski 
// po wykryciu pola magentycznego i zaświeci diodę na pinie 13
// https://botland.com.pl/pl/czujniki-magnetyczne/14326-iduino-czujnik-halla-pola-magnetycznego.html


int Led = 13 ; // define LED Interface
int SENSOR = 10 ; // define the Hall magnetic sensor interface
int val ; // define numeric variables val
void setup () {
  pinMode (Led, OUTPUT) ;    // define LED as output interface
  pinMode (SENSOR, INPUT) ;  // define the Hall magnetic sensor line as input
}

void loop () {
  val = digitalRead (SENSOR) ; // read sensor line
  if (val == LOW) { // when the Hall sensor detects a magnetic field, Arduino LED lights up
    digitalWrite (Led, HIGH);
  }
  digitalWrite (Led, LOW);
}


*/