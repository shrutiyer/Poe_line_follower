/*
 * Created by Shruti Iyer, William Lu
 * This code integrates both the two motors and
 * the two infrared sensors. It just runs the
 * motors according to the sensors. No PID yet, just
 * very basic sense where the line is code.
 */


#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *rightMotor = AFMS.getMotor(3);
Adafruit_DCMotor *leftMotor = AFMS.getMotor(4);

int rightIR; //Value from infrared sensor 1
int leftIR; //Value from infrared sensor 2

byte updateSpeed = 0; //For changing speeds

byte rightSpeed = 30; //Setting speed for right and left
byte leftSpeed = 30;

void setup() {
  AFMS.begin();
  rightMotor->setSpeed(rightSpeed);
  leftMotor->setSpeed(leftSpeed);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

void loop(){
  
  updateSpeed();
  
  leftIR = analogRead(A0);
  rightIR = analogRead(A1);
  
  Serial.print(leftIR); Serial.print(" "); Serial.print(rightIR); Serial.print(" ");

  if (rightIR > leftIR && rightIR - leftIR >= 200) {
    leftMotor->run(BACKWARD);
    rightMotor->run(FORWARD);
    Serial.println("Turn right.");
  }

  else if (leftIR > rightIR && leftIR - rightIR >= 200) {
    rightMotor->run(BACKWARD);
    leftMotor->run(FORWARD);
    Serial.println("Turn left.");
  }
  
  else if (leftIR - rightIR <= 100 || rightIR - leftIR <= 100) {
    rightMotor->run(BACKWARD);
    leftMotor->run(BACKWARD);
    Serial.println("Go straight.");
  }
}

void updateSpeed() {
  if (Serial.available() > 0){
    updateSpeed = Serial.read();
    rightMotor->setSpeed(updateSpeed);
    leftMotor->setSpeed(updateSpeed);
}


