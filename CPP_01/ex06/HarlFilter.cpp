# include "HarlFilter.hpp"

HarlFilter::HarlFilter()
{  
}

HarlFilter::~HarlFilter()
{
}

void	HarlFilter::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	HarlFilter::info(void)
{
	std::cout << std::endl << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	HarlFilter::warning(void)
{
	std::cout << std::endl << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month."  << std::endl;
}

void	HarlFilter::error(void)
{
	std::cout << std::endl << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void HarlFilter::complain(std::string level)
{
	int i;

	i = 0;
	static std::string levelNames[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while (i < 4 && !(level == levelNames[i])) 
		i++;
	if (i == 4)
		level.clear();
	switch (i)
	{
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break ;
		case 4:
			std::cout << ORANGE << "[ Probably complaining about insignificant problems ]" << RESET << std::endl;
			break ;
	}
}