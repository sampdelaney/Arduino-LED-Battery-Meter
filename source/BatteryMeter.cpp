#include "BatteryMeter.h"

BatteryMeter::BatteryMeter(float voltageMin, float voltageMax, Adc* adc)
{
	_voltageMin = voltageMin;
	_voltageMax = voltageMax;
	_adc = adc;
}

float BatteryMeter::getPercentage()
{
	// determine percentage within min / max
	return (_adc->readVolts() - _voltageMin) / _voltageMax;
}