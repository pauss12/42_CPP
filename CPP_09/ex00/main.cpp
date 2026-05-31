#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    BitcoinExchange exchange;
    
    if (argc != 2)
    {
        std::cout << RED << "ERROR" << RESET << CYAN << " Usage: ./BitcoinExchange <input_file>" << RESET << std::endl;
        return (1);
    }
    exchange.loadDatabase("data.csv");
    std::ifstream file(argv[1]);
    if (!file.is_open())
    {
        std::cout << RED << "ERROR" << RESET << CYAN << " Could not open file." << RESET << std::endl;
        return (1);
    }
    exchange.processFile(argv[1]);
    file.close();
    return (0);
}