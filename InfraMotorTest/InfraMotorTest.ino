/*
 * Created by Shruti Iyer, William Lu
 * This code integrates both the two motors and
 * the two infrared sensors. It just runs the
 * motors according to the sensors. No PID yet.
 */


#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *myMotor1 = AFMS.getMotor(3);
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(4);

int infraVal1; //Value from infrared sensor 1
int infraVal2; //Value from infrared sensor 2

//int Motor1 = 100 //Right motor speed

void setup() {
  // put your setup code here, to run once:
  AFMS.begin();
  myMotor1->setSpeed(10);
  myMotor2->setSpeed(10);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  infraVal1 = analogRead(A0);
  infraVal2 = analogRead(A1);

  if (infraVal1>infraVal2 && infraVal1-infraVal2>=700) {
    myMotor1->run(FORWARD);
  }else if (infraVal2>infraVal1 && infraVal2-infraVal1>=700) {
    myMotor2->run(FORWARD);
    }
}
