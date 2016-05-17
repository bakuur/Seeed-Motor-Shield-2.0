// This #include statement was automatically added by the Particle IDE.
#include "SeeedMotorShield.h"

SeeedMotorShield motors;

int runtime = 3000;
int think = 1000;
int speed = 255;


void setup() {
    motors.begin();
}

// ---Main Program Loop -----------------------------

void loop(){
    motors.goForward(MOTORA, speed);
    motors.goForward(MOTORB, speed);
    delay(runtime);
    
    motors.Stop(MOTORA);
    motors.Stop(MOTORB);
    delay(think);
    
    motors.goBackward(MOTORA, speed);
    motors.goBackward(MOTORB, speed);
    delay(runtime);
    
    motors.turnLeft(speed);
    delay(runtime);
    
    motors.turnRight(speed);
    delay(runtime);
}

