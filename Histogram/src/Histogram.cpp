#include <iostream>

#include "Histogram.h"

void Histogram::add(EInteger number)
{
	if (number > Hist::Four)
	{
		std::cout << "Number larger than max allowed value! Returning." << std::endl;
		return;
	}
	if (number < Hist::Zero)
	{
		std::cout << "Number smaller than min allowed value! Returning." << std::endl;
		return;
	}

	if (numbers.size() == 0)
	{
		min = number;
		max = number;
	}

	if (number < min) min = number;
	if (number > max) max = number;
	
	numbers.push_back(number);
	counts[number]++;
}

void Histogram::add(int number)
{
	add(EInteger(number));
}

EInteger Histogram::getMode() const
{
	int idx = 0;
	int maxCount = 0;
	for (int i = 0; i < sizeof(counts) / sizeof(int); i++)
	{
		if (counts[i] > maxCount)
		{
			idx = i;
			maxCount = counts[i];
		}
	}
	return EInteger(idx);
}

EInteger Histogram::getMinValue() const
{
	return min;
}

EInteger Histogram::getMaxValue() const
{
	return max;
}

void Histogram::displayDistribution()
{
	std::cout << "\nDISTRIBUTION:" << std::endl;
	std::cout << std::string(counts[getMode()] + 5, '-') << std::endl;
	for (int i = 0; i < sizeof(counts) / sizeof(int); i++)
	{
		std::cout << i << ": " << std::string(counts[i], '#') << std::endl;
	}
	std::cout << std::string(counts[getMode()] + 5, '-') << std::endl;
}

void Histogram::displayInfo()
{
	std::cout << "\nINFO: " << std::endl;
	std::cout << std::string(10, '-') << std::endl;
	std::cout << "Mode: " << getMode() << std::endl;
	std::cout << "Min: " << getMinValue() << std::endl;
	std::cout << "Max: " << getMaxValue() << std::endl;
	std::cout << std::string(10, '-') << std::endl;
}
