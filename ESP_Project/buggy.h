#pragma once

#ifndef BUGGY_H
#define BUGGY_H

#include "buggyEncoder.h"
#include "buggyMotor.h"
#include "buggyASensor.h"
#include "buggyDSensor.h"
#include "buggyBattery.h"
#include "buggyCurrent.h"
#include "buggyBLE.h"
#include "buggySensors.h"
#include "buggySpeed.h"
#include "buggyDisplay.h"

class buggy
{

private:
	buggySpeed speedCtrl;
	int defaultS;

public:
	buggy(); //set interruptin callbacks for sensors

//typedef
	typedef enum disp {
		DISP_AVGSPEED, DISP_BATTERY, DISP_CURRENT
	} disp;

//get
	

//set
	void set_DefaultS(int val);
	void set_DisplayCtrl(disp setting);

//alg
	void alg_Control(int speedVal);
	void alg_BLE(void);

//cb
	void cb_FRS(void);
	void cb_FLS(void);
	void cb_MS(void); //create a timeout for 6 meters
	void cb_Check(void);
};

#endif