#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << std::endl << YELLOW << "------------ CREATING A BUREAUCRAT WITH PARAMETERS --------------------- " << RESET << std::endl;
	Bureaucrat b1("Paula", 4);

	std::cout << std::endl << YELLOW << "------------ CREATE A FORM --------------------- " << RESET << std::endl;
	Form f1("Form1", false, 5, 10);

	std::cout << std::endl << YELLOW << "------------ FORM COPY CONSTRUCTOR --------------------- " << RESET << std::endl;
	Form f2(f1);

	std::cout << std::endl << YELLOW << "------------ FORM ASSIGNMENT OPERATOR --------------------- " << RESET << std::endl;
	Form f3 = f1;


	std::cout << std::endl << YELLOW << "################################# TESTS ##############################" << RESET << std::endl;

	std::cout << std::endl << YELLOW << "------------ TEST 1: CREATING A NAMELESS FORM --------------------- " << RESET << std::endl;
	Form f4("", false, 5, 10);
	std::cout << f4 << std::endl;

	std::cout << std::endl << YELLOW << "------------ TEST 2: CREATING A FORM WITH HIGH GRADE --------------------- " << RESET << std::endl;
	try {
		Form f5("Form5", false, 0, 10);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << YELLOW << "------------ TEST 3: FORM SIGNING ITSELF WITH SUFFICIENT GRADE --------------------- " << RESET << std::endl;
	try {

		std::cout << std::endl << "Before signing:" << std::endl;
		std::cout << f1 << std::endl;

		f1.beSigned(b1, false);
		std::cout << std::endl << "After signing:" << std::endl;
		std::cout << f1 << std::endl;

	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << YELLOW << "------------ TEST 4: FORM SIGNING ITSELF WITH INSUFFICIENT GRADE --------------------- " << RESET << std::endl;
	Bureaucrat b3("John", 8);
	Form f5("Form4", false, 6, 5);
	try {

		std::cout << std::endl << "Before signing:" << std::endl;
		std::cout << f5 << std::endl;

		f5.beSigned(b3, false);

		std::cout << std::endl << "After signing:" << std::endl;
		std::cout << f5 << std::endl;

	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << YELLOW << "------------ TEST 4: BUREAUCRAT SIGNING FORM WITH INSUFFICIENT GRADE --------------------- " << RESET << std::endl;
	Bureaucrat b2("John", 6);
	Form f6("Form4", false, 5, 5);
	try {

		std::cout << std::endl << "Before signing:" << std::endl;
		std::cout << f6 << std::endl;

		b2.signForm(f6);

		std::cout << std::endl << "After signing:" << std::endl;
		std::cout << f6 << std::endl;

	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << YELLOW << "------------ TEST 5: BUREAUCRAT SIGNING FORM WITH SUFFICIENT GRADE --------------------- " << RESET << std::endl;
	Form f7("Form4", false, 6, 5);
	try {

		std::cout << std::endl << "Before signing:" << std::endl;
		std::cout << f7 << std::endl;

		b1.signForm(f7);

		std::cout << std::endl << "After signing:" << std::endl;
		std::cout << f7 << std::endl;

	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << YELLOW << "------------ END OF TESTS --------------------- " << RESET << std::endl;

	return (0);
}