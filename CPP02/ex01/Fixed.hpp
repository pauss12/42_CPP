#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

# define GREEN "\033[0;32m"
# define RED "\033[0;31m\033[1m"
# define ORANGE "\001\033[38;5;208m\002"
# define RESET "\033[0m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"

class Fixed 
{
    private:
        int _value;
        static const int _bits = 8;

    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float valorFloat);
        ~Fixed();
        Fixed(const Fixed &orig);
        Fixed& operator=(const Fixed& orig);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        int toInt( void ) const;
        float toFloat( void ) const;

        // La sobrecarga del operador "<<" es una funcion global; con el atributo "friend" le estas diciendo 
        // que esta funcion pueda acceder a los valores privados de la clase
        friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
};

#endif

