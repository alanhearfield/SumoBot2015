#include <SharpIR.h>

int maximumRange = 45; // Maximum range in cm
int minimumRange = 4; 

#define ir A0
#define model 1080

SharpIR sharp(ir, 25, 93, model);

int timer = 0;           // The higher the number, the slower the timing.
int ledPins[] = {
	0, 1, 8, 9, 10, 11 };       // an array of pin numbers to which LEDs are attached
int pinCount = 6;           // the number of pins (i.e. the length of the array)

void setup() {
Serial.begin (9600);  //Commented Out

	// the array elements are numbered from 0 to (pinCount - 1).
	// use a for loop to initialize each pin as an output:
	for (int thisPin = 0; thisPin < pinCount; thisPin++)  {
		pinMode(ledPins[thisPin], OUTPUT);}

}

void loop() {

int dis = sharp.distance();  // this returns the distance to the object you're measuring
Serial.print(dis); 
////if the distance is unreadable, turn left until a reading is made
// if (dis >= maximumRange || dis <= minimumRange){   
//lights_off();
// //to indicate "out of range" 
// Serial.println("Out of range! :(");  //Commented Out
//
// }
// else {
//  //drive_forward into enemy
//lights_on();
// Serial.print(dis);  //Commented Out
// Serial.println(" cm");  //Commented Out
//Serial.println("Charge"); 
//  

while (dis < maximumRange){
  lights_on(); 
Serial.print(dis); 
Serial.println(" while");
dis = sharp.distance();

}

 lights_off();
Serial.println(dis); 
 //Delay 50ms before next reading.
 delay(50);
 
}

//--------------------------------------------------------------------------
void lights_on(){
	// loop from the lowest pin to the highest:
	for (int thisPin = 0; thisPin < pinCount; thisPin++) {
		// turn the pin on:
		digitalWrite(ledPins[thisPin], HIGH);
		delay(timer);
	}
}

//--------------------------------------------------------------------------
void lights_off(){
	// loop from the lowest pin to the highest:
	for (int thisPin = 0; thisPin < pinCount; thisPin++) {
		// turn the pin off:
		digitalWrite(ledPins[thisPin], LOW);
		delay(timer);
	}
}
