#include "Adc.h"
#include <Arduino.h>

Adc::Adc(int pin, int bits, float voltsMin, float voltsMax)
{
	_pin = pin;
	_valueMax = pow(2, bits);
	_voltsMin = voltsMin;
	_voltsMax = voltsMax;
	_voltsPerVal = (_voltsMax - _voltsMin) / _valueMax;
}

int Adc::read()
{
	return analogRead(_pin);
}

int Adc::readAverage()
{
	int cummulativeValue = 0;
	for(int i = 0; i < ADC_AVERAGING_LENGTH; i++) {
		cummulativeValue += read();
		delay(ADC_AVERAGING_DELAY);
	}
	return cummulativeValue / ADC_AVERAGING_LENGTH;
}

float Adc::readVolts()
{
	return read() * _voltsPerVal;
}

float Adc::readVoltsAverage()
{
	return readAverage() * _voltsPerVal;
}