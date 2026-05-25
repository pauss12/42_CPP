#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    BitcoinExchange exchange;
    
    // Aquí compruebas si le metes un argumento o no
    if (argc != 2)
    {
        std::cout << ORANGE << "Usage: " << argv[0] << " <input_file>" << RESET << std::endl;
        return (1);
    }

    return 0;
}