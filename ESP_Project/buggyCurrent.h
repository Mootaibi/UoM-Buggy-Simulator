#pragma once

#ifndef BUGGYC_H
#define BUGGYC_H

#include "mbed.h"
#include "QEI.h"
#include "C12832.h"

class buggyCurrent {

private:
	AnalogIn rightPin;
	AnalogIn leftPin;
	int currentR;
	int currentL;

public:
	buggyCurrent(PinName pinR, PinName pinL);

//get
	int get_CurrentR(void);
	int get_CurrentL(void);
};

#endif