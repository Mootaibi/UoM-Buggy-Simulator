#pragma once

#ifndef TOOLS
#define TOOLS

#include "mbed.h"

//Joystick
class Joystick {
    
private:    
    DigitalIn up, down, left, right, fire;
    
public:      
    Joystick(PinName u, PinName d, PinName l, PinName r, PinName f);
            
    bool upPressed(void);
    bool downPressed(void);
    bool leftPressed(void);
    bool rightPressed(void);
    bool firePressed(void);
};

//Potentiometer
class Potentiometer { 

private:     
    AnalogIn inputSignal;     
    int maxVal;
    
public:     
    Potentiometer(PinName pin);     
    
    int amplitude16bit(void);
    float amplitudeMax(int val);
};

#endif