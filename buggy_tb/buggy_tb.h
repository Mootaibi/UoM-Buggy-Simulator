#pragma once

#ifndef BUGGYS_TB_H
#define BUGGYS_TB_H

#include "mbed.h"
#include "buggyMotor.h"
#include "buggyEncoder.h"
#include "buggyASensor.h"
#include "buggyDSensor.h"
#include "buggySpeed.h"
#include "tools.h"

void MOTOR_TB_DISPLAY(buggyMotor &m, Potentiometer &ptn, C12832 &lcd);
void MOTOR_TB_MAIN(buggyMotor &m, Potentiometer &ptn1, Potentiometer &ptn2, Joystick &jstck);

void ENCODER_TB_DISPLAY(buggyEncoder &e, C12832 &lcd);

void ASENSOR_TB_DISPLAY(buggyASensor &s, C12832 &lcd);

void SPEED_TB_DISPLAY(buggySpeed &sp, Potentiometer &ptn1, Potentiometer &ptn2, C12832 &lcd);
void SPEED_TB_MAIN(buggySpeed &sp, Potentiometer &ptn1, Potentiometer &ptn2);

#endif