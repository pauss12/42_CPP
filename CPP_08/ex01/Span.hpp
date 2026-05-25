#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <stdexcept>

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

class Span
{
    private:
        std::vector<int> _numbers;
        unsigned int _maxSize;

    public:
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        // Agrega un número al Span
        void addNumber(int num);
        int shortestSpan() const;
        int longestSpan() const;
};

#endif