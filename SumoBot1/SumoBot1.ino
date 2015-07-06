int trigger = 9;
int echo = 8;
int motor1right = 5;
int motor1left = 4;
int motor2right = 7;
int motor2left = 6;
int distance = 0;
int line1 = 0; 
int line2 = 0; 

void setup() {
pinMode(trigger, OUTPUT);
pinMode(echo, INPUT);
pinMode(motor1right, OUTPUT);
pinMode(motor1left, OUTPUT);
pinMode(motor2right, OUTPUT);
pinMode(motor2left, OUTPUT);
}

void loop() {
line1 = digitalRead(2);
line2 = digitalRead(3);
digitalWrite(trigger, HIGH);
delayMicroseconds(5);
digitalWrite(trigger, LOW);
distance = pulseIn(echo, HIGH);
{if (distance <= 1500){
digitalWrite(motor1right, LOW);
digitalWrite(motor1left, HIGH);
digitalWrite(motor2right, LOW);
digitalWrite(motor2left, HIGH);
}
else if (line1 > 900 or line2 > 900){
digitalWrite(motor1right, LOW);
digitalWrite(motor1left, HIGH);
digitalWrite(motor2right, HIGH);
digitalWrite(motor2left, LOW);
}
else {
digitalWrite(motor1right, HIGH);
digitalWrite(motor1left, LOW);
digitalWrite(motor2right, LOW);
digitalWrite(motor2left, HIGH);
}}
}
