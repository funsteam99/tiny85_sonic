#include "SSD1306_minimal.h"
#include <avr/pgmspace.h>


int trigPin = PB4;                  //Trig Pin
int echoPin = PB3;                  //Echo Pin

///


SSD1306_Mini oled; // Declare the OLED object

void splash() {
 oled.startScreen();
 oled.clear(); // Clears the display

 oled.cursorTo(0, 0); // x:0, y:0
 oled.printString("Hello World!");
 oled.cursorTo(0, 10); // x:0, y:23
 oled.printString("ATtiny85!");
 oled.cursorTo(0, 30); // x:0, y:23
 oled.printString("     FunSTEAM");
}

void setup() {
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 delay(1000);
 oled.init(0x3C); 
 oled.clear(); 
 delay(1000); 
 splash(); 
 delay(1000);
 oled.clear(); 
}

int clear_screen_counter;

void loop() {
  long duration;
  float RangeInInches;
  float RangeInCentimeters;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);     
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);   
  duration = pulseIn(echoPin, HIGH);


  RangeInCentimeters = (float)duration / 29.1 / 2.0; 
  RangeInInches = (float)duration / 74.0 / 2.0; 

    
 char str[6]; 

// oled.clear(); 
 oled.cursorTo(0, 0); // x:0, y:0
 oled.printString("distance:");

 oled.cursorTo(0, 10); // x:0, y:23
 oled.printString("       inch      ");
// itoa(RangeInInches, str, 10);
 dtostrf(RangeInInches,3,0,str);
 oled.cursorTo(0, 10); // x:0, y:23
 oled.printString(str);
 
 oled.cursorTo(0, 20); // x:0, y:23
 oled.printString("       cm        ");
// itoa(RangeInCentimeters, str, 10);
 dtostrf(RangeInCentimeters,3,0,str);
 oled.cursorTo(0, 20); // x:0, y:23
 oled.printString(str);

    delay(333);
 clear_screen_counter++;
}
