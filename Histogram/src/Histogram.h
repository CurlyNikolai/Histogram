#ifndef HISTOGRAM_H

#define HISTOGRAM_H

#include "HistogramBase.h"
#include "Log.h"

using namespace Hist;

class Histogram : private HistogramBase
{
public:
	//Histogram(std::unique_ptr<Logger> logger) : HistogramBase(move(logger)) {};
	Histogram() : HistogramBase(std::make_unique<Logger>()) {};
	virtual void add(EInteger);
	virtual EInteger getMode() const;
	virtual EInteger getMinValue() const;
	virtual EInteger getMaxValue() const ;

private:
};

#endif // !HISTOGRAM_H
