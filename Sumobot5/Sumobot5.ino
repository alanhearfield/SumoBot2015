#include <IRremote.h>
#include <IRremoteInt.h>

#include <SharpIR.h>

// IR Reciever
IRrecv irrecv(12); // Receive on pin 12
decode_results results;
long lastPressTime = 0;
int state = LOW;
int IRmode = 0;

//sharp ir
#define ir A0
#define model 1080
SharpIR sharp(ir, 25, 93, model);
int maximumRange = 45; // Maximum range in cm
int minimumRange = 4;

//Motor
int rightmotorpin1 = 4;
int rightmotorpin2 = 5;
int leftmotorpin1 = 6;
int leftmotorpin2 = 7;

//QTR-RC Sensors
int sensor1 = 2;
int sensor2 = 3;
int reflectance1;
int reflectance2;

//Enemy detection count
int detect = 101;

//Initial get away setting
int getaway = 0;

//LED Lights Array

int timer = 0;           // The higher the number, the slower the timing.
int ledPins[] = {
	0, 1, 8, 9, 10, 11 };       // an array of pin numbers to which LEDs are attached
int pinCount = 6;           // the number of pins (i.e. the length of the array)

//--------------------------------------------------------------------------

void setup() {
	// Serial.begin (9600);  //Commented Out

	// Setup motors
	pinMode(rightmotorpin1, OUTPUT);
	pinMode(rightmotorpin2, OUTPUT);
	pinMode(leftmotorpin1, OUTPUT);
	pinMode(leftmotorpin2, OUTPUT);

	//Sharp IR sensor
	pinMode(ir, INPUT);

	// Start the receiver
	irrecv.enableIRIn();

	//LED Brightness for some reason  
	pinMode(13, OUTPUT);

	// the array elements are numbered from 0 to (pinCount - 1).
	// use a for loop to initialize each pin as an output:
	for (int thisPin = 0; thisPin < pinCount; thisPin++)  {
		pinMode(ledPins[thisPin], OUTPUT);

	}
}
//--------------------------------------------------------------------------

void loop()
{
	//Set TX/RX lights to off
	digitalWrite(13, LOW);
lights_off();
	//Wait for IR command
	switch (IRmode)
	{
		case 0:
			if (irrecv.decode(&results)) {
				if (0xFF6897) {  // Can check for a specific button here
					IRmode = 1;}
				irrecv.resume();} // Receive the next value

			break;
		case 1:
			get_away_from_the_edge();
			enemy_detection();
			/* avoid the edges */
			line_right();
			line_left();
	}
}
//--------------------------------------------------------------------------

void enemy_detection(){
	int dis = sharp.distance();
            while (dis < maximumRange){
              lights_on(); 
              forward(10);
              detect = 0;
              dis = sharp.distance();
              line_right();
              line_left();

}

 lights_off();
if (detect < 100){
			detect_right();
		}
		else if (detect >= 100) {
			detect_left();
}
}
//--------------------------------------------------------------------------
void detect_left(){
	left(10);
	detect++;

}

//--------------------------------------------------------------------------
void detect_right(){
	right(20);
	detect++;

}

//--------------------------------------------------------------------------
void line_left()
{
	reflectance1 = 1;
	pinMode(sensor1, OUTPUT);
	digitalWrite(sensor1, HIGH);
	delayMicroseconds(15);
	pinMode(sensor1, INPUT);                                          //set pin as input

	while ((reflectance1 < 500) && (digitalRead(sensor1) != LOW)){   //timeout at 500
		// read the pin state, increment counter until state = LOW
		++reflectance1;                                           // increment value to be displayed via serial port
		delayMicroseconds(4);
	}

	if (reflectance1 < 20){
		//                    Serial.println(reflectance1);  
		//                    Serial.println("Sensor 1 Edge detected");  
		reverse(400);
		right(500);
		detect = 0;

	}
	else 
	{
		//                Serial.println(reflectance1);     
	}
}

//--------------------------------------------------------------------------
void line_right(){
	reflectance2 = 1;
	pinMode(sensor2, OUTPUT);
	digitalWrite(sensor2, HIGH);
	delayMicroseconds(15);
	pinMode(sensor2, INPUT);                                          //set pin as input

	while ((reflectance2 < 500) && (digitalRead(sensor2) != LOW)){   //timeout at 500
		// read the pin state, increment counter until state = LOW
		++reflectance2;                                           // increment value to be displayed via serial port
		delayMicroseconds(4);
	}

	if (reflectance2 < 20){
		//                    Serial.println(reflectance2); 
		//                Serial.println("Sensor 2 Edge detected");  
		reverse(400);
		left(500);
		detect = 100;
	}
	else {
		//                Serial.println(reflectance2);     
	}
}

//--------------------------------------------------------------------------
void motor_stop(){
	digitalWrite(rightmotorpin1, LOW);
	digitalWrite(rightmotorpin2, LOW);

	digitalWrite(leftmotorpin1, LOW);
	digitalWrite(leftmotorpin2, LOW);
}
//--------------------------------------------------------------------------
void forward(int time){
	//  Serial.println("Forward");
	digitalWrite(rightmotorpin1, LOW);
	digitalWrite(rightmotorpin2, HIGH);

	digitalWrite(leftmotorpin1, LOW);
	digitalWrite(leftmotorpin2, HIGH);
	delay(time);
}
//--------------------------------------------------------------------------
void reverse(int time){
	//  Serial.println("Backward");
	digitalWrite(rightmotorpin1, HIGH);
	digitalWrite(rightmotorpin2, LOW);

	digitalWrite(leftmotorpin1, HIGH);
	digitalWrite(leftmotorpin2, LOW);
	delay(time);
}
//--------------------------------------------------------------------------
void left(int time){
	//  Serial.println("Left");
	digitalWrite(rightmotorpin1, LOW);
	digitalWrite(rightmotorpin2, HIGH);

	digitalWrite(leftmotorpin1, HIGH);
	digitalWrite(leftmotorpin2, LOW);
	delay(time);
}
//--------------------------------------------------------------------------
void right(int time){
	//  Serial.println("Right");
	digitalWrite(rightmotorpin1, HIGH);
	digitalWrite(rightmotorpin2, LOW);

	digitalWrite(leftmotorpin1, LOW);
	digitalWrite(leftmotorpin2, HIGH);
	delay(time);
}

//--------------------------------------------------------------------------
void lights_on(){
  
  digitalWrite(0,HIGH);
  digitalWrite(1,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  
}

//--------------------------------------------------------------------------
void lights_off(){
  digitalWrite(0,LOW);
  digitalWrite(1,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);

}
//--------------------------------------------------------------------------

void get_away_from_the_edge() {
	// Initial get away from the edge (only run once)
	while (getaway < 1){
		forward(400);
		getaway++;
	}
}


