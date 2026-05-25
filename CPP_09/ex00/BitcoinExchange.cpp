#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::cout << CYAN << "Constructor called" << RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    std::cout << BLUE << "Copy constructor called" << RESET << std::endl;
    this->_database = other._database;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    std::cout << ROSE << "Copy assignment operator called" << RESET << std::endl;
    if (this != &other)
        this->_database = other._database;
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout << PURPLE << "Destructor called" << RESET << std::endl;
}

// FUNCIONES ---------------------
