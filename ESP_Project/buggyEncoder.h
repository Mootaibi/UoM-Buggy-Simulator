#pragma once

#ifndef BUGGYE_H
#define BUGGYE_H

#include "mbed.h"
#include "QEI.h"
#include "C12832.h"

class buggyEncoder {

private:
    QEI encoderMain;
    int pulseRate;
    int speed;
    Timer time;

public:
    buggyEncoder(PinName pina, PinName pinb, int ppr, PinName pini = NC);

 //get
    int get_PulseRate(void);
    int get_Speed(void);

 //calc
    void calc_PulseRate(void);
    void calc_Speed(void);
};

#endif