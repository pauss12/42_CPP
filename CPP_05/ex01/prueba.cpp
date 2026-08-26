#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"

int main()
{
    std::cout << CYAN << "=== TEST 1: Form Constructor Exceptions ===" << RESET << std::endl;
    try {
        Form fBadSign("BadSign", 0, 50);
    } catch (std::exception &e) {
        std::cout << GREEN << "Caught expected exception (Sign grade 0): " << e.what() << RESET << std::endl;
    }
    try {
        Form fBadExec("BadExec", 50, 151);
    } catch (std::exception &e) {
        std::cout << GREEN << "Caught expected exception (Exec grade 151): " << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << CYAN << "=== TEST 2: Successful Form Signing ===" << RESET << std::endl;
    try {
        Bureaucrat boss("Boss", 10);
        Form taxForm("Taxation Form", 20, 10);

        std::cout << taxForm;
        boss.signForm(taxForm);
        std::cout << taxForm;
    } catch (std::exception &e) {
        std::cerr << RED << "Unexpected error: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << CYAN << "=== TEST 3: Unsuccessful Form Signing (Grade Too Low) ===" << RESET << std::endl;
    try {
        Bureaucrat intern("Intern", 100);
        Form topSecret("Top Secret Form", 20, 10);

        std::cout << topSecret;
        intern.signForm(topSecret);
        std::cout << topSecret;
    } catch (std::exception &e) {
        std::cerr << RED << "Unexpected error: " << e.what() << RESET << std::endl;
    }

    return 0;
}