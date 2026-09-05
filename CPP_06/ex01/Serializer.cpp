# include "Serializer.hpp"

//! Nunca se va a ver el mensaje de constructor, destructor, etc. porque la clase es estática y no se puede instanciar.
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

//! El enunciado te pide métodos estáticos; static uintptr_t serialize(...) y static Data* deserialize(...). 
//! En C++, los métodos estáticos no pueden ser virtuales, por eso no puede ser clase abstracta, ademas de no se necesita una clase base.

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
