#ifndef ADC_H
#define ADC_H

class Adc
{
public:
	Adc(int pin, int bits, float voltsMin, float voltsMax);
	int read();
	float readVolts();
private:
	int _pin;
	int _valueMax;
	float _voltsMax;
	float _voltsMin;
	float _voltsPerVal;
};

#endif /* #ifndef ADC_H */