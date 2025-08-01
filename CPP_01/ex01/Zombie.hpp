#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <iomanip>

# define CYAN "\033[0;36m"
# define RESET "\033[0m"

class Zombie
{
	private:
		std::string name;

	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void announce(void);
		void setName(std::string name);
		
};

Zombie *zombieHorde(int N, std::string name);

#endif