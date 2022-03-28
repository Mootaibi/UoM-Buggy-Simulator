#pragma once

#ifndef BUGGYDS_H
#define BUGGYDS_H

#include "mbed.h"
#include "QEI.h"
#include "C12832.h"

class buggyDSensor {

private:
	InterruptIn sensorPin;

public:
	buggyDSensor(PinName pin);

//get
	int get_SensorVal(void);
};

#endif