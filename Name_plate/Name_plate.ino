int red = 4;
int green = 2;
int yellow = 3;
int buttongreen = 8;
int buttonyellow = 9;
int buttonred = 10;



int buttongreenstate = 0;
int buttonyellowstate = 0;
int buttonredstate = 0;

int lightmode = 1;

void setup() {

   Serial.begin (9600);  //Commented Out
 pinMode(2,OUTPUT); 
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(10,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(13,OUTPUT);
}

void loop()  {
  digitalWrite(13,LOW);
buttongreenstate = digitalRead(buttongreen);
//        Serial.println(buttongreen);
  buttonyellowstate = digitalRead(buttonyellow);
//          Serial.println(buttonyellow);
  buttonredstate = digitalRead(buttonred);
//          Serial.println(buttonred);
  if (buttongreenstate == HIGH) {
    lightmode = 1;
        Serial.print("Green ");
        Serial.println(buttongreenstate);
  }
  else if(buttonyellowstate == HIGH) {
    lightmode = 2;
        Serial.print("Yellow ");
        Serial.println(buttonyellowstate);
  }
  else if (buttonredstate == HIGH) {
    lightmode = 3;
    Serial.print("Red ");
    Serial.println(buttonredstate);
  }
  else {}

  switch(lightmode){
    case 1:
            Serial.println(lightmode);
  greenlight();
    break;
  case 2:
          Serial.println(lightmode);
  yellowlight();
    break;
  case 3:
          Serial.println(lightmode);
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
