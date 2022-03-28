#include "buggyDSensor.h"

buggyDSensor::buggyDSensor(PinName pin) : sensorPin(pin) {}

//get
int buggyDSensor::get_SensorVal(void) {
	return sensorPin.read();
}