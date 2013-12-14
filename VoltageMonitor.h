#ifndef VOLTAGEMONITOR_H
#define VOLTAGEMONITOR_H

#include "Adc.h"

class VoltageMonitor
{
public:
	VoltageMonitor(float voltageMin, float voltageMax, Adc* adc);
	float monitorPercentage();
	float monitorVoltage();
private:
	// used for calculating voltage percentage
	float _voltageMin;
	float _voltageMax;
	// used for converting 
	Adc *_adc;

};
#endif /* #ifndef VOLTAGEMONITOR_H*/