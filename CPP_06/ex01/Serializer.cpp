#include "Serializer.hpp"

Serializer::Serializer() 
{
	std::cout << LIGHT_BLUE << "Serializer default constructor has been called " << RESET << std::endl;
}

Serializer::Serializer(const Serializer& other) 
{
	(void)other;
	std::cout << BLUE << "Serializer copy constructor has been called " << RESET << std::endl;
}

Serializer& Serializer::operator=(const Serializer& other) 
{
	(void)other;
	if (this != &other)
		std::cout << CYAN << "Serializer assignment operator has been called " << RESET << std::endl;
	return (*this);
}

Serializer::~Serializer() 
{
	std::cout << PURPLE << "Serializer destructor has been called " << RESET << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
