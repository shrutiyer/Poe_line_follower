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
  rightMotor->setSpeed(10);
  leftMotor->setSpeed(10);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

void loop() {
  rightIR_val = analogRead(A0);
  rightIR_val = analogRead(A1);

  if (rightIR_val > leftIR_val && rightIR_val >= 700) {
    leftMotor->run(FORWARD);
  }

  if (leftIR_val > rightIR_val && leftIR_val >= 700) {
    rightMotor->run(FORWARD)
  }

  if (leftIR_val < 700 && rightIR_val < 700) {
    rightMotor->run(FORWARD);
    leftMotor->run(FORWARD);
  }
}
