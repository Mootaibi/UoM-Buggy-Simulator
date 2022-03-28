#include "buggyEncoder.h"

buggyEncoder::buggyEncoder(PinName pina, PinName pinb, int ppr, PinName pini) : encoderMain(pina, pinb, pini, ppr) {
    pulseRate = 0;
    speed = 0;
    time.start();
}

//get
int buggyEncoder::get_PulseRate(void) {
    calc_PulseRate();
    return pulseRate;
}
int buggyEncoder::get_Speed(void) {
    calc_Speed();
    return speed;
}

//calc
void buggyEncoder::calc_PulseRate(void) {
    int sample = encoderMain.getPulses();
    pulseRate = (int)(sample*(1/time.read_us())*1000000);
    encoderMain.reset();
    time.reset();
}
void buggyEncoder::calc_Speed(void) {
    calc_PulseRate();
    speed = (int)(pulseRate*(9.6845/512.0)); //check values are accurate
}