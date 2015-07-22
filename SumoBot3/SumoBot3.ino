int echoPin = 8; // Echo Pin
int trigPin = 9; // Trigger Pin
int LEDPin = 13; // Onboard LED

//Distance Sensor setup
int maximumRange = 200; // Maximum range in cm
int minimumRange = 0; 
long duration, distance; 


//Motor
int motor_left[] = {7, 6};
int motor_right[] = {5, 4};

void setup() {
Serial.begin (9600);  
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(LEDPin, OUTPUT); 
 
 // Setup motors
int i;
for(i = 0; i < 2; i++){
pinMode(motor_left[i], OUTPUT);
pinMode(motor_right[i], OUTPUT);
}

}

void loop() {
//digitalWrite(LEDPin, HIGH);
// digitalWrite(trigPin, LOW); 
// delayMicroseconds(2); // 1 microsecond = 0.000001 seconds
//
// digitalWrite(trigPin, HIGH);
// delayMicroseconds(10); 
//
// digitalWrite(trigPin, LOW);
// duration = pulseIn(echoPin, HIGH, 3000);
// delay(3000);
// //distance (in cm) based on the speed of sound.
//  distance = duration/58.2;    // t = r / c c=speed of sound (340m/s), t=time, r=distance     
//
//
//if (distance >= maximumRange || distance <= minimumRange){
//  Serial.print(distance);
// digitalWrite(LEDPin, LOW);
// Serial.println("Out of range! :(");
////digitalWrite(motor_left[0], HIGH); 
////digitalWrite(motor_left[1], LOW); 
//
////digitalWrite(motor_right[0], LOW); 
////digitalWrite(motor_right[1], HIGH); 
//delay(5);
////break;
//}
//else if (distance <= maximumRange || distance >= minimumRange)
//{
//digitalWrite(LEDPin, HIGH);
//digitalWrite(motor_left[0], HIGH); 
//digitalWrite(motor_left[1], LOW); 
//
//digitalWrite(motor_right[0], HIGH); 
//digitalWrite(motor_right[1], LOW); 
//delay(5);
////break;
// }
//}
//
//

// ... this is the reading loop
    long pulseDuration;
    long distance;
    int tries = 0;
    do
    {
      digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); // 1 microsecond = 0.000001 seconds

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 

 digitalWrite(trigPin, LOW);
 
        pulseDuration = pulseIn( echoPin, HIGH, 5000);
        Serial.println("step 1");
        delay(5000); 
        distance = 0.034 * pulseDuration / 2;
        if ( pulseDuration = 0 ) {
            delay(100);
            pinMode(echoPin, OUTPUT);
            digitalWrite(echoPin, LOW);
            Serial.println("step 2");
            delay(100);
            pinMode(echoPin, INPUT);
        }
    } while (pulseDuration == 0 && ++tries < 3);
    if (pulseDuration == 0)
      // Out of range
      Serial.println("Out of range! :(");
    else
      // Read ok!
      Serial.print(distance);
      }
// --------------------------------------------------------------------------- Drive

void motor_stop(){
digitalWrite(motor_left[0], LOW); 
digitalWrite(motor_left[1], LOW); 

digitalWrite(motor_right[0], LOW); 
digitalWrite(motor_right[1], LOW);

}

void drive_forward(){
digitalWrite(motor_left[0], HIGH); 
digitalWrite(motor_left[1], LOW); 

digitalWrite(motor_right[0], HIGH); 
digitalWrite(motor_right[1], LOW); 
delay(50);

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
//delay(50);

}

