#ifndef BATTERYMETER_H
#define BATTERYMETER_H

#include "Adc.h"

class BatteryMeter
{
public:
	BatteryMeter(float voltageMin, float voltageMax, Adc* adc);
	float getPercentage();
private:
	float _voltageMin;
	float _voltageMax;
	float _voltageRange;
	Adc *_adc;
};
#endif /* #ifndef BATTERYMETER_H*/
