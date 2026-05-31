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

// ######################## FUNCIONES --------------------------------------

// STATIC FUNCTIONS THAT HELP TO CHECK THE DATE AND VALUE -----------------------------
static bool isLeapYear(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

static int daysInMonth(int year, int month)
{
    if (month == 2)
    {
        if (isLeapYear(year))
            return 29;
        return 28;
    }
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
    int     year;
    int     month;
    int     day;
    int     currentYear;
    time_t  t;

    currentYear = 0;
    if (!parseDate(date, year, month, day))
    {
        std::cout << RED << "ERROR" << RESET << CYAN << " Invalid date format." << RESET << std::endl;
        return false;
    }

    t = time(NULL);
    struct tm *tm_ptr = localtime(&t);
    if (tm_ptr)
        currentYear = tm_ptr->tm_year + 1900;
    if (year < 0 || (currentYear > 0 && year > currentYear))
    {
        std::cout << RED << "ERROR" << RESET << CYAN << " bad input " << RESET << "=> " << date << std::endl;
        std::cout << CYAN << "Year out of range." << RESET << std::endl;
        return false;
    }
    if (month < 1 || month > 12)
    {
        std::cout << RED << "ERROR" << RESET << CYAN << " bad input " << RESET << "=> " << date << std::endl;
        std::cout << CYAN << "Month out of range." << RESET << std::endl;
        return false;
    }
    int maxDay = daysInMonth(year, month);
    if (day < 1 || day > maxDay)
    {
        std::cout << RED << "ERROR" << RESET << CYAN << " bad input " << RESET << "=> " << date << std::endl;
        std::cout << CYAN << "Day out of range for given month." << RESET << std::endl;
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
        std::cout << RED << "ERROR" << RESET << CYAN << " not a positive number." << RESET << std::endl;
        return false;
    }
    if (d > 1000.0)
    {
        std::cout << RED << "ERROR" << RESET << CYAN << " too large a number." << RESET << std::endl;
        return false;
    }
    return true;
}

void BitcoinExchange::processFile(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cout << RED << "ERROR" << RESET << CYAN << " Could not open file." << RESET << std::endl;
        return;
    }
    std::string line;
    std::string part1;
    std::string part2;
    double      rate;
    double      value;
    std::string date;

    rate = 0;
    value = 0.0;
    if (!std::getline(file, line))
        std::cout << RED << "ERROR" << RESET << CYAN << " File is empty." << RESET << std::endl;
    else
    {
        if (line != "date | value")
            std::cout << RED << "ERROR" << RESET << CYAN << " Invalid line format." << RESET << std::endl;
    }

    while (std::getline(file, line))
    {
        if (line.empty() || line[0] == '#')
            continue;

        part1 = line.substr(0, line.find(" | "));
        part2 = line.substr(line.find(" | ") + 3);

        if (!check_date(part1) || !check_value(part2))
            continue;

        date = findNearestDate(part1);
        rate = getRate(date);
        value = strtod(part2.c_str(), NULL);

        std::cout << part1 << " => " << part2 << " = " << (value * rate) << std::endl;
        
    }
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cout << RED << "ERROR" << RESET << CYAN << " Could not open database file." << RESET << std::endl;
        return;
    }
    std::string line;

    if (!std::getline(file, line))
        std::cout << RED << "ERROR" << RESET << CYAN << " File is empty." << RESET << std::endl;
    else
    {
        if (line != "date,exchange_rate")
            std::cout << RED << "ERROR" << RESET << CYAN << " Invalid line format." << RESET << std::endl;
    }

    while (std::getline(file, line))
    {
        if (line.empty() || line[0] == '#')
            continue;
        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos)
        {
            std::cout << RED << "ERROR" << RESET << CYAN << " Invalid database line format." << RESET << std::endl;
            continue;
        }
        std::string date = line.substr(0, commaPos);
        std::string rateStr = line.substr(commaPos + 1);
        char *endptr = NULL;
        double rate = strtod(rateStr.c_str(), &endptr);
        if (endptr == rateStr.c_str() || *endptr != '\0')
        {
            std::cout << RED << "ERROR" << RESET << CYAN << " Invalid exchange rate in database." << RESET << std::endl;
            continue;
        }
        _database[date] = rate;
    }
    file.close();
}

// GET RATE FUNCTION ----------------------------------------------------------
double BitcoinExchange::getRate(const std::string &date) const
{
    std::map<std::string, double>::const_iterator it = _database.find(date);
    if (it != _database.end())
        return it->second;
    return (-1.0);
}

// FIND NEAREST DATE FUNCTION ------------------------------------------------------
std::string BitcoinExchange::findNearestDate(const std::string &date) const
{
    std::map<std::string, double>::const_iterator it = _database.lower_bound(date);
    if (it == _database.end())
        return (--it)->first;
    if (it == _database.begin())
        return (it->first);

    std::map<std::string, double>::const_iterator prevIt = std::prev(it);
    if ((date > prevIt->first && date < it->first) || (date == prevIt->first))
        return prevIt->first;
    return (it->first);
}