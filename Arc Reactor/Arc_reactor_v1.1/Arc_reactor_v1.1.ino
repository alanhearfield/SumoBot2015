
// Initialize Variables
int blinkCycle = 0;
int newLed[7] = {3, 5, 6, 9, 10};
int middleLed = 11;
int i;
int fadeCycle = 0;
void setup() {         
pinMode(middleLed, OUTPUT);
digitalWrite (middleLed, HIGH);


}
void loop() 
{
if (blinkCycle == 10) { // Skip blink if t's already run 6 times
goto fade;
}
for (i = 0; i < 10; i = i + 1)  {
// Blink array in order
analogWrite(newLed[i], 255);
delay(50); // change for slower blinking
analogWrite(newLed[i], 0);
}
if (i == 10) // If finished array...
{
i = 0; // start over
blinkCycle++; // count times through loop
if (blinkCycle == 10) { // blinked x times already, LIGHT IT UP
for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) {  // fade in
analogWrite(newLed[0], fadeValue);
analogWrite(newLed[1], fadeValue);  
analogWrite(newLed[2], fadeValue);
analogWrite(newLed[3], fadeValue);  
analogWrite(newLed[4], fadeValue); 
analogWrite(newLed[5], fadeValue); 
delay(30);                            
}  
delay (6000); // wait between animations
}
}
fade:
if (blinkCycle == 10) { 
Serial.println("DONE");


for(int fadeValue = 255 ; fadeValue >= 10; fadeValue -=5) { // fade out
analogWrite(newLed[0], fadeValue);
analogWrite(newLed[1], fadeValue);  
analogWrite(newLed[2], fadeValue);
analogWrite(newLed[3], fadeValue);  
analogWrite(newLed[4], fadeValue);  
analogWrite(newLed[5], fadeValue); 
delay(30);   
}
for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) {  // fade in
analogWrite(newLed[0], fadeValue);
analogWrite(newLed[1], fadeValue);  
analogWrite(newLed[2], fadeValue);
analogWrite(newLed[3], fadeValue);  
analogWrite(newLed[4], fadeValue); 
analogWrite(newLed[5], fadeValue); 
delay(30);                            
} 
  
fadeCycle++;
if (fadeCycle == 20) { // if faded x times LIGHT IT UP
analogWrite(newLed[0], 255);
analogWrite(newLed[1], 255);  
analogWrite(newLed[2], 255);
analogWrite(newLed[3], 255);  
analogWrite(newLed[4], 255);  
analogWrite(newLed[5], 255); 
delay (6000); // pause inbetween animations
}
}
if (fadeCycle == 20) {
blinkCycle = 0; // reset
fadeCycle = 0; // reset
}
}
