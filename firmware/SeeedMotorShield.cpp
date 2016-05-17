#include "SeeedMotorShield.h"
#include "application.h"

/*----Ardunio to Shield Pinout Controls-----

Are using a Seeed motor shield to drive 2 DC motors
Seeed motor shield uses Arduino pins 8->13
Pin 9 sets the enable and speed of shield outputs 1 & 2
Pin 10 sets the enable and speed of shield outputs 3 & 4
Pin 8 from Uno controls the state of shield output 1
Pin 11 from Uno controls the state of shield output 2
Pin 12 from Uno controls the state of shield output 3
Pin 13 from Uno controls the state of shiled output 4

*/

void SeeedMotorShield::begin() {

    leftmotorForward = D0; // pin 8 --- left motor (+)
    leftmotorspeed = D1; // pin 9 --- left motor speed signal
    rightmotorspeed = D2; // pin 10 --- right motor speed signal
    leftmotorBackward = D3; // pin 11 --- left motor (-)
    rightmotorForward = D4; // pin 12 --- right motor (+)
    rightmotorBackward = D5; // pin 13 --- right motor (-)

    pinMode(leftmotorForward, OUTPUT);
    pinMode(leftmotorBackward, OUTPUT);
    pinMode(leftmotorspeed, OUTPUT);
    pinMode(rightmotorForward, OUTPUT);
    pinMode(rightmotorBackward, OUTPUT);
    pinMode(rightmotorspeed, OUTPUT);
}

void SeeedMotorShield::goForward(int motor, int speed){
    if(motor == 0){
        analogWrite(leftmotorspeed,speed);
        digitalWrite(leftmotorForward,LOW);
        digitalWrite(leftmotorBackward,HIGH);
    }
    else if (motor == 1) {
        analogWrite(rightmotorspeed,speed);
        digitalWrite(rightmotorForward,LOW);
        digitalWrite(rightmotorBackward,HIGH);
    }
}

void SeeedMotorShield::turnLeft(int speed){
    goBackward(MOTORB, speed);
    goForward(MOTORA, speed);
}

void SeeedMotorShield::turnRight(int speed){
    goBackward(MOTORA, speed);
    goForward(MOTORB, speed);
}

void SeeedMotorShield::goBackward(int motor, int speed) {
    if(motor == 0){
        analogWrite(leftmotorspeed,speed);
        digitalWrite(leftmotorBackward,LOW);
        digitalWrite(leftmotorForward,HIGH);
    }
    else if (motor == 1) {
        analogWrite(rightmotorspeed,speed);
        digitalWrite(rightmotorBackward,LOW);
        digitalWrite(rightmotorForward,HIGH);
    }
}

void SeeedMotorShield::Stop(int motor) {
    if(motor == 0){
        digitalWrite(leftmotorspeed,LOW);
    }
    else if (motor == 1) {
        digitalWrite(rightmotorspeed,LOW);
    }
    
}
