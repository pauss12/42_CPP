
# include "Harl.hpp"

Harl::Harl()
{  
}

Harl::~Harl()
{
}

void    Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month."  << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    int i;
    std::string levelNames[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    while (i < 4 && !(level == levelNames[i])) 
    {
        i++;
    }

    switch (i)
    {
        case 0:
            this->debug();
            break ;
        case 1:
            this->info();
            break ;
        case 2:
            this->warning();
            break ;
        case 3:
            this->error();
            break ;
        case 4:
            std::cout << ORANGE "There is no other option" RESET << std::endl;
            break ;
    }
}