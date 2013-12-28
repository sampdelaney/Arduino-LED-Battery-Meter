#ifndef LEDBARGRAPH_H
#define LEDBARGRAPH_H

class LedBargraph
{
public:
	LedBargraph(int segments, int startPin, float minValue, float maxValue);
	void setValue(float value);
private:
	float _minValue;
	float _range;
	int _segments;
	int _startPin;
};

#endif /* #ifndef LEDBARGRAPH_H */