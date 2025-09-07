#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

# define GREEN "\033[0;32m"
# define RED "\033[0;31m\033[1m"
# define ORANGE "\001\033[38;5;208m\002"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define YELLOW  "\x1b[33m"
# define ROSE    "\x1B[38;2;255;151;203m"
# define LIGHT_BLUE   "\x1B[38;2;53;149;240m"
# define LIGHT_GREEN  "\x1B[38;2;17;245;120m"
# define GRAY    "\x1B[38;2;176;174;174m"
# define RESET "\033[0m"

class Fixed 
{
    private:
        int _value;
        static const int _bits = 8;

    public:
        // CONSTRUCTORES Y DESTRUCTORES 
        Fixed();
        Fixed(const int value);
        Fixed(const float valorFloat);
        ~Fixed();
        Fixed(const Fixed &orig);

		// GETTERS Y SETTERS
        int getRawBits(void) const;
        void setRawBits(int const raw);

        // FUNCIONES PARA SACAR MAXIMO / MINIMO
        static Fixed&	min(Fixed& numA, Fixed& numB);
		static const Fixed&	min(const Fixed& numA, const Fixed& numB);
		static Fixed&	max(Fixed& numA, Fixed& numB);
		static const	Fixed&	max(const Fixed& numA, const Fixed& numB);

        // OTRAS FUNCIONES 
        int toInt(void) const;
        float toFloat(void) const;

        // SOBRECARGA DE OPERADORES ---
        Fixed& operator=(const Fixed& orig);
        // La sobrecarga del operador "<<" es una funcion global; con el atributo "friend" le estas diciendo 
        // que esta funcion pueda acceder a los valores privados de la clase
        friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

        bool operator<(const Fixed& fixed);
		bool operator<=(const Fixed& fixed);
		bool operator>(const Fixed& fixed);
		bool operator>=(const Fixed& fixed);
		bool operator==(const Fixed& fixed);
		bool operator!=(const Fixed& fixed);

		Fixed operator+(const Fixed&) const;
		Fixed operator-(const Fixed&) const;
		Fixed operator/(const Fixed&) const;
		Fixed operator*(const Fixed&) const;

		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);
};

#endif

