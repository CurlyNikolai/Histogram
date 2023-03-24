#ifndef HISTOGRAM_H

#define HISTOGRAM_H

#include <vector>

#include "HistogramBase.h"
#include "Log.h"

using namespace Hist;

/**
 * Class for generating a histogram of EIntegers.
 * @see HistogramBase.
 */
class Histogram : public HistogramBase
{
public:
	/**
	 * Default constructor of Histogram.
	 */
	Histogram() : HistogramBase(std::make_unique<Logger>()), min(Zero), max(Four) {};
	/**
	 * Overloaded constructor of Histogram.
	 * @param logger is a unique pointer to a Logger.
	 */
	Histogram(std::unique_ptr<Logger> logger) : HistogramBase(move(logger)), min(Zero), max(Four) {};

	~Histogram() {};

	/**
	 * Method for adding EIntegers to the histogram.
	 * Currently restricted to numbers in the range 0-4.
	 * @param EInteger number to add to histogram.
	 */
	void add(EInteger number) override;
	
	/**
	 * Overloaded method for adding integers to the histogram.
	 * @param int number to add to histogram.
	 */
	void add(int number);

	/**
	 * Gets the most frequently occuring EInteger in histogram.
	 * @return most frequently occuring EInteger.
	 */
	EInteger getMode() const override;

	/**
	 * Gets the smallest value in histogram.
	 * @return minimum EInteger value of histogram.
	 */
	EInteger getMinValue() const override;
	
	/**
	 * Gets the largest value in histogram.
	 * @return maximum EInteger value of histogram.
	 */
	EInteger getMaxValue() const override;

	/**
	 * Helper method to visualize the histogram distribution.
	 */
	void displayDistribution();
	/**
	 * Helper method to visualize histogram information.
	 */
	void displayInfo();

private:
	/**
	 * List of all numbers in histogram.
	 */
	std::vector<EInteger> numbers {};
	/**
	 * Array holding the count of each number in histogram.
	 */
	int counts[5] = {0};
	/**
	 * The minimum value present in the histogram.
	 */
	EInteger min;
	/**
	 * The maxmimum value present in the histogram.
	 */
	EInteger max;
};

#endif // !HISTOGRAM_H
