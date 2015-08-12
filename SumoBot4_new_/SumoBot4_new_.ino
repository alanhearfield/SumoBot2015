#include <IRremote.h>
#include <IRremoteInt.h>
#include <SharpIR.h>
//#include <QTRSensors.h>

int maximumRange = 50; // Maximum range in cm
int minimumRange = 4; 
//long duration, distance; 

//sharp ir
#define ir A0
#define model 1080

SharpIR sharp(ir, 25, 93, model);

//Motor
int rightmotorpin1 = 4; 
int rightmotorpin2 = 5; 
int leftmotorpin1 = 6;
int leftmotorpin2 = 7;  

// IR Reciever
IRrecv irrecv(12); // Receive on pin 12
decode_results results;
long lastPressTime = 0;
int state = LOW;
int IRmode = 0;

#define MAX_TIME 150

//int LEDPin = 13; // Onboard LED

//QTR-RC Sensors
int sensor1 = 2;  
int sensor2 = 3;
int reflectance1;
int reflectance2;


//--------------------------------------------------------------

void setup() {
 Serial.begin (9600);  //Commented Out
// pinMode(LEDPin, OUTPUT); 
 pinMode (ir, INPUT);

// Start the receiver
irrecv.enableIRIn(); 

// Setup motors
  pinMode(rightmotorpin1,OUTPUT);
  pinMode(rightmotorpin2,OUTPUT);
  pinMode(leftmotorpin1,OUTPUT);
  pinMode(leftmotorpin2,OUTPUT);
  
  pinMode(1,OUTPUT);
  digitalWrite(1,LOW);

}
//-------------------------------------------------------------
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


 edge_detect();

 int dis=sharp.distance();  // this returns the distance to the object you're measuring

//if the distance is unreadable, turn left until a reading is made
 if (dis >= maximumRange || dis <= minimumRange){   

 //to indicate "out of range" 

Serial.println("Out of range! :(");  //Commented Out
// digitalWrite(LEDPin, LOW); 

 turn_left();
 delay(50);
 motor_stop();
Serial.println("Not detected"); 
 }
 else {
  //drive_forward into enemy
//   digitalWrite(LEDPin, HIGH); 

 drive_forward();

 Serial.print(dis);  //Commented Out
 Serial.println(" cm");  //Commented Out
Serial.println("Charge"); 
 }

 //Delay 50ms before next reading.
 delay(50);
 
 
 
 //  break;
}
}

// --------------------------------------------------------------------------- Drive

void motor_stop(){
  digitalWrite(rightmotorpin1,LOW);
  digitalWrite(rightmotorpin2,LOW);
  
  digitalWrite(leftmotorpin1,LOW);
  digitalWrite(leftmotorpin2,LOW);
//delay(25);
}

void drive_forward(){
  Serial.println("Forward");
  digitalWrite(rightmotorpin1,LOW);
  digitalWrite(rightmotorpin2,HIGH);
  
  digitalWrite(leftmotorpin1,LOW);
  digitalWrite(leftmotorpin2,HIGH);
}

void drive_backward(){
  Serial.println("Backward");
  digitalWrite(rightmotorpin1,HIGH);
  digitalWrite(rightmotorpin2,LOW);
  
  digitalWrite(leftmotorpin1,HIGH);
  digitalWrite(leftmotorpin2,LOW);
}

void turn_left(){
  Serial.println("Left");
  digitalWrite(rightmotorpin1,LOW);
  digitalWrite(rightmotorpin2,HIGH);
  
  digitalWrite(leftmotorpin1,HIGH);
  digitalWrite(leftmotorpin2,LOW);
}

void turn_right(){
  Serial.println("Right");
  digitalWrite(rightmotorpin1,HIGH);
  digitalWrite(rightmotorpin2,LOW);
  
  digitalWrite(leftmotorpin1,LOW);
  digitalWrite(leftmotorpin2,HIGH);
}

void edge_detect()
 
{
 
  reflectance1 = 1;   //initialize value to 1 at the beginning of each loop
  reflectance2 = 1;
  pinMode(sensor1, OUTPUT);   //set pin as output
  pinMode(sensor2, OUTPUT);   //set pin as output
  digitalWrite(sensor1, HIGH);  //set pin HIGH (5V)
  digitalWrite(sensor2, HIGH);  //set pin HIGH (5V)
  delayMicroseconds(15);        //charge capacitor for 15 microseconds
   
  pinMode(sensor1, INPUT);                                          //set pin as input
     while((reflectance1 < 500) && (digitalRead(sensor1) != LOW)){   //timeout at 500
                                                                    // read the pin state, increment counter until state = LOW
          ++ reflectance1;                                           // increment value to be displayed via serial port
              delayMicroseconds(4);                                 //Change value or comment out to adjust value range
      }
  
  if (reflectance1 < 20){
      drive_backward();
      delay(300);
      turn_right();
      delay(300);
            Serial.println("Sensor 1 Edge detected");   
  }
      else {
        Serial.println(reflectance1);       
      }

  pinMode(sensor2, INPUT);                                          //set pin as input
     while((reflectance2 < 500) && (digitalRead(sensor2) != LOW)){   //timeout at 500
                                                                    // read the pin state, increment counter until state = LOW
          ++ reflectance2;                                           // increment value to be displayed via serial port
              delayMicroseconds(4);                                 //Change value or comment out to adjust value range
      }
  
  if (reflectance2 < 20){
      drive_backward();
            delay(300);
      turn_left();
      delay(300);
              Serial.println("Sensor 2 Edge detected");     
  }
      else {
        Serial.println(reflectance1);       
      }
       
  delay(100);
   
}

