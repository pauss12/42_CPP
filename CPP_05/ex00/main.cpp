#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << std::endl << YELLOW << "------------ CREATING A DEFAULT BUREAUCRAT --------------------- " << RESET << std::endl;
	Bureaucrat b0();

	std::cout << std::endl << YELLOW << "------------ CREATING A BUREAUCRAT WITH PARAMETERS --------------------- " << RESET << std::endl;
	Bureaucrat b1("Paula", 4);

	std::cout << std::endl << YELLOW << "------------ CREATING WITH COPY CONSTRUCTOR --------------------- " << RESET << std::endl;
	Bureaucrat b2(b1);
	std::cout << b2 << std::endl;

	std::cout << std::endl << YELLOW << "------------ CREATING WITH ASSIGN OPERATOR --------------------- " << RESET << std::endl;
	Bureaucrat b3;
	b3 = b1;
	std::cout << b3 << std::endl;

	std::cout << std::endl << YELLOW << "################################# TESTS ##############################" << RESET << std::endl;

	std::cout << std::endl << YELLOW << "------------ TEST 1: INCREMENTING GRADE --------------------- " << RESET << std::endl;
	Bureaucrat b4("John", 100);
	std::cout << b4 << std::endl;
	b4.incrementGrade();
	std::cout << b4 << std::endl;

	std::cout << std::endl << YELLOW << "------------ TEST 2: DECREMENTING GRADE --------------------- " << RESET << std::endl;
	Bureaucrat b5("Jane", 50);
	std::cout << b5 << std::endl;
	b5.decrementGrade();
	std::cout << b5 << std::endl;

	std::cout << std::endl << YELLOW << "------------ TEST 3: GRADE TOO HIGH --------------------- " << RESET << std::endl;
	try {
		Bureaucrat b6("Alice", 0);
		std::cout << b6 << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << YELLOW << "------------ TEST 4: GRADE TOO LOW --------------------- " << RESET << std::endl;
	try {
		Bureaucrat b7("Bob", 151);
		std::cout << b7 << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << YELLOW << "------------ TEST 5: INCREMENTING GRADE TOO HIGH --------------------- " << RESET << std::endl;
	try {
		Bureaucrat b8("Charlie", 1);
		std::cout << b8 << std::endl;
		b8.incrementGrade();
		std::cout << b8 << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << YELLOW << "------------ TEST 6: DECREMENTING GRADE TOO LOW --------------------- " << RESET << std::endl;
	try {
		Bureaucrat b9("David", 150);
		std::cout << b9 << std::endl;
		b9.decrementGrade();
		std::cout << b9 << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}