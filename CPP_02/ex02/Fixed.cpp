# include "Fixed.hpp"

// CONSTRUCTORES Y DESTRUCTORES -----------------------------------------------
Fixed::Fixed()
{
    // std::cout << PURPLE << "Default constructor called" << RESET << std::endl;
    this->_value = 0;
}

Fixed::Fixed(int const value)
{
    // std::cout << YELLOW << "Int constructor called" << RESET << std::endl;
    this->_value = value << _bits;
}

Fixed::Fixed(float const value)
{
    // std::cout << ROSE << "Float constructor called" << RESET << std::endl;
    this->_value = static_cast<int>(roundf(value * (1 << _bits)));
}

Fixed::Fixed(const Fixed &orig)
{
    // std::cout << ORANGE << "Copy constructor called " << RESET << std::endl;
    *this = orig;
}

Fixed::~Fixed()
{
    // std::cout << GREEN << "Destructor called " << RESET << std::endl;
}


// GETTERS Y SETTERS --------------------------------- ----------------------------------
int Fixed::getRawBits(void) const
{
    return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

// FUNCIONES PARA SACAR MÁXIMO / MINIMO -------------------------------------------------------
Fixed&	Fixed::min(Fixed& numA, Fixed& numB)
{
	if (numA < numB)
		return (numA);
	return (numB);
}

const Fixed&	Fixed::min(const Fixed& numA, const Fixed& numB)
{
	if (numA.toFloat() < numB.toFloat())
		return (numA);
	return (numB);
}

Fixed&	Fixed::max(Fixed& numA, Fixed& numB)
{
	if (numA > numB)
		return (numA);
	return (numB);
}

const Fixed&	Fixed::max(const Fixed& numA, const Fixed& numB)
{
	if (numA.toFloat() > numB.toFloat())
		return (numA);
	return (numB);
}

// OTRAS FUNCIONES -----------------------------------------------------------------------------
int Fixed::toInt(void) const
{
    return (this->_value >> _bits);
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(this->_value) / (1 << this->_bits);
}

// SOBRECARGA DE OPERADORES -----------------------------------------------------------------

Fixed& Fixed::operator=(const Fixed& orig)
{
    if (this != &orig)
    {
        // std::cout << CYAN << "Copy assignment operator called " << RESET << std::endl;
        this->_value = orig._value;
    }
    return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << LIGHT_GREEN << fixed.toFloat() << RESET;
    return os;
}

bool Fixed::operator<(const Fixed& fixed)
{
	return (this->_value < fixed._value);
}

bool Fixed::operator<=(const Fixed& fixed)
{
	return (this->_value <= fixed._value);
}

bool Fixed::operator>(const Fixed& fixed)
{
	return (this->_value > fixed._value);
}

bool Fixed::operator>=(const Fixed& fixed)
{
	return (this->_value >= fixed._value);
}

bool Fixed::operator==(const Fixed& fixed)
{
	return (this->_value == fixed._value);
}

bool Fixed::operator!=(const Fixed& fixed)
{
	return (this->_value != fixed._value);
}

Fixed Fixed::operator+(const Fixed& fixed) const
{
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator-(const Fixed& fixed) const
{
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator/(const Fixed& fixed) const
{
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed Fixed::operator*(const Fixed& fixed) const
{
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed& Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_value++;
	return (temp);
}

Fixed& Fixed::operator--()
{
	this->_value--;
	return (*this);
}
Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_value--;
	return (temp);
}