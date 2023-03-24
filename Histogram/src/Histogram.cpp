#include <limits>
#include "Histogram.h"
#include <iostream>

int MIN = std::numeric_limits<int>::min();
int MAX = std::numeric_limits<int>::max();

void Histogram::add(EInteger number)
{
	numbers.push_back(number);
}

void Histogram::add(int number)
{
	add((EInteger)number);
}

EInteger Histogram::getMode() const
{
	//for (auto i : numbers)
	//{

	//}
	return EInteger();
}

EInteger Histogram::getMinValue() const
{
	int currentMin = MAX;
	for (auto i : numbers)
	{
		if ((int)i < currentMin) currentMin = i;
	}
	return (EInteger)currentMin;
}

EInteger Histogram::getMaxValue() const
{
	int currentMax = MIN;
	for (auto i : numbers)
	{
		if ((int)i > currentMax) currentMax = i;
	}
	return (EInteger)currentMax;
}
