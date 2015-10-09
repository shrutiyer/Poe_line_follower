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

void setup() {
  AFMS.begin();
  rightMotor->setSpeed(20);
  leftMotor->setSpeed(20);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

void loop() {
  leftIR = analogRead(A0);
  rightIR = analogRead(A1);
  
  Serial.print(leftIR); Serial.print(" "); Serial.print(rightIR); Serial.print(" ");

  if (rightIR > leftIR && rightIR - leftIR >= 500) {
    leftMotor->run(BACKWARD);
    rightMotor->run(FORWARD);
    Serial.println("Turn right.");
  }

  else if (leftIR > rightIR && leftIR - rightIR >= 500) {
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
