#ifndef SEEEDMOTORSHIELD_H
#define SEEEDMOTORSHIELD_H

#define MOTORA 0
#define MOTORB 1

class SeeedMotorShield{
    private:
        int leftmotorForward; // pin 8 --- left motor (+)
        int leftmotorspeed; // pin 9 --- left motor speed signal
        int rightmotorspeed; // pin 10 --- right motor speed signal
        int leftmotorBackward; // pin 11 --- left motor (-)
        int rightmotorForward; // pin 12 --- right motor (+)
        int rightmotorBackward; // pin 13 --- right motor (-)
    
    public:
        void begin(); 
        void goForward(int motor, int speed);
        void goBackward(int motor, int speed);
        void turnLeft(int speed);
        void turnRight(int speed);
        void Stop(int motor);

};

#endif
