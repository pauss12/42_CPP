#include "ScalarConverter.hpp"

// FUNCTIONS DUE TO ORTHODOX CANNONICAL FORM --------------------------------------------------------------------
ScalarConverter::ScalarConverter()
{
	std::cout << LIGHT_BLUE << "Scalar Converter default constructor has been called " << RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
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

// FUNCTIONS NEEDED TO THE CONVERSION ------------------------------------------------------------------------------------
static int getType(const std::string& literal)
{
	if (literal.length() == 1 && !std::isdigit(literal[0]))
		return (0); // char
	else if (literal.find('.') == std::string::npos && literal.find('f') == std::string::npos)
		return (1); // int
	else if (literal.find('f') != std::string::npos)
		return (2); // float
	else if (literal.find('.') != std::string::npos)
		return (3); // double
	return (-1);
}

void ScalarConverter::convertChar(const std::string& literal)
{
	char value;

	value = static_cast<char>(atoi(literal.c_str()));
	if (!std::isprint(value))
		std::cout << "char: Non displayable" << std::endl;
	else if (literal.length() >= 3)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: '" << value << "'" << std::endl;
}

void ScalarConverter::convertInt(const std::string& literal, int type)
{
	int valor_int;
	double valor_double;

	valor_int = std::atoi(literal.c_str());
	valor_double = std::atof(literal.c_str());
	if (valor_double != valor_double)
	{
		std::cout << "int: impossible" << std::endl;
		return;
	}
	else if (type == 2 || type == 3 || (type == 1 && literal.length() < 11))
	{
		// Comprobar si esta dentro del rango de enteros
		if (valor_double < MIN_INT || valor_double > MAX_INT)
		{
			std::cout << "int: impossible" << std::endl;
			return ;
		}
		std::cout << "int: " << valor_int << std::endl;
	}
	else
		std::cout << "int: impossible" << std::endl;
}

void ScalarConverter::convertFloat(const std::string& literal, int type)
{
	
}

void ScalarConverter::convertDouble(const std::string& literal, int type)
{
	(void)literal;
	(void)type;
}

// CONVERSION FUNCTION ----------------------------------------------------------------------------------------------------
void ScalarConverter::convert(const std::string& literal)
{
	int	type;

	type = getType(literal);
	// Conversion logic goes here
	if (type == -1)
	{
		std::cout << RED << "ERROR: Invalid literal" << RESET << std::endl;
		return;
	}
	convertChar(literal);
	convertInt(literal, type);
	convertFloat(literal, type);
	convertDouble(literal, type);
}