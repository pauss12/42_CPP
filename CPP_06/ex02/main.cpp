#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
    int random = rand() % 3;

    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

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

void identify(Base& base)
{
	try
	{
		A& a = dynamic_cast<A&>(base);
		(void)a;
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::exception& e) {}
	try
	{
		B& b = dynamic_cast<B&>(base);
		(void)b;
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::exception& e) {}
	try
	{
		C& c = dynamic_cast<C&>(base);
		(void)c;
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::exception& e) {}
	std::cout << "NULL Type" << std::endl;
}

int main()
{
	srand(time(0));

	Base* base = generate();
	
	std::cout << "Identifying base pointer:" << std::endl;
	identify(base);

	std::cout << std::endl << "Identifying base reference:" << std::endl;
	identify(*base);

	delete base;

	return (0);
}