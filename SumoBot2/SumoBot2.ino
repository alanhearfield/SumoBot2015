#include <IRremote.h>
#include <IRremoteInt.h>

int echoPin = 8; // Echo Pin
int trigPin = 9; // Trigger Pin
int LEDPin = 13; // Onboard LED

//Motor
int motor_left[] = {7, 6};
int motor_right[] = {5, 4};

// IR Reciever
IRrecv irrecv(12); // Receive on pin 12
decode_results results;
long lastPressTime = 0;
int state = LOW;

int maximumRange = 200; // Maximum range in cm
int minimumRange = 0; 
long duration, distance; 

void setup() {
// Serial.begin (9600);  Commented Out
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(LEDPin, OUTPUT); 

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
 if (irrecv.decode(&results))//have we received an IR signal?

{ 
 translateIR();
    irrecv.resume();} // Receive the next value
}
 //(END MAINLOOP)
 
 void translateIR()  //Takes actions based on IR Code
 {
 switch(results.value)
 
 {
 
 case 0xFF30CF:  
 enemydetection();
 
 }}
 
 
 void enemydetection(){
 delay(3000);
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); // 1 microsecond = 0.000001 seconds

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 

 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH, 3000);

 Serial.println(digitalRead(7));  //Commented Out

 //distance (in cm) based on the speed of sound.
  distance = duration/58.2;    // t = r / c c=speed of sound (340m/s), t=time, r=distance     



 if (distance >= maximumRange || distance <= minimumRange){   //if the distance is unreadable, turn the led off and print "out of range" to serial monitor

 //to indicate "out of range" 

Serial.println("Out of range! :(");  //Commented Out
 digitalWrite(LEDPin, LOW); 
 Serial.println(digitalRead(7));  //Commented Out
 digitalWrite(echoPin, LOW);  //Commented Out
 Serial.println(digitalRead(7));  //Commented Out
 
 turn_right();
 

 }
else  {

 Serial.print(distance);  //Commented Out
 Serial.println(" cm");  //Commented Out
   drive_forward();

 }

 //Delay 50ms before next reading.
 // delay(3000); //Not executed
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
delay(3000);
enemydetection();
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
delay(10);
enemydetection();
}

