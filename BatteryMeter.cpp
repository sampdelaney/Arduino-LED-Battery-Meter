#include "BatteryMeter.h"

BatteryMeter::BatteryMeter(float voltageMin, float voltageMax, Adc* adc)
{
	_voltageMin = voltageMin;
	_voltageMax = voltageMax;
	_voltageRange = voltageMax - voltageMin;
	_adc = adc;
}

float BatteryMeter::getPercentage()
{
	// determine percentage within range
	return (_adc->readVolts() - _voltageMin) / _voltageRange;
}
