#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <string>
#include <iostream>

template <typename T>
void easyfind(const T &container, int value);

struct NotFoundException : std::exception
{
	public:
		virtual const char *what() const throw();
};

#include "easyFind.tpp"

#endif