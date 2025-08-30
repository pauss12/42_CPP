
# include "ClapTrap.hpp"

int main(void)
{
    ClapTrap claptrap("Clappy");
    claptrap.attack("target");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);
    
    return (0);
}