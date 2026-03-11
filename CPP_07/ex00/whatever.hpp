#ifndef WHATEVER_HPP
#define WHATEVER_HPP

# include <iostream>
# include <string>

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
void swap(T &a, T &b)
{
	T aux;

	aux = a;
	a = b;
	b = aux;
}

template <typename S>
S min(S valor_1, S valor_2)
{
	// Siempre devuelve el menor, si son iguales, devuelve el segundo
	if (valor_1 < valor_2)
		return (valor_1);
	return (valor_2);
}

template <typename L>
L max(L valor_1, L valor_2)
{
	// Siempre devuelve el menor, si son iguales, devuelve el segundo
	if (valor_1 > valor_2)
		return (valor_1);
	return (valor_2);
}

#endif