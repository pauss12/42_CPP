#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <iostream>
#include <string>
#include <iomanip>

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon *weapon;

	public:
		HumanB(std::string name, Weapon &weapon);
		~HumanB();
		void attack(void);
		Weapon &getWeapon();
		void setWeapon(Weapon &weapon);
};

#endif