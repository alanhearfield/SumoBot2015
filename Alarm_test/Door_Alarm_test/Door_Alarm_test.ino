#include <SharpIR.h>

int maximumRange = 60; // Maximum range in cm
int minimumRange = 4; 

#define ir A0
#define model 1080

SharpIR sharp(ir, 25, 93, model);

int timer = 500;
int timer1 = 50;
int ledPin = 13;           
int piezoPin = 8;
int count = 0;
int buzzer = 0;

void setup() {
Serial.begin (9600);  //Commented Out

pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);
}

void loop() {

int dis = sharp.distance();  
Serial.print(dis);   //Commented Out
Serial.println(" out");  //Commented Out

while (dis < maximumRange){

Serial.print(dis);   //Commented Out
Serial.println(" on");  //Commented Out
dis = sharp.distance();
 delay(100);
}


alarm_on();

 
}

//--------------------------------------------------------------------------
void alarm_on(){
int dis = sharp.distance();
if (count < 5)
{
  dis = sharp.distance();
Serial.print(dis);   //Commented Out
Serial.println(" max");  //Commented Out
dis = sharp.distance();
 delay(100);
 count ++;
 Serial.print(count);  //Commented Out
 Serial.println(" count");  //Commented Out
	}
 else{

while (buzzer < 10)
{
      digitalWrite(ledPin, HIGH);
    tone(piezoPin, 1000, 500);
    delay(200);
  tone(piezoPin, 2500, 500);
//      digitalWrite(ledPin, LOW);
    delay(200);
  tone(piezoPin, 1000, 500);
 //     digitalWrite(ledPin, HIGH);
    delay(200);
//          digitalWrite(ledPin, LOW);
    delay(200);
    buzzer ++;
    Serial.print(buzzer);  //Commented Out
    Serial.println(" buzzer");  //Commented Out
}
 { 
  buzzer = 0;
  count = 0;
}
  
 }
}



