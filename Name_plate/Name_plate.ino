int red = 4;
int green = 2;
int yellow = 3;
int buttongreen = 7;
int buttonyellow = 8;
int buttonred = 9;

int buttongreenstate = 0;
int buttonyellowstate = 0;
int buttonredstate = 0;

int lightmode = 1;

void setup() {
 pinMode(2,OUTPUT); 
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
}

void loop()  {
buttongreenstate = digitalRead(buttongreen);
  buttonyellowstate = digitalRead(buttonyellow);
  buttonredstate = digitalRead(buttonred);
  if (buttongreenstate == HIGH) {
    lightmode = 1;
        Serial.println(lightmode);
  }
  else if(buttonyellowstate == HIGH) {
    lightmode = 2;
        Serial.println(lightmode);
  }
  else if (buttonredstate == HIGH) {
    lightmode = 3;
    Serial.println(lightmode);
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
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
 digitalWrite(4,HIGH); 
}
//**************************************
void greenlight()  {
  digitalWrite(4,LOW);
  digitalWrite(3,LOW);
 digitalWrite(2,HIGH); 
}
//**************************************
void yellowlight()  {
  digitalWrite(2,LOW);
  digitalWrite(4,LOW);
 digitalWrite(3,HIGH); 
}
