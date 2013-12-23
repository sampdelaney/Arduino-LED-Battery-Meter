#ifndef ADC_H
#define ADC_H

const int ADC_AVERAGING_LENGTH = 10;
const int ADC_AVERAGING_DELAY = 10;

class Adc
{
public:
	Adc(int pin, int bits, float voltsMin, float voltsMax);
	int read();
	int readAverage();
	float readVolts();
	float readVoltsAverage();
private:
	int _pin;
	int _valueMax;
	float _voltsMax;
	float _voltsMin;
	float _voltsPerVal;
};

#endif /* #ifndef ADC_H */