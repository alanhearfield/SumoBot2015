#include <IRremote.h>
#include <IRremoteInt.h>
#include <SharpIR.h>

int maximumRange = 70; // Maximum range in cm
int minimumRange = 4; 
//long duration, distance; 

//sharp ir
#define ir A0
#define model 1080

SharpIR sharp(ir, 25, 93, model);

//Motor
int motor_left[] = {7, 6};
int motor_right[] = {5, 4};

// IR Reciever
IRrecv irrecv(12); // Receive on pin 12
decode_results results;
long lastPressTime = 0;
int state = LOW;
int IRmode = 0;

#define MAX_TIME 150

int LEDPin = 13; // Onboard LED

void setup() {
 Serial.begin (9600);  //Commented Out
 pinMode(LEDPin, OUTPUT); 
 pinMode (ir, INPUT);

// Start the receiver
irrecv.enableIRIn(); 

// Setup motors
int i;
for(i = 0; i < 2; i++){
pinMode(motor_left[i], OUTPUT);
pinMode(motor_right[i], OUTPUT);
}
}

void loop() {

// Wait for IR remote button press
switch(IRmode)
{
case 0:

if (irrecv.decode(&results)) {
  if (0xFF6897) {  // Can check for a specific button here
    IRmode = 1;
    Serial.print("ON");
  }
   irrecv.resume();} // Receive the next value
break;
case 1:


 int dis=sharp.distance();  // this returns the distance to the object you're measuring

//if the distance is unreadable, turn left until a reading is made
 if (dis >= maximumRange || dis <= minimumRange){   

 //to indicate "out of range" 

Serial.println("Out of range! :(");  //Commented Out
 digitalWrite(LEDPin, LOW); 


digitalWrite(motor_left[0], LOW); 
digitalWrite(motor_left[1], HIGH); 

digitalWrite(motor_right[0], HIGH); 
digitalWrite(motor_right[1], LOW);
 }
 else {
  //drive_forward into enemy
   digitalWrite(LEDPin, HIGH); 
digitalWrite(motor_left[0], HIGH); 
digitalWrite(motor_left[1], LOW); 

digitalWrite(motor_right[0], HIGH); 
digitalWrite(motor_right[1], LOW); 


 Serial.print(dis);  //Commented Out
 Serial.println(" cm");  //Commented Out

 }

 //Delay 50ms before next reading.
 delay(50);
 
 
 
 //  break;
}
}

// --------------------------------------------------------------------------- Drive

void motor_stop(){
digitalWrite(motor_left[0], LOW); 
digitalWrite(motor_left[1], LOW); 

digitalWrite(motor_right[0], LOW); 
digitalWrite(motor_right[1], LOW);
delay(25);
}

void drive_forward(){
digitalWrite(motor_left[0], HIGH); 
digitalWrite(motor_left[1], LOW); 

digitalWrite(motor_right[0], HIGH); 
digitalWrite(motor_right[1], LOW); 
}

void drive_backward(){
digitalWrite(motor_left[0], LOW); 
digitalWrite(motor_left[1], HIGH); 

digitalWrite(motor_right[0], LOW); 
digitalWrite(motor_right[1], HIGH); 
}

void turn_left(){
digitalWrite(motor_left[0], LOW); 
digitalWrite(motor_left[1], HIGH); 

digitalWrite(motor_right[0], HIGH); 
digitalWrite(motor_right[1], LOW);
}

void turn_right(){
digitalWrite(motor_left[0], HIGH); 
digitalWrite(motor_left[1], LOW); 

digitalWrite(motor_right[0], LOW); 
digitalWrite(motor_right[1], HIGH); 
}

