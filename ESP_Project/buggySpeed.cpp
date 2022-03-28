#include "buggySpeed.h"

buggySpeed::buggySpeed(buggyEncoder re, buggyEncoder le, buggyMotor rm, buggyMotor lm) 
    : rEncoder(re), lEncoder(le), rMotor(rm), lMotor(lm) {
    setSpeedR = 0;
    setSpeedL = 0;
    avgSpeed = 0;
	angularSpeed = 0;
    sampRate = 0;
}

//get
int buggySpeed::get_AvgSpeed(void) {
    calc_AvgSpeed();
    return avgSpeed;
}
int buggySpeed::get_AngularSpeed(void) {
    calc_AngularSpeed();
    return angularSpeed;
}

//set
void buggySpeed::set_SetSpeedR(int val) {
    while (!((rEncoder.get_PulseRate() < (val + 5)) && (rEncoder.get_PulseRate() > (val - 5)))) {
        if (rEncoder.get_PulseRate() > (val + 5)) {
            ++rMotor;
        }
        else if (rEncoder.get_PulseRate() < (val - 5)) {
            --rMotor;
        }
    }
}
void buggySpeed::set_SetSpeedL(int val) {
    while (!((lEncoder.get_PulseRate() < (val + 5)) && (lEncoder.get_PulseRate() > (val - 5)))) {
        if (lEncoder.get_PulseRate() > (val + 5)) {
            ++lMotor;
        }
        else if (lEncoder.get_PulseRate() < (val - 5)) {
            --lMotor;
        }
    }
}
void buggySpeed::set_SampRate(int val) {
    tick.detach();
    tick.attach_us(callback(this, &buggySpeed::calc_AvgSpeed), val);
    sampRate = val;
}

//calc
void buggySpeed::calc_AvgSpeed(void) {
    rEncoder.calc_Speed();
    lEncoder.calc_Speed();
    avgSpeed = (int)((rEncoder.get_Speed()-lEncoder.get_Speed())/2);
}
void buggySpeed::calc_AngularSpeed(void) {
    rEncoder.calc_Speed();
    lEncoder.calc_Speed();
    angularSpeed = (int)((rEncoder.get_Speed()-lEncoder.get_Speed())/1); //replace 1 with distance between wheels
}