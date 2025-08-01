#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

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
		~Zombie();
		Zombie(std::string name);
		void announce(void);
		
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif