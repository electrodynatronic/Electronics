#include <math.h>
#include "Ultrasonic.h"
Ultrasonic ultrasonic(10,9);
boolean motion_enabled = true;
int distance_to_collision = 0;
int wheelspeed = 0;

#define ENA 6 // wHITE
#define ENB 5 // Brown
#define IN1 7 // Grey
#define IN2 8 // Purple
#define IN3 11 // Orange
#define IN4 12 // Yellow

#define MAX_SPEED 255
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
#define TESTDISTANCE 50
#define MIN_DISTANCE 40

void loop()
{
  distance_to_collision = ultrasonic.Ranging(CM);
  if (distance_to_collision > 5){
    wheelspeed = min( distance_to_collision+200, MAX_SPEED);
    //wheelspeed = wheelspeed>1;    // Shit's too fast yo
    if( motion_enabled == true && distance_to_collision < TESTDISTANCE && distance_to_collision > MIN_DISTANCE){
      forward(wheelspeed-25, wheelspeed -25);
      delay(200-distance_to_collision);
    } 
    if( motion_enabled == true && distance_to_collision < MIN_DISTANCE){
      reverse(wheelspeed-64, wheelspeed);
      delay(800-distance_to_collision);
    } 
    
    if( motion_enabled == true && distance_to_collision > TESTDISTANCE){
      forward(wheelspeed, wheelspeed);
    } 
//    if( motion_enabled == true && distance_to_collision > 800){
//      halt();
//    } 

  }
  Serial.print(distance_to_collision );
  Serial.println("cm");
    
  delay(100);
}

void halt(){
       Serial.println("stop");
      analogWrite(ENA, 0);
      analogWrite(ENB, 0);
      digitalWrite(IN1, 0);
      digitalWrite(IN2, 0);
      digitalWrite(IN3, 0);
      digitalWrite(IN4, 0);
 
}
void forward(int lspeed, int rspeed){
      Serial.println("full speed ahead");
      analogWrite(ENA, max(100,min(255,lspeed)));
      analogWrite(ENB, max(100,min(255,rspeed-15)));
      digitalWrite(IN1, 1);
      digitalWrite(IN2, 0);
      digitalWrite(IN3, 1);
      digitalWrite(IN4, 0);

  
}

void reverse(int lspeed, int rspeed){
       Serial.println("reverse");
      //analogWrite(ENA, 0);
      //analogWrite(ENB, 0);
      digitalWrite(IN1, 0);
      digitalWrite(IN2, 1);
      digitalWrite(IN3, 0);
      digitalWrite(IN4, 1);
      analogWrite(ENA, max(100,min(255,lspeed)));
      analogWrite(ENB, max(100,min(255,rspeed)));
//      analogWrite(ENA, min(255,lspeed));
//      analogWrite(ENB, min(255,rspeed));
}
