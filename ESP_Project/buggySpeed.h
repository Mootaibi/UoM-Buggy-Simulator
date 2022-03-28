#pragma once

#ifndef BUGGYS_H
#define BUGGYS_H

#include "buggyEncoder.h"
#include "buggyMotor.h"

class buggySpeed {

private:
	buggyEncoder rEncoder;
	buggyEncoder lEncoder;
	buggyMotor rMotor;
	buggyMotor lMotor;
	int setSpeedR;
	int setSpeedL;
	int avgSpeed;
	int angularSpeed;
	int sampRate;
	Ticker tick;

public:
	buggySpeed(buggyEncoder re, buggyEncoder le, buggyMotor rm, buggyMotor lm);

//get
	int get_AvgSpeed(void);
	int get_AngularSpeed(void);
	
//set
	void set_SetSpeedR(int val);
	void set_SetSpeedL(int val);
	void set_SampRate(int val);

//calc
	void calc_AvgSpeed(void);
	void calc_AngularSpeed(void);
};

#endif