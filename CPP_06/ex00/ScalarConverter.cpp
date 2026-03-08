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
static int getVariableType(const std::string& literal)
{
	std::string::size_type i;
	int dot_found;

	i = 0;
	dot_found = 0;
	if (literal.size() == 1 && !std::isdigit(literal[0]) && std::isprint(literal[0]))
		return (CHAR);
	// Caso en el que encuentre un "nan"
	if (!std::isdigit(literal[0]) && (literal == "nan" || literal == "nanf"))
		return (NOT_A_NUMBER);
	if (!std::isdigit(literal[0]) && std::isinf(std::atof(literal.c_str())))
		return (INF);
	if (literal[0] == '-' || (literal[0] == '+' && literal.size() > 1))
		i++;
	while (i < literal.length())
	{
		// ¿Es Float?
		if (literal[i] == '.')
		{
			if (dot_found == 1)
				return (UNDEFINED);
			dot_found = 1;
		}
		else if (literal[i] == 'f')
		{
			if (dot_found == 0)
				return (UNDEFINED);
			return (FLOAT);
		}
		i++;
	}
	if (dot_found == 1)
		return (DOUBLE);
	else if (dot_found == 0)
		return (INT);
	return (UNDEFINED);
}

static bool parseLiteralToDouble(const std::string& literal, int type, double &outDouble)
{
	outDouble = std::atof(literal.c_str());
	return (type == INT || type == FLOAT || type == DOUBLE || 
			type == INF || type == NOT_A_NUMBER);
}

void	ScalarConverter::convertChar(const std::string& literal)
{
	if (literal.length() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0])) && std::isprint(static_cast<unsigned char>(literal[0])))
	{
		std::cout << "char: '" << literal[0] << "'" << std::endl;
		return;
	}
	double val = std::atof(literal.c_str());
	if (!parseLiteralToDouble(literal, INT, val))
	{
		std::cout << "char: impossible" << std::endl;
		return;
	}
	if (std::isnan(val) || std::isinf(val))
	{
		std::cout << "char: impossible" << std::endl;
		return;
	}
	if (val != static_cast<int>(val))
	{
		std::cout << "char: impossible" << std::endl;
		return;
	}
	int iv = static_cast<int>(val);
	unsigned char c = static_cast<unsigned char>(iv);
	if (std::isprint(c))
		std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::convertInt(const std::string& literal, int type)
{
	double valor_double;

	if (!parseLiteralToDouble(literal, type, valor_double))
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	if (type == 2 || type == 3 || (type == 1 && literal.length() < 11))
	{
		if (valor_double < MIN_INT || valor_double > MAX_INT)
		{
			std::cout << "int: impossible" << std::endl;
			return ;
		}
		int i = static_cast<int>(valor_double);
		std::cout << "int: " << i << std::endl;
	}
	else
		std::cout << "int: impossible" << std::endl;
}

void ScalarConverter::convertFloat(const std::string& literal, int type)
{
	double valor_double;
	if (!parseLiteralToDouble(literal, type, valor_double))
	{
		std::cout << "float: impossible" << std::endl;
		return ;
	}
	std::cout << std::fixed << std::setprecision(1);
	if (type == FLOAT || type == INF || type == NOT_A_NUMBER || (type == INT && literal.length() < 11))
	{
		if (valor_double < MIN_FLOAT || valor_double > MAX_FLOAT)
		{
			std::cout << "float: impossible" << std::endl;
			return ;
		}
		float f = static_cast<float>(valor_double);
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

	type = getVariableType(literal);
	if (type == UNDEFINED)
	{
		std::cout << RED << "ERROR: Invalid literal" << RESET << std::endl;
		return;
	}
	convertChar(literal);
	convertInt(literal, type);
	convertFloat(literal, type);
	convertDouble(literal, type);
}