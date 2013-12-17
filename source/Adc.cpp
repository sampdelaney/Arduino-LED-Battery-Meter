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

float Adc::readVolts()
{
	return read() * _voltsPerVal;
}