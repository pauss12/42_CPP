#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define RESET   "\033[0m"
#define CYAN    "\033[36m"

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    Bureaucrat president("President", 1);
    Bureaucrat manager("Manager", 40);
    Bureaucrat intern("Intern", 150);

    std::cout << CYAN << "=== TEST 1: Execution Without Signature ===" << RESET << std::endl;
    {
        ShrubberyCreationForm shrub("garden");
        president.executeForm(shrub);
    }

    std::cout << "\n" << CYAN << "=== TEST 2: Shrubbery Creation Form (Sign 145, Exec 137) ===" << RESET << std::endl;
    {
        ShrubberyCreationForm shrub("home");
        intern.signForm(shrub);
        manager.signForm(shrub);
        
        intern.executeForm(shrub);
        manager.executeForm(shrub); // Genera home_shrubbery
    }

    std::cout << "\n" << CYAN << "=== TEST 3: Robotomy Request Form (Sign 72, Exec 45 - 50% Random) ===" << RESET << std::endl;
    {
        RobotomyRequestForm robot("Target_Bender");
        manager.signForm(robot);

        for (int i = 0; i < 4; i++) {
            std::cout << "[Attempt " << (i + 1) << "] ";
            manager.executeForm(robot);
        }
    }

    std::cout << "\n" << CYAN << "=== TEST 4: Presidential Pardon Form (Sign 25, Exec 5) ===" << RESET << std::endl;
    {
        PresidentialPardonForm pardon("Arthur Dent");
        
        manager.signForm(pardon);
        president.signForm(pardon);
        
        manager.executeForm(pardon);
        president.executeForm(pardon);
    }

    return 0;
}