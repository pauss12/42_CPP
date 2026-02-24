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
// static int getType(const std::string& literal)
// {
// 	if (literal.length() == 1 && !std::isdigit(literal[0]))
// 		return (0); // char
// 	else if (literal.find('.') == std::string::npos && literal.find('f') == std::string::npos)
// 		return (1); // int
// 	else if (literal.find('f') != std::string::npos)
// 		return (2); // float
// 	else if (literal.find('.') != std::string::npos)
// 		return (3); // double
// 	return (-1);
// }

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// int	ScalarConverter::getType(std::string str)
// {
// 	bool	dot_found = false;
// 	int		sign = 0;
// 	size_t	i = 0;

// 	if (str.length() == 1 && !isdigit(str[0]) && PRINTABLE(str[0]))
// 		return (0); // char
// 	if (str[0] == '-' || str[0] == '+')
// 	{ 
// 		i++;
// 		sign = 1;
// 		if (!isdigit(str[i]) && !str.compare(i, 3, "inf") && !str.compare(i, 3, "nan"))
// 			return (-1);
// 	}
// 	if (std::isinf(atof(str.c_str())) == 1.0f || std::isinf(atof(str.c_str())) == -1.0f)
// 		return (4); // inf
// 	while(str[i] != '\0')
// 	{
// 		if (str[i] == '.')
// 		{
// 			if (dot_found)
// 				return (-1); // invalid
// 			dot_found = true;
// 		}
// 		else if (!isdigit(str[i]))
// 		{
// 			if (str[i] == 'f' && str[i + 1] == '\0' && dot_found)
// 				return (2); // float

// 		}
// 		i++;
// 	}
// 	if (sign)
// 	if (dot_found)
// 		return (1); // double
// 	return (3); // int
// }

static int getType(const std::string& literal)
{
	if (literal.length() == 1 && !std::isdigit(literal[0]) && std::isprint(literal[0]))
		return (0); // char
	else if (literal.find('.') == std::string::npos && literal.find('f') == std::string::npos)
		return (1); // int
	else if (literal.find('f') != std::string::npos)
		return (2); // float
	else if (literal.find('.') != std::string::npos)
		return (3); // double
	else if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return (4); // inf
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

static bool parseLiteralToDouble(const std::string& literal, int type, double &outDouble)
{
	outDouble = std::atof(literal.c_str());
	if (std::isnan(outDouble))
		return false;
	if (type == 2 || type == 3 || (type == 1 && literal.length() < 11))
		return true;
	return false;
}

void ScalarConverter::convertInt(const std::string& literal, int type)
{
	int valor_int;
	double valor_double;

	if (!parseLiteralToDouble(literal, type, valor_double))
	{
		std::cout << "int: impossible" << std::endl;
		return;
	}
	valor_int = static_cast<int>(valor_double);
	if (valor_double < MIN_INT || valor_double > MAX_INT)
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	std::cout << "int: " << valor_int << std::endl;
}

void ScalarConverter::convertFloat(const std::string& literal, int type)
{
	double valor_double;
	if (!parseLiteralToDouble(literal, type, valor_double))
	{
		std::cout << "float: impossible" << std::endl;
		return ;
	}
	float f = static_cast<float>(valor_double);
	if (type == 2 || type == 3 || (type == 1 && literal.length() < 11))
	{
		if (f < MIN_FLOAT || f > MAX_FLOAT)
		{
			std::cout << "float: impossible" << std::endl;
			return ;
		}
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << f << "f" << std::endl;
	}
	else
		std::cout << "float: impossible" << std::endl;
}

void ScalarConverter::convertDouble(const std::string& literal, int type)
{
	double valor_double;
	if (!parseLiteralToDouble(literal, type, valor_double))
	{
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "double: " << valor_double << std::endl;
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