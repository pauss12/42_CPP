#include <cstdio>
#include <ctime>
#include <cstdlib>
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    // std::cout << CYAN << "Constructor called" << RESET << std::endl;
    this->_rate = 0;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    // std::cout << BLUE << "Copy constructor called" << RESET << std::endl;
    this->_database = other._database;
    this->_rate = other._rate;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    // std::cout << ROSE << "Copy assignment operator called" << RESET << std::endl;
    if (this != &other)
    {
        this->_rate = other._rate;
        this->_database = other._database;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
    // std::cout << PURPLE << "Destructor called" << RESET << std::endl;
}

// ######################## FUNCIONES ---------------------
void BitcoinExchange::checkInput(const std::string &input)
{
    // Intenta abrir el fichero input.txt
    std::ifstream file(input.c_str());
    if (!file.is_open())
    {
        std::cout << RED << "ERROR" << RESET << CYAN << " Could not open file." << RESET << std::endl;
        return; 
    }
    processFile(file);
    file.close();
}

// STATIC FUNCTIONS THAT HELP TO CHECK THE DATE AND VALUE -----------------------------
static bool isLeapYear(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

static int daysInMonth(int year, int month)
{
    if (month == 2)
        return isLeapYear(year) ? 29 : 28;
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    return 31;
}

static bool parseDate(const std::string &date, int &year, int &month, int &day)
{
    if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
        return false;
    return true;
}

// ########## CHECKEO DE LA FECHA -------------------------------------
bool check_date(const std::string &date)
{
    int year, month, day;

    if (!parseDate(date, year, month, day))
    {
        std::cout << RED << "ERROR" << RESET << CYAN << " Invalid date format." << RESET << std::endl;
        return false;
    }

    time_t t = time(NULL);
    struct tm *tm_ptr = localtime(&t);
    int currentYear = tm_ptr ? tm_ptr->tm_year + 1900 : 0;
    if (year < 0 || (currentYear > 0 && year > currentYear))
    {
        std::cout << RED << "ERROR" << RESET << CYAN << " Year out of range." << RESET << std::endl;
        return false;
    }

    if (month < 1 || month > 12)
    {
        std::cout << RED << "ERROR" << RESET << CYAN << " Month out of range." << RESET << std::endl;
        return false;
    }

    int maxDay = daysInMonth(year, month);
    if (day < 1 || day > maxDay)
    {
        std::cout << RED << "ERROR" << RESET << CYAN << " Day out of range for given month." << RESET << std::endl;
        return false;
    }

    return true;
}

// ########## CHECKEO DEL VALOR -------------------------------------
bool check_value(const std::string &valueStr)
{
    size_t a = valueStr.find_first_not_of(" \t");
    if (a == std::string::npos)
    {
        std::cout << RED << "ERROR" << RESET << CYAN << " Empty value." << RESET << std::endl;
        return false;
    }
    size_t b = valueStr.find_last_not_of(" \t");
    std::string s = valueStr.substr(a, b - a + 1);

    char *endptr = NULL;
    double d = strtod(s.c_str(), &endptr);
    if (endptr == s.c_str() || *endptr != '\0')
    {
        std::cout << RED << "ERROR" << RESET << CYAN << " Invalid value." << RESET << std::endl;
        return false;
    }
    if (d < 0.0)
    {
        std::cout << RED << "ERROR" << RESET << CYAN << " Value cannot be negative." << RESET << std::endl;
        return false;
    }
    if (d > 1000.0)
    {
        std::cout << RED << "ERROR" << RESET << CYAN << " Value exceeds maximum allowed (1000)." << RESET << std::endl;
        return false;
    }
    return true;
}

void BitcoinExchange::processFile(std::ifstream &file)
{
    std::string line;
    std::string part1;
    std::string part2;

    if (!std::getline(file, line))
        std::cout << ORANGE << "Error: file is empty." << RESET << std::endl;
    else
    {
        if (line != "date | value")
            std::cout << RED << "ERROR" << RESET << CYAN << " Invalid line format." << RESET << std::endl;
    }

    while (std::getline(file, line))
    {
        if (line.empty() || line[0] == '#')
            continue;

        std::cout << "Processing line: " << line << std::endl;

        part1 = line.substr(0, line.find(" | "));
        part2 = line.substr(line.find(" | ") + 3);

        if (!check_date(part1) || !check_value(part2))
            continue;
    }
}