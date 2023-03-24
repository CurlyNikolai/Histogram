#ifndef RANDOMEINTEGERGENERATOR_H

#define RANDOMEINTEGERGENERATOR_H

#include <random>

#include "HistogramBase.h"

using namespace Hist;

/**
 * Random number distribution enum.
 * Picks which distribution is used when sampling random EIntegers.
 */
enum dist
{
	Uniform = 0,
	Binomial = 1,
};

/**
 * A class for generating random EIntegers for a histogram
 * Generates random EIntegers with a Mersenne-Twister, from either a uniform or binomial distribution.
 * Restricted to generating EIntegers in the range 0-4 to coincide with the Histogram class.
 * @see Histogram.
 */
class RandomEintegerGenerator : public RandomEintegerGeneratorBase
{
public:
	/**
	 * Constructor for initializing random EInteger generator.
	 * The constructor initializes a mersenne twister rng with distributions to sample from. 
	 * Currently only a uniform and binomial distribution is available.
	 */
	RandomEintegerGenerator();
	
	/**
	 * Default operator for sampling random EIntegers
	 * @return random EInteger
	 */
	EInteger operator()();
	
	/**
	 * Overloaded operator for sampling random EIntegers.
	 * Input enum specifies which distribution to use when sampling EIntegers.
	 * @param dist specifies which distribution to sample from.
	 * @return random EInteger.
	 */
	EInteger operator()(dist);

private:
	std::mt19937 mt;
	std::uniform_int_distribution<> dist_uniform;
	std::binomial_distribution<> dist_binom;
};

#endif // !RANDOMEINTEGERGENERATOR_H

