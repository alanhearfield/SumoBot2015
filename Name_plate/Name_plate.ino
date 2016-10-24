
int green = 2;
int yellow = 3;
<<<<<<< HEAD
int buttongreen = 8;
int buttonyellow = 9;
int buttonred = 10;


=======
int red = 4;

int blue1 = 6;
int blue2 = 7;

int buttongreen = 8;
int buttonyellow = 9;
int buttonred = 10;
>>>>>>> origin/Develop

int buttongreenstate = 0;
int buttonyellowstate = 0;
int buttonredstate = 0;

int lightmode = 1;

void setup() {
<<<<<<< HEAD

   Serial.begin (9600);  //Commented Out
=======
  
//   Serial.begin (9600);  //Commented Out
   
>>>>>>> origin/Develop
 pinMode(2,OUTPUT); 
  pinMode(3,OUTPUT);
<<<<<<< HEAD
  pinMode(10,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(13,OUTPUT);
=======
  pinMode(4,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(13,OUTPUT);

  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
>>>>>>> origin/Develop
}

void loop()  {
  digitalWrite(13,LOW);
<<<<<<< HEAD
buttongreenstate = digitalRead(buttongreen);
//        Serial.println(buttongreen);
=======
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  buttongreenstate = digitalRead(buttongreen);
>>>>>>> origin/Develop
  buttonyellowstate = digitalRead(buttonyellow);
//          Serial.println(buttonyellow);
  buttonredstate = digitalRead(buttonred);
//          Serial.println(buttonred);
  if (buttongreenstate == HIGH) {
    lightmode = 1;
<<<<<<< HEAD
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
=======
//        Serial.println(lightmode);
  }
  else if(buttonyellowstate == HIGH) {
    lightmode = 2;
//        Serial.println(lightmode);
  }
  else if (buttonredstate == HIGH) {
    lightmode = 3;
//    Serial.println(lightmode);
>>>>>>> origin/Develop
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
