#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"

int main()
{
    Intern someRandomIntern;
    Bureaucrat boss("Big Boss", 1);
    AForm* form;

    std::cout << CYAN << "=== TEST 1: Intern Creates Shrubbery Creation Form ===" << RESET << std::endl;
    form = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (form) {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    std::cout << "\n" << CYAN << "=== TEST 2: Intern Creates Robotomy Request Form ===" << RESET << std::endl;
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form) {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    std::cout << "\n" << CYAN << "=== TEST 3: Intern Creates Presidential Pardon Form ===" << RESET << std::endl;
    form = someRandomIntern.makeForm("presidential pardon", "Marvin");
    if (form) {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    std::cout << "\n" << CYAN << "=== TEST 4: Intern Receives Unknown Form Request ===" << RESET << std::endl;
    form = someRandomIntern.makeForm("coffee request", "Boss Office");
    if (form == NULL) {
        std::cout << GREEN << "Success: Pointer returned NULL correctly for unknown form." << RESET << std::endl;
    } else {
        delete form;
    }

    return 0;
}