#pragma once

#ifndef SETUP_TB_H
#define SETUP_TB_H

Joystick jstck(A2, A3, A4, A5, D4);
Potentiometer ptnR(A1);
Potentiometer ptnL(A0);
C12832 lcd(D11, D13, D12, D7, D10);

buggyMotor* motorR = new buggyMotor(PB_15, PB_1, 25, 50, 1);
buggyMotor* motorL = new buggyMotor(PB_13, PB_14, 25, 50, 1);
buggyEncoder* encoderR = new buggyEncoder(PA_11, PA_12, 1024, NC);
buggyEncoder* encoderL = new buggyEncoder(PC_13, PC_14, 1024, NC);

buggyASensor RS(PC_2);
buggyASensor LS(PC_3);
buggyDSensor FRS(PC_15, 1);
buggyDSensor MS(PH_0, 0);
buggyDSensor FLS(PH_1, 1);

buggySpeed spd(encoderR, encoderL, motorR, motorL);

int state = 1;

#endif