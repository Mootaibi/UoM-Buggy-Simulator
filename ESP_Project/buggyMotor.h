#pragma once

#ifndef BUGGYM_H
#define BUGGYM_H

#include "mbed.h"
#include "QEI.h"
#include "C12832.h"

class buggyMotor {
private:
    PwmOut motorPWMPin;
    DigitalOut motorDirPin;
    int dutyC;
    int period;

public:
    buggyMotor(PinName pwmpin, PinName dirpin, int dut, int per, int dir);

//get
    int get_Direction(void);
    int get_DutyC(void);
    int get_Period(void);

//set
    void set_Direction(int val);
    void set_DutyC(int val);
    void set_Period(int val);

//operator
    void operator ++(void);
    void operator --(void);
};

#endif