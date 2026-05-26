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
        std::cout << ORANGE << "Error: could not open file." << RESET << std::endl;
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
    // Expect format YYYY-MM-DD
    if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
        return false;
    return true;
}

// ########## CHECKEO DE LA FECHA -------------------------------------
bool check_date(const std::string &date)
{
    int year, month, day;
    // Enforce year to be non-negative and not in the future
    if (!parseDate(date, year, month, day))
    {
        std::cout << CYAN << "Error: invalid date format." << RESET << std::endl;
        return false;
    }

    time_t t = time(NULL);
    struct tm *tm_ptr = localtime(&t);
    int currentYear = tm_ptr ? tm_ptr->tm_year + 1900 : 0;
    if (year < 0 || (currentYear > 0 && year > currentYear))
    {
        std::cout << CYAN << "Error: year out of range." << RESET << std::endl;
        return false;
    }

    if (month < 1 || month > 12)
    {
        std::cout << CYAN << "Error: month out of range." << RESET << std::endl;
        return false;
    }

    int maxDay = daysInMonth(year, month);
    if (day < 1 || day > maxDay)
    {
        std::cout << CYAN << "Error: day out of range for given month." << RESET << std::endl;
        return false;
    }

    return true;
}

// ########## CHECKEO DEL VALOR -------------------------------------
bool check_value(const std::string &valueStr)
{
    double value;
    try
    {
        size_t idx;
        value = std::stod(valueStr, &idx);
        if (idx != valueStr.length())
            throw std::invalid_argument("Extra characters after number");
    }
    catch (const std::exception &e)
    {
        std::cout << CYAN << "Error: invalid value format." << RESET << std::endl;
        return false;
    }

    if (value < 0)
    {
        std::cout << CYAN << "Error: value cannot be negative." << RESET << std::endl;
        return false;
    }
    if (value > 10000)
    {
        std::cout << CYAN << "Error: value exceeds maximum allowed." << RESET << std::endl;
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
    {
        std::cout << ORANGE << "Error: file is empty." << RESET << std::endl;
        return;
    }
    else
    {
        if (line != "date | value")
        {
            std::cout << ORANGE << "Error: invalid line format." << RESET << std::endl;
            return;
        }
    }

    while (std::getline(file, line))
    {
        // Ignorar líneas comentadas
        if (line.empty() || line[0] == '#')
            continue;

        std::cout << "Processing line: " << line << std::endl;

        part1 = line.substr(0, line.find(" | "));
        part2 = line.substr(line.find(" | ") + 3);

        if (!check_date(part1) || !check_value(part2))
            return ;
    }
}