#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << LIGHT_BLUE << "Scalar Converter default constructor has been called " << RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	std::cout << BLUE << "Scalar Converter has called the copy constructor " << RESET << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& other)
{
	if (this != &other)
		std::cout << CYAN << "Scalar Converter has called the assignment operator" << RESET << std::endl;	
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << PURPLE << "Scalar Converter has been destroyed" << RESET << std::endl;
}


void ScalarConverter::convert(const std::string& literal)
{
	
}