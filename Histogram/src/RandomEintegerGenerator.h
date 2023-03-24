#ifndef RANDOMEINTEGERGENERATOR_H

#define RANDOMEINTEGERGENERATOR_H

#include <random>

#include "HistogramBase.h"

using namespace Hist;

enum dist
{
	Uniform = 0,
	Binomial = 1,
};

class RandomEintegerGenerator : public RandomEintegerGeneratorBase
{
public:
	RandomEintegerGenerator();
	EInteger operator()();
	EInteger operator()(dist);

private:
	std::mt19937 mt;
	std::uniform_int_distribution<> dist_uniform;
	std::binomial_distribution<> dist_binom;
};

#endif // !RANDOMEINTEGERGENERATOR_H

