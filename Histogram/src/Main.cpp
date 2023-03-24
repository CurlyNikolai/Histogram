#include "Histogram.h"
#include "test.h"

int main()
{
	//Histogram* h = new Histogram(move(std::make_unique<Logger>()));
	Histogram* h = new Histogram();
	h->add(0);
	h->add(1);
	h->add(2);
	h->add(3);
	h->add(4);
	h->add(5);
	
	std::cout << "min: " << h->getMinValue() << std::endl;
	std::cout << "max: " << h->getMaxValue() << std::endl;
}