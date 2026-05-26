#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    BitcoinExchange exchange;
    
    // Aquí compruebas si le metes un argumento o no
    if (argc != 2)
    {
        std::cout << ORANGE << "Error: could not open file." << RESET << std::endl;
        return (1);
    }
    exchange.checkInput(argv[1]);

    return 0;
}