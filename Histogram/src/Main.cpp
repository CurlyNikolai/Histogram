#include "Histogram.h"
#include "RandomEintegergenerator.h"
#include <iostream>
#include <string>
#include <cstdio>

int main()
{
	RandomEintegerGenerator rng;

	Histogram h1 = Histogram();
	for (int i = 0; i < 100; i++)
	{
		h1.add(rng(Uniform));
	}
	
	h1.displayInfo();
	h1.displayDistribution();

	Histogram h2 = Histogram();
	for (int i = 0; i < 100; i++)
	{
		h2.add(rng(Binomial));
	}

	h2.displayInfo();
	h2.displayDistribution();

	std::cout << "Press enter to exit" << std::endl;
	char a = std::getchar();

	return 0;
}