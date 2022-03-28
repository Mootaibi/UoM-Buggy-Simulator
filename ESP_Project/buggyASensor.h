#pragma once

#ifndef BUGGYAS_H
#define BUGGYAS_H

#include "mbed.h"
#include "QEI.h"
#include "C12832.h"

class buggyASensor {

private:
	AnalogIn sensorPin;

public:
	buggyASensor(PinName pin);

//get
	int get_SensorVal(void);
};

#endif