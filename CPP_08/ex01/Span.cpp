#include "Span.hpp"

Span::Span() : _maxSize(0) 
{
    // std::cout << CYAN << "Default constructor called" << RESET<< std::endl;
}

Span::Span(unsigned int n) : _maxSize(n) 
{
    // std::cout << CYAN << "Parameterized constructor called with size: " << n << RESET << std::endl;
}

Span::Span(const Span &other) : _numbers(other._numbers), _maxSize(other._maxSize) 
{
    std::cout << BLUE << "Copy constructor called" << RESET << std::endl;
}

Span &Span::operator=(const Span &other) 
{
    if (this != &other) 
    {
        // std::cout << ROSE   << "Assignment operator called" << RESET << std::endl;
        _numbers = other._numbers;
        _maxSize = other._maxSize;
    }
    return (*this);
}

Span::~Span() 
{
    // std::cout << PURPLE << "Destructor called" << RESET << std::endl;
    // No hay recursos dinámicos que liberar, así que el destructor puede estar vacío
}

// Otras funciones como addNumber, shortestSpan, longestSpan se implementarán en Span.tpp
void Span::addNumber(int num) 
{
    if (_numbers.size() >= _maxSize)
        throw std::runtime_error("Span is full");
    _numbers.push_back(num);
}

int Span::shortestSpan() const 
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");
    
    std::vector<int> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    
    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sortedNumbers.size(); ++i) 
    {
        int span = sortedNumbers[i] - sortedNumbers[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return (minSpan);
}

int Span::longestSpan() const 
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");
    
    int minNum = *std::min_element(_numbers.begin(), _numbers.end());
    int maxNum = *std::max_element(_numbers.begin(), _numbers.end());
    
    return (maxNum - minNum);
}