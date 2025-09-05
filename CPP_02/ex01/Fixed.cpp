# include "Fixed.hpp"

/**
 * Constructor por defecto -- Inicializa el valor de la clase en 0.
 * El valor de _bits se inicializa desde la clase en 8, ya que es una constante.
 */
Fixed::Fixed()
{
    std::cout << PURPLE << "Default constructor called" << RESET << std::endl;
    this->_value = 0;
}

Fixed::Fixed(int const value)
{
    std::cout << YELLOW << "Int constructor called" << RESET << std::endl;
    this->_value = value << _bits;
}

/**
 * Una sobrecarga del operador de asignación de copia.
 * El valor de _bits se inicializa desde la clase en 8, ya que es una constante.
 */
Fixed& Fixed::operator=(const Fixed& orig)
{
    if (this != &orig)
    {
        std::cout << CYAN << "Copy assignment operator called " << RESET << std::endl;
        this->_value = orig._value;
    }
    return (*this);
}

Fixed::Fixed(float const value)
{
    std::cout << ROSE << "Float constructor called" << RESET << std::endl;
    this->_value = static_cast<int>(roundf(value * (1 << _bits)));
}

/**
 * Constructor copia -- Crea un nuevo objeto de la clase, a partir de otro
 * El valor de _bits se inicializa desde la clase en 8, ya que es una constante.
 */
Fixed::Fixed(const Fixed &orig)
{
    std::cout << ORANGE << "Copy constructor called " << RESET << std::endl;
    *this = orig;
}

/**
 * Destructor, en este caso, no hace nada. 
 * En el caso de que se hubiera reservado memoria dinamica, esta funcion se 
 * encargaria de liberarla.
 */
Fixed::~Fixed()
{
    std::cout << GREEN << "Destructor called " << RESET << std::endl;
}

/**
 * Getter 
 * Devuelve el valor de la clase.
 */
int Fixed::getRawBits(void) const
{
    return (this->_value);
}

/**
 * Setter
 * Asigna el valor de la clase.
 */
void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

/**
 * Convierte el valor a un entero.
 */
int Fixed::toInt(void) const
{
    return (this->_value >> _bits);
}

/**
 * Convierte el valor a un numero en punto flotante.
 */
float Fixed::toFloat(void) const
{
    return static_cast<float>(this->_value) / (1 << this->_bits);
}

/**
 * Sobrecarga del operador << para poder imprimir datos de la clase.
 */
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << LIGHT_GREEN << fixed.toFloat() << RESET;
    return os;
}