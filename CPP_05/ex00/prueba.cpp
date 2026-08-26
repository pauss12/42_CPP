#include <iostream>
#include "Bureaucrat.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"

int main()
{
    std::cout << CYAN << "=== TEST 1: Valid Instantiations ===" << RESET << std::endl;
    try {
        Bureaucrat top("CEO", 1);
        Bureaucrat low("Intern", 150);
        std::cout << top << low;
    } catch (std::exception &e) {
        std::cerr << RED << "Unexpected exception: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << CYAN << "=== TEST 2: Invalid Constructor Grades ===" << RESET << std::endl;
    try {
        Bureaucrat invalid1("TooHigh", 0);
    } catch (std::exception &e) {
        std::cout << GREEN << "Caught expected exception (Grade 0): " << e.what() << RESET << std::endl;
    }
    try {
        Bureaucrat invalid2("TooLow", 151);
    } catch (std::exception &e) {
        std::cout << GREEN << "Caught expected exception (Grade 151): " << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << CYAN << "=== TEST 3: Grade Increments and Boundaries ===" << RESET << std::endl;
    try {
        Bureaucrat b1("Bob", 2);
        std::cout << b1;
        b1.incrementGrade();
        std::cout << "After increment: " << b1;
        std::cout << "Attempting to increment Grade 1..." << std::endl;
        b1.incrementGrade();
    } catch (std::exception &e) {
        std::cout << GREEN << "Caught expected exception: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << CYAN << "=== TEST 4: Grade Decrements and Boundaries ===" << RESET << std::endl;
    try {
        Bureaucrat b2("Alice", 149);
        std::cout << b2;
        b2.decrementGrade();
        std::cout << "After decrement: " << b2;
        std::cout << "Attempting to decrement Grade 150..." << std::endl;
        b2.decrementGrade();
    } catch (std::exception &e) {
        std::cout << GREEN << "Caught expected exception: " << e.what() << RESET << std::endl;
    }

    return 0;
}