#include "tools.h"

//Joystick
Joystick::Joystick(PinName u, PinName d, PinName l, PinName r, PinName f) : up(u), down(d), left(l), right(r), fire(f) {}
            
bool Joystick::upPressed(void) {
    return up.read();
}
bool Joystick::downPressed(void) {
    return down.read();
}
bool Joystick::leftPressed(void) {
    return left.read();
}
bool Joystick::rightPressed(void) {
    return right.read();
}
bool Joystick::firePressed(void) {
    return fire.read();
}

//Potentiometer
Potentiometer::Potentiometer(PinName pin) : inputSignal(pin) {} 
              
int Potentiometer::amplitude16bit(void) { 
    return (int)inputSignal.read_u16(); 
}
float Potentiometer::amplitudeMax(int val) { 
    return inputSignal.read()*val;
}