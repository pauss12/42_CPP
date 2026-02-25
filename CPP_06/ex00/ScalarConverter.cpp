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
	if (literal.length() == 1 && !std::isdigit(literal[0]) && std::isprint(literal[0]))
		return (CHAR);
	if (!std::isdigit(literal[0]) && !std::isinf(std::atof(literal.c_str())) && !std::isnan(std::atof(literal.c_str())))
		return (UNDEFINED);
	// Caso en el que encuentre un inf
	if (!std::isdigit(literal[0]) && std::isinf(std::atof(literal.c_str())))
		return (INF);
	// Caso en el que encuentre un "nan"
	if (!std::isdigit(literal[0]) && (literal == "nan"))
		return (NOT_A_NUMBER);
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
		return (false);
	if (type == FLOAT || type == DOUBLE || (type == INT && literal.length() < 11))
		return (true);
	return (false);
}

void ScalarConverter::convertInt(const std::string& literal, int type)
{
	int valor_int;
	double valor_double;

	if (!parseLiteralToDouble(literal, type, valor_double))
	{
		std::cout << "int: impossible" << std::endl;
		return ;
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

	type = getVariableType(literal);
	// Conversion logic goes here
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