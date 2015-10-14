
int green = 2;
int yellow = 3;
int red = 4;

int blue1 = 6;
int blue2 = 7;

int buttongreen = 8;
int buttonyellow = 9;
int buttonred = 10;

int buttongreenstate = 0;
int buttonyellowstate = 0;
int buttonredstate = 0;

int lightmode = 1;

void setup() {
  
//   Serial.begin (9600);  //Commented Out
   
 pinMode(2,OUTPUT); 
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(13,OUTPUT);

  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
}

void loop()  {
  digitalWrite(13,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  buttongreenstate = digitalRead(buttongreen);
  buttonyellowstate = digitalRead(buttonyellow);
  buttonredstate = digitalRead(buttonred);
  if (buttongreenstate == HIGH) {
    lightmode = 1;
//        Serial.println(lightmode);
  }
  else if(buttonyellowstate == HIGH) {
    lightmode = 2;
//        Serial.println(lightmode);
  }
  else if (buttonredstate == HIGH) {
    lightmode = 3;
//    Serial.println(lightmode);
  }
  else {}

  switch(lightmode){
    case 1:
  greenlight();
    break;
  case 2:
  yellowlight();
    break;
  case 3:
  redlight();
    break;
  }
}
//**************************************
void redlight()  {
//  Serial.println("RED");
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
 digitalWrite(4,LOW); 
}
//**************************************
void greenlight()  {
//  Serial.println("GREEN");
  digitalWrite(4,HIGH);
  digitalWrite(3,HIGH);
 digitalWrite(2,LOW); 
}
//**************************************
void yellowlight()  {
//    Serial.println("YELLOW");
  digitalWrite(2,HIGH);
  digitalWrite(4,HIGH);
 digitalWrite(3,LOW); 
}
