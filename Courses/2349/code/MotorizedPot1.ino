/*
  Comments go here
 
 An example of using the Arduino board to receive data from the 
 computer.  
 */

#define MAX_DELTA 6
boolean newMessage=0;
const int ledPin = 13; // the pin that the LED is attached to
int incomingData=0;      // a variable to read incoming serial data into
int oldData=0;
int setpoint;
int potVal;
byte message[3];

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  setpoint=analogRead(A0);
  potVal=setpoint;
      Serial.print("setpoint: ");
  Serial.println(setpoint);
  digitalWrite(2, 0);
  digitalWrite(3, 0);
}

void loop() {
  // see if there's incoming serial data:
  while (Serial.available() >0) {
//    Serial.println("Got some data");
    
    incomingData = Serial.parseInt();
     Serial.print("Got an instruction! ");
     newMessage=1;
    Serial.println(incomingData);
//    Serial.println(incomingData);
//    incomingData = Serial.parseInt();
//    Serial.println(incomingData);
//    incomingData = Serial.parseInt();
//    Serial.println(incomingData);
    //message[i]=Serial.read();
     //movePotPosition();
//    Serial.println("done");

  }
  if(abs(incomingData - setpoint) > MAX_DELTA && newMessage == 1){
    Serial.print("My setpoint doesn't match remote setpoint! Delta is: ");
    Serial.print(abs(incomingData - setpoint));
    Serial.print(", incoming data: ");
    Serial.println(incomingData);
    writePotPosition(incomingData);
    newMessage=0;
    //setpoint = incomingData;
    delay(10);
  }
  else if (abs(incomingData - setpoint) < MAX_DELTA && newMessage == 1){
    Serial.print("Setpoint is close enough! Delta is: ");
    Serial.print(abs(incomingData - setpoint));
    setpoint=incomingData;
    newMessage=0;
  }
  if ( abs(getPotVal() - setpoint) > MAX_DELTA){
    
   // Looks like someone manually moved the pot
    Serial.print("Someone moved the pot!, potval: ");
    Serial.print(getPotVal());
    int k=0;
    while(abs(getPotVal()-getPotVal()>MAX_DELTA)){
      k++;
      Serial.println("Simmah down now.");
      if(k>10) break;
    }
    Serial.print(", Tell the others that the new setpoint is: ");
    Serial.println(getPotVal()); 
    setpoint = getPotVal();  //update the setpoint
    writePotPosition(setpoint);
  
  }
}
int getPotVal(){
  int i;
  int val=0;
 for( i=0; i<5; i++){
   delay(11);
   val += analogRead(A0);
 }
 return val/5;
 }
void writePotPosition(int pos){
  if(pos <= 1023 && pos >=0){  
    int val=getPotVal();
    Serial.print("Moving to new pot position: ");
    digitalWrite(3,0);
    digitalWrite(2,0);
    while (abs(analogRead(A0)-pos)>MAX_DELTA){
      while(pos-analogRead(A0) > MAX_DELTA && analogRead(A0) < 1023){ //increasing
        digitalWrite(3,1);
      }
      digitalWrite(3,0);
      while(analogRead(A0)-pos >MAX_DELTA && analogRead(A0) > 0){ //decreasing
        digitalWrite(2,1);
      }
      digitalWrite(2,0);
 // setpoint=pos;
    }
  }
}



void movePotPosition(){
    digitalWrite(3,0);
    digitalWrite(2,0);
  while(analogRead(A0)-analogRead(A1) >2){
//    writeBrightness( analogRead(A0)),
    digitalWrite(2,1);
    delay(5);
    
  }
  digitalWrite(2,0);
  while(analogRead(A1)-analogRead(A0) >2){
//    writeBrightness( analogRead(A0)),
    digitalWrite(3,1);
    delay(5);
  }
  digitalWrite(3,0);
  
  
}
