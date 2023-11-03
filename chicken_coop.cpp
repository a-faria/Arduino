#include <Servo.h>
#include <IRremote.h>


int photocellPin = 0;     // the cell and 10K pulldown are connected to a0
int photocellReading;     // the analog reading from the sensor divider
int LEDpin = 11;          // connect Red LED to pin 11 (PWM pin)
int LEDbrightness; 
//


const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
/////create a servo object called servo1 
Servo servo1;
int servoAngle;       // 

void setup(void) {
  // We'll send debugging information via the Serial monitor
	Serial.begin(9600); 
	servo1.attach(9);  
  irrecv.enableIRIn();
  irrecv.blink13(true);
}
 
void loop(void) {
  photocellReading = analogRead(photocellPin);  
 
  //Serial.print("Analog reading = ");
  //Serial.println(photocellReading);     // the raw analog reading
 
  //if statement to turn on the light if light is low
  if (photocellReading >= 500 || irrecv.decode(&results)){
    switch(results.value){
          case 0xFF38C7: //Keypad button "5"
    LEDbrightness = 0;
	servoAngle = 1;
   delay(100);
    analogWrite(LEDpin, LEDbrightness);
	servo1.write (servoAngle);
    delay(100);
    
    }
    irrecv.resume(); 
	}
  else{

  LEDbrightness = 255;
  servoAngle = 100;
  delay(100);
    analogWrite(LEDpin, LEDbrightness);
	servo1.write (servoAngle);
    delay(100);


  }
	
	//analogWrite(LEDpin, LEDbrightness);
	//servo1.write (servoAngle);
	//delay(200);
}
