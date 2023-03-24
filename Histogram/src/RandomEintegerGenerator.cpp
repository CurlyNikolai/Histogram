#include "RandomEintegerGenerator.h"

RandomEintegerGenerator::RandomEintegerGenerator()
{
	mt = std::mt19937((unsigned)time(nullptr));
	dist_uniform = std::uniform_int_distribution<>(0, 4);
	dist_binom = std::binomial_distribution(4, 0.5f);
}

EInteger RandomEintegerGenerator::operator()()
{
	return EInteger(dist_uniform(mt));
}

EInteger RandomEintegerGenerator::operator()(dist d)
{
	switch (d)
	{
	case Uniform:
		return EInteger(dist_uniform(mt));
		break;
	case Binomial:
		return EInteger(dist_binom(mt));
		break;
	default:
		return EInteger(dist_uniform(mt));
		break;
	}
}