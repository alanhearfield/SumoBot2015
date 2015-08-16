#include <SharpIR.h>

int maximumRange = 45; // Maximum range in cm
int minimumRange = 4; 

#define ir A0
#define model 1080

SharpIR sharp(ir, 25, 93, model);

void setup() {
Serial.begin (9600);  //Commented Out

}

void loop() {

int dis=sharp.distance();  // this returns the distance to the object you're measuring

//if the distance is unreadable, turn left until a reading is made
 if (dis >= maximumRange || dis <= minimumRange){   

 //to indicate "out of range" 
 Serial.println("Out of range! :(");  //Commented Out

 }
 else {
  //drive_forward into enemy

 Serial.print(dis);  //Commented Out
 Serial.println(" cm");  //Commented Out
Serial.println("Charge"); 
  
 }

 //Delay 50ms before next reading.
 delay(50);
 
}
