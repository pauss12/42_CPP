#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>
# include <stdexcept>
# include <cstddef>

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

template <typename T>
class Array
{
    private:
        T *_array;
        unsigned int _size;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array &other);
        Array &operator=(const Array &other);
        ~Array();
        
        T &operator[](unsigned int index);
        const T &operator[](unsigned int index) const;
        unsigned int size(void) const;
};

/**
 *   Se pone abajo del todo porque asi es como el compilador lee el codigo, de abajo hacia arriba
 *  Si ponemos la implementacion de las funciones antes de la clase, el compilador no sabra que es Array<T> y dara error
 * 
 * Lo tratamos como una extension del fichero HPP
*/
#include "Array.tpp"

#endif