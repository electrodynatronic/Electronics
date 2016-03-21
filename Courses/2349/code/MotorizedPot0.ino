/*
  Comments go here
 */

// the setup routine runs once when you press reset:

int setpoint = 0;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  setpoint=analogRead(A0);
  digitalWrite(2, 0);
  digitalWrite(3, 0);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue1 = analogRead(A0);
  int sensorValue2 = analogRead(A1);
  writeBrightness( sensorValue1),

  // print out the value you read:
  Serial.print(sensorValue1);
  Serial.println(", ");
  Serial.println(sensorValue2);
  
  movePotPosition();

//  if (sensorValue2-sensorValue1 >2){
//    Serial.println("Values differ");
//    digitalWrite(2,1);
//    delay(10);
//  }
//  if (sensorValue2-sensorValue1 <2){
//    Serial.println("Values differ");
//    digitalWrite(2,1);
//    delay(10);
//  }
  delay(100);        // delay in between reads for stability
}

void writeBrightness(int brightness){
   analogWrite(6,map(brightness,0,695,0,255));
 
}

void movePotPosition(){
    digitalWrite(3,0);
    digitalWrite(2,0);
  while(analogRead(A0)-analogRead(A1) >2){
    writeBrightness( analogRead(A0)),
    digitalWrite(2,1);
    delay(5);
  }
  digitalWrite(2,0);
  while(analogRead(A1)-analogRead(A0) >2){
    writeBrightness( analogRead(A0)),
    digitalWrite(3,1);
    delay(5);
  }
  digitalWrite(3,0);
  
  
}
