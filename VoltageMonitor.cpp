#include "VoltageMonitor.h"

VoltageMonitor::VoltageMonitor(float voltageMin, float voltageMax, Adc* adc)
{
	_voltageMin = voltageMin;
	_voltageMax = voltageMax;
	_adc = adc;
	
	// Arduino 10-bit ADC
	//_adcMax = pow(2, 10) - 1;
	//_adcValPerVolts = (_adcVoltsMax - _adcVoltsMin) / _adcMax;
}

float VoltageMonitor::monitorPercentage()
{
	// read the voltage from the ADC using other method
	float voltage = monitorVoltage();
	// determine percentage within min / max
	return (voltage - _voltageMin) / _voltageMax;
}

float VoltageMonitor::monitorVoltage()
{
	// wrapper for the ADC read function
	return _adc->readVolts();
}