
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

void setup() {
 Serial.begin (9600);  //Commented Out

// Setup motors
  pinMode(rightmotorpin1,OUTPUT);
  pinMode(rightmotorpin2,OUTPUT);
  pinMode(leftmotorpin1,OUTPUT);
  pinMode(leftmotorpin2,OUTPUT);

 
}

void loop()
{

  forward(10);
  /* avoid the edges */
  line_right();
  line_left(); 
}

//--------------------------------------------------------------------------
void line_left()
{
reflectance1 = 1;
 pinMode(sensor1, OUTPUT);
digitalWrite(sensor1, HIGH);
delayMicroseconds(15);
pinMode(sensor1, INPUT);                                          //set pin as input
  while((reflectance1 < 500) && (digitalRead(sensor1) != LOW)){   //timeout at 500
                                                                  // read the pin state, increment counter until state = LOW
       ++ reflectance1;                                           // increment value to be displayed via serial port
       delayMicroseconds(4);  
  } 
  if (reflectance1 < 20){
                    Serial.println(reflectance1);  
                    Serial.println("Sensor 1 Edge detected");  
    reverse(200);
    right(500);

  }
      else {
                Serial.println(reflectance1);     
      }
  }

//--------------------------------------------------------------------------
void line_right(){
reflectance2 = 1;
 pinMode(sensor2, OUTPUT);
digitalWrite(sensor2, HIGH);
delayMicroseconds(15);
pinMode(sensor2, INPUT);                                          //set pin as input
  while((reflectance2 < 500) && (digitalRead(sensor2) != LOW)){   //timeout at 500
                                                                  // read the pin state, increment counter until state = LOW
       ++ reflectance2;                                           // increment value to be displayed via serial port
       delayMicroseconds(4);   
  }
  if (reflectance2 < 20){
                    Serial.println(reflectance2); 
                Serial.println("Sensor 2 Edge detected");  
    reverse(200);
    left(500);
  }
      else {
                Serial.println(reflectance2);     
      }
  }

//--------------------------------------------------------------------------
void motor_stop(){
  digitalWrite(rightmotorpin1,LOW);
  digitalWrite(rightmotorpin2,LOW);
  
  digitalWrite(leftmotorpin1,LOW);
  digitalWrite(leftmotorpin2,LOW);
}
//--------------------------------------------------------------------------
void forward(int time){
//  Serial.println("Forward");
  digitalWrite(rightmotorpin1,LOW);
  digitalWrite(rightmotorpin2,HIGH);
  
  digitalWrite(leftmotorpin1,LOW);
  digitalWrite(leftmotorpin2,HIGH);
  delay(time);
}
//--------------------------------------------------------------------------
void reverse(int time){
//  Serial.println("Backward");
  digitalWrite(rightmotorpin1,HIGH);
  digitalWrite(rightmotorpin2,LOW);
  
  digitalWrite(leftmotorpin1,HIGH);
  digitalWrite(leftmotorpin2,LOW);
  delay(time);
}
//--------------------------------------------------------------------------
void left(int time){
//  Serial.println("Left");
  digitalWrite(rightmotorpin1,LOW);
  digitalWrite(rightmotorpin2,HIGH);
  
  digitalWrite(leftmotorpin1,HIGH);
  digitalWrite(leftmotorpin2,LOW);
  delay(time);
}
//--------------------------------------------------------------------------
void right(int time){
//  Serial.println("Right");
  digitalWrite(rightmotorpin1,HIGH);
  digitalWrite(rightmotorpin2,LOW);
  
  digitalWrite(leftmotorpin1,LOW);
  digitalWrite(leftmotorpin2,HIGH);
  delay(time);
}
