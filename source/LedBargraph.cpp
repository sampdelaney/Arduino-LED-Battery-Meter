#include "LedBargraph.h"
#include <Arduino.h>

LedBargraph::LedBargraph(int segments, int startPin, float minValue, float maxValue)
{
	// set all the led pins as outputs
	for(int i = 0; i < segments; i++) {
		pinMode(startPin + i, OUTPUT);
	} 
	_minValue = minValue;
	_range = maxValue - minValue;
	_segments = segments;
	_startPin = startPin;
}

void LedBargraph::setValue(float value)
{
	// determine the number of leds to light
	int barHeight = int(((value - _minValue) / _range) * _segments);
	// turn on and off the appropriate leds
	for(int i = 0; i < _segments; i++) {
		digitalWrite(_startPin + i, i <= barHeight ? HIGH : LOW);
	}
}