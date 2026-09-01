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
		else if (!std::isdigit(literal[i]))
			return (UNDEFINED);
		i++;
	}
	if (dot_found == 1)
		return (DOUBLE);
	else if (dot_found == 0)
		return (INT);
	return (UNDEFINED);
}

static bool isIntegralValue(double value)
{
	return (std::floor(value) == value);
}

void	ScalarConverter::convertChar(const std::string& literal)
{
	if (literal.length() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0])))
    {
        std::cout << "char: '" << literal[0] << "'" << std::endl;
        return;
    }

    double val = std::atof(literal.c_str());

	if (!isIntegralValue(val))
	{
		std::cout << "char: impossible" << std::endl;
		return;
	}

    // Si es NaN, Inf o se sale del rango de la tabla ASCII (0 a 127)
    if (std::isnan(val) || std::isinf(val) || val < 0 || val > 127)
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }

    int iv = static_cast<int>(val);
	if (iv == 127)
	{
		std::cout << "char: impossible" << std::endl;
		return;
	}
    if (std::isprint(iv))
        std::cout << "char: '" << static_cast<char>(iv) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::convertInt(const std::string& literal, int type)
{
	if (type == CHAR)
	{
		std::cout << "int: impossible" << std::endl;
		return;
	}

	double val = std::atof(literal.c_str());

    if (std::isnan(val) || std::isinf(val) || val < MIN_INT || val > MAX_INT || !isIntegralValue(val))
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }

	if (type == INT)
		std::cout << "int: " << static_cast<int>(val) << " ";
	else
		std::cout << "int: " << static_cast<int>(val) << std::endl;
}

void ScalarConverter::convertFloat(const std::string& literal, int type)
{
	if (type == CHAR)
	{
		std::cout << "float: impossible" << std::endl;
		return;
	}

	// 1. Manejo explícito de pseudo-literals (nan, inf)
    if (type == NOT_A_NUMBER || type == INF)
    {
        if (literal.find("-inf") != std::string::npos)
            std::cout << "float: -inff" << std::endl;
        else if (literal.find("inf") != std::string::npos)
            std::cout << "float: inff" << std::endl;
        else
            std::cout << "float: nanf" << std::endl;
        return;
    }

    // 2. Conversión normal para números
    double valor_double = std::atof(literal.c_str());

	if (type == DOUBLE && !isIntegralValue(valor_double))
	{
		std::cout << "float: impossible" << std::endl;
		return;
	}

    float f = static_cast<float>(valor_double);
    
    std::cout << "float: " << f;
    
    // Imprime .0 solo si es entero puro
    if (f == static_cast<long long>(f))
        std::cout << ".0";
        
    std::cout << "f" << std::endl;
}

void ScalarConverter::convertDouble(const std::string& literal, int type)
{
	if (type == CHAR)
	{
		std::cout << "double: impossible" << std::endl;
		return;
	}

	// 1. Manejo explícito de pseudo-literals (nan, inf)
    if (type == NOT_A_NUMBER || type == INF)
    {
        if (literal.find("-inf") != std::string::npos)
            std::cout << "double: -inf" << std::endl;
        else if (literal.find("inf") != std::string::npos)
            std::cout << "double: inf" << std::endl;
        else
            std::cout << "double: nan" << std::endl;
        return;
    }

    // 2. Conversión normal para números
    double valor_double = std::atof(literal.c_str());

	if (type == FLOAT && !isIntegralValue(valor_double))
	{
		std::cout << "double: impossible" << std::endl;
		return;
	}

    std::cout << "double: " << valor_double;

    if (valor_double == static_cast<long long>(valor_double))
        std::cout << ".0";
        
    std::cout << std::endl;
}

// CONVERSION FUNCTION ----------------------------------------------------------------------------------------------------
void ScalarConverter::convert(const std::string& literal)
{
	int	type;

	type = getVariableType(literal);
	if (type == UNDEFINED)
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible" << std::endl;
		return;
	}
	convertChar(literal);
	convertInt(literal, type);
	convertFloat(literal, type);
	convertDouble(literal, type);
}