
# include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
    this->_name = "";
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
    this->_name = name;
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &orig)
{
    this->_name = orig._name;
    this->_hitPoints = orig._hitPoints;
    this->_energyPoints = orig._energyPoints;
    this->_attackDamage = orig._attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& orig)
{
    //Se comprueba si es la misma direccion de memoria
    if (this != &orig)
    {

    }
}