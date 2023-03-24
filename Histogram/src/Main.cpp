#include "Histogram.h"
#include "RandomEintegergenerator.h"
#include <iostream>

int main()
{
	RandomEintegerGenerator rng;
	Histogram h = Histogram();

	for (int i = 0; i < 100; i++)
	{
		//h.add(rng(Uniform));
		h.add(rng(Binomial));
	}
	
	std::cout << "mode: " << h.getMode() << std::endl;
	std::cout << "min: " << h.getMinValue() << std::endl;
	std::cout << "max: " << h.getMaxValue() << std::endl;
	
	h.displayDistribution();

}