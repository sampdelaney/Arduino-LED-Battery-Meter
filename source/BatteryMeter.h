#ifndef BATTERYMETER_H
#define BATTERYMETER_H

#include "Adc.h"

class BatteryMeter
{
public:
	BatteryMeter(float voltageMin, float voltageMax, Adc* adc);
	float getPercentage();
private:
	// used for calculating voltage percentage
	float _voltageMin;
	float _voltageMax;
	// used for converting 
	Adc *_adc;
};
#endif /* #ifndef BATTERYMETER_H*/