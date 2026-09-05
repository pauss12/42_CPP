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

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	std::srand(std::time(NULL));

	std::cout << "--- TEST 1: Random Generation & Identification ---" << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		Base* randomInstance = generate();

		std::cout << "Test #" << i + 1 << ":" << std::endl;
		std::cout << "  Pointer   -> ";
		identify(randomInstance);
		std::cout << "  Reference -> ";
		identify(*randomInstance);

		delete randomInstance;
		std::cout << "------------------------------------" << std::endl;
	}

	std::cout << "\n--- TEST 2: Null Pointer Handling ---" << std::endl;
	Base* nullPtr = NULL;
	std::cout << "  Pointer   -> ";
	identify(nullPtr);

	return 0;
}