#pragma once

#ifndef BUGGYB_H
#define BUGGYB_H

#include "mbed.h"
#include "QEI.h"
#include "C12832.h"

class buggyBattery {

private:
	DigitalInOut batteryPin;
	int battery;

public:
	buggyBattery(PinName pin);

//get
	int get_Battery(void);
};

#endif