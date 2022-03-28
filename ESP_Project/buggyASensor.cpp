#include "buggyASensor.h"

buggyASensor::buggyASensor(PinName pin) : sensorPin(pin) {}

//get
int buggyASensor::get_SensorVal(void) {
	return (int)sensorPin.read_u16();
}