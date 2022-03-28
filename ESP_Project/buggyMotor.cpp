#include "buggyMotor.h"

buggyMotor::buggyMotor(PinName pwmpin, PinName dirpin, int dut, int per, int dir) : motorPWMPin(pwmpin), motorDirPin(dirpin) {
    set_DutyC(dut);
    set_Period(per);
    motorDirPin.write(dir);
}

//get
int buggyMotor::get_Direction(void) {
    return motorDirPin.read();
}
int buggyMotor::get_DutyC(void) {
    return dutyC;
}
int buggyMotor::get_Period(void) {
    return period;
}

//set
void buggyMotor::set_Direction(int val) {
    motorDirPin.write(val);
}
void buggyMotor::set_DutyC(int val) {
    motorPWMPin.pulsewidth_us(val);
    dutyC = val;
}
void buggyMotor::set_Period(int val) {
    motorPWMPin.period_us(val);
    period = val;
}

//operator
void buggyMotor::operator ++(void) {
    set_DutyC((get_DutyC() + 1));
}
void buggyMotor::operator --(void) {
    set_DutyC((get_DutyC() - 1));
}