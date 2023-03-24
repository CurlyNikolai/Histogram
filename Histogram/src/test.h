#include <iostream>
#ifndef A_H

class A
{
public:
	A() = delete;
	A(int i) { std::cout << "A: " << i << std::endl; };
};

#endif // !A_H


#ifndef B_H

class B : A
{
public:
	//B();
	B(int i) : A(i) { std::cout << "B: " << i << std::endl; };
};

#endif // !B_H
