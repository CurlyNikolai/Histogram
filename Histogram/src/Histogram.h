#ifndef HISTOGRAM_H

#define HISTOGRAM_H

#include <vector>

#include "HistogramBase.h"
#include "Log.h"

using namespace Hist;

class Histogram : public HistogramBase
{
public:
	//Histogram();
	Histogram(std::unique_ptr<Logger> logger) : HistogramBase(move(logger)) {};
	~Histogram() {};
	void add(EInteger) override;
	void add(int number);
	EInteger getMode() const override;
	EInteger getMinValue() const override;
	EInteger getMaxValue() const override;

private:
	std::vector<EInteger> numbers;
};

#endif // !HISTOGRAM_H
