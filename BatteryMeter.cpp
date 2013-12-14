#include "BatteryMeter.h"

BatteryMeter::BatteryMeter(float voltageMin, float voltageMax, Adc* adc)
{
	_voltageMin = voltageMin;
	_voltageMax = voltageMax;
	_adc = adc;
	
	// Arduino 10-bit ADC
	//_adcMax = pow(2, 10) - 1;
	//_adcValPerVolts = (_adcVoltsMax - _adcVoltsMin) / _adcMax;
}

float BatteryMeter::getPercentage()
{
	// determine percentage within min / max
	return (_adc->readVolts() - _voltageMin) / _voltageMax;
}