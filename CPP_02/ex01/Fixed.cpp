# include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << PURPLE << "Default constructor called" << RESET << std::endl;
    this->_value = 0;
}
/**
 * Constructor copia -- Crea un nuevo objeto de la clase, a partir de otro
 */
Fixed::Fixed(const Fixed &orig)
{
    std::cout << ORANGE << "Copy constructor called " << RESET << std::endl;
    this->_value = orig.getRawBits();
}
/**
 * Una sobrecarga del operador de asignación de copia.
 */
Fixed& Fixed::operator=(const Fixed& orig)
{
    std::cout << CYAN << "Copy assignment operator called " << RESET << std::endl;
    if (this != &orig)
    {
        this->_value = this->getRawBits();
    }
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << GREEN << "Destructor called " << RESET << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << BLUE << "getRawBits member function called " << RESET << std::endl;
    return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

int Fixed::toInt(void) const
{

}

float Fixed::toFloat(void) const
{

}

