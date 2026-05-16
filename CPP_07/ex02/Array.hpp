#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>
# include <stdexcept>
# include <cstddef>

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