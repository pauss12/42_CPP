#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(const Base& base)
{
	try
	{
		const A& a = dynamic_cast<const A&>(base);
		(void)a;
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::exception& e) {}
	try
	{
		const B& b = dynamic_cast<const B&>(base);
		(void)b;
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::exception& e) {}
	try
	{
		const C& c = dynamic_cast<const C&>(base);
		(void)c;
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::exception& e) {}
	std::cout << "NULL Type" << std::endl;
}

int main()
{
	// Que aleatoriamente saque una instancia de A, B o C
	Base* base;
	int random;

	srand(time(0));
	random = rand() % 3;
	if (random == 0)
		base = new A();
	else if (random == 1)
		base = new B();
	else
		base = new C();

	// How to idenfify each of then
	std::cout << "Identifying base pointer:" << std::endl;
	identify(base);

	std::cout << std::endl << "Identifying base reference:" << std::endl;
	identify(*base);

	delete base;

	return (0);
}