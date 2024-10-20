#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Weapon 
{
	private:
		std::string type;

	public:
		Weapon(std::string type);
		~Weapon();
		const std::string &getType(void);
		void setType(std::string type);
};

#endif