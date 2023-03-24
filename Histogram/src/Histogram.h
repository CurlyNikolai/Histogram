#ifndef HISTOGRAM_H

#define HISTOGRAM_H

#include <vector>

#include "HistogramBase.h"
#include "Log.h"

using namespace Hist;

class Histogram : public HistogramBase
{
public:
	Histogram() : HistogramBase(std::make_unique<Logger>()), min(Zero), max(Four) {};
	Histogram(std::unique_ptr<Logger> logger) : HistogramBase(move(logger)), min(Zero), max(Four) {};

	~Histogram() {};

	void add(EInteger) override;
	void add(int number);
	EInteger getMode() const override;
	EInteger getMinValue() const override;
	EInteger getMaxValue() const override;

	void displayDistribution();

private:
	std::vector<EInteger> numbers {};
	int counts[5] = {0};
	EInteger min, max;
};

#endif // !HISTOGRAM_H
