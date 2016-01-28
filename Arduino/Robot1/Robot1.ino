#include <math.h>
#include "Ultrasonic.h"
Ultrasonic ultrasonic(10,9);
boolean motion_enabled = true;
int distance_to_collision = 0;
int wheelspeed = 0;
#define ENA 6
#define ENB 5
#define IN1 7
#define IN2 8
#define IN3 11
#define IN4 12

#define MAX_SPEED 180
void setup() {
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  digitalWrite(ENA, 0);
  digitalWrite(ENB, 0);
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 0);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 0);
}
#define TESTDISTANCE 125
#define MIN_DISTANCE 30

void loop()
{
  distance_to_collision = ultrasonic.Ranging(CM);
  if (distance_to_collision > 5){
    wheelspeed = min( distance_to_collision+25, MAX_SPEED);
    //wheelspeed = wheelspeed>1;    // Shit's too fast yo
    if( motion_enabled == true && distance_to_collision < TESTDISTANCE && distance_to_collision > MIN_DISTANCE){
      Serial.println("turn");
   //   analogWrite(ENA, 0);
   //   analogWrite(ENB, 0);
      digitalWrite(IN1, 1);
      digitalWrite(IN2, 0);
      digitalWrite(IN3, 1);
      digitalWrite(IN4, 0);
      analogWrite(ENA, wheelspeed);
      analogWrite(ENB, wheelspeed>>1);
      delay(distance_to_collision);
    } 
    if( motion_enabled == true && distance_to_collision < MIN_DISTANCE){
      Serial.println("reverse");
      //analogWrite(ENA, 0);
      //analogWrite(ENB, 0);
      digitalWrite(IN1, 0);
      digitalWrite(IN2, 1);
      digitalWrite(IN3, 0);
      digitalWrite(IN4, 1);
      analogWrite(ENA, wheelspeed+60);
      analogWrite(ENB, wheelspeed+60);
    } 
    
    if( motion_enabled == true && distance_to_collision > TESTDISTANCE){
      Serial.println("full speed ahead");
      analogWrite(ENA, wheelspeed);
      analogWrite(ENB, wheelspeed);
      digitalWrite(IN1, 1);
      digitalWrite(IN2, 0);
      digitalWrite(IN3, 1);
      digitalWrite(IN4, 0);
    } 
    if( motion_enabled == true && distance_to_collision > 800){
      Serial.println("stop");
      analogWrite(ENA, 0);
      analogWrite(ENB, 0);
      digitalWrite(IN1, 0);
      digitalWrite(IN2, 0);
      digitalWrite(IN3, 0);
      digitalWrite(IN4, 0);

    } 

  }
  Serial.print(distance_to_collision );
  Serial.println("cm");
    
  delay(100);
}



