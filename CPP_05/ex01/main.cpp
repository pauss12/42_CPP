#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << std::endl << YELLOW << "------------ CREATING A BUREAUCRAT WITH PARAMETERS --------------------- " << RESET << std::endl;
	Bureaucrat b1("Paula", 4);

	std::cout << std::endl << YELLOW << "------------ CREATE A FORM --------------------- " << RESET << std::endl;
	Form f1("Form1", 5, 10);

	std::cout << std::endl << YELLOW << "------------ FORM COPY CONSTRUCTOR --------------------- " << RESET << std::endl;
	Form f2(f1);

	std::cout << std::endl << YELLOW << "------------ FORM ASSIGNMENT OPERATOR --------------------- " << RESET << std::endl;
	Form f3 = f1;


	std::cout << std::endl << YELLOW << "################################# TESTS ##############################" << RESET << std::endl;

	std::cout << std::endl << YELLOW << "------------ TEST 0: TRYING TO INCREMENT BUREAUCRAT GRADE --------------------- " << RESET << std::endl;
	try {
		
		Bureaucrat b0("John", 1);
		b0.incrementGrade();

	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << YELLOW << "------------ TEST 1: CREATING A NAMELESS FORM --------------------- " << RESET << std::endl;
	Form f4("", 5, 10);
	std::cout << f4 << std::endl;

	std::cout << std::endl << YELLOW << "------------ TEST 2: CREATING A FORM WITH HIGH GRADE --------------------- " << RESET << std::endl;
	try {
		Form f5("Form5", 0, 10);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << YELLOW << "------------ TEST 3: FORM SIGNING ITSELF WITH SUFFICIENT GRADE --------------------- " << RESET << std::endl;
	try {

		std::cout << std::endl << "Before signing:" << std::endl;
		std::cout << f1 << std::endl;

		std::cout << std::endl << "Bureaucrat signing the form:" << std::endl;
		std::cout << b1 << std::endl;

		f1.beSigned(b1);
		std::cout << std::endl << "After signing:" << std::endl;
		std::cout << f1 << std::endl;

	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << YELLOW << "------------ TEST 4: FORM SIGNING ITSELF WITH INSUFFICIENT GRADE --------------------- " << RESET << std::endl;
	Bureaucrat b3("John", 8);
	Form f5("Form4", 6, 5);
	try {

		std::cout << std::endl << "Before signing:" << std::endl;
		std::cout << f5 << std::endl;

		std::cout << std::endl << "Bureaucrat signing the form:" << std::endl;
		std::cout << b3 << std::endl;
		f5.beSigned(b3);

		std::cout << std::endl << "After signing:" << std::endl;
		std::cout << f5 << std::endl;

	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << YELLOW << "------------ TEST 5: BUREAUCRAT SIGNING FORM WITH INSUFFICIENT GRADE --------------------- " << RESET << std::endl;
	Bureaucrat b2("John", 6);
	Form f6("Form4", 5, 5);
	try {

		std::cout << std::endl << "Before signing:" << std::endl;
		std::cout << f6 << std::endl;

		std::cout << std::endl << "Bureaucrat signing the form:" << std::endl;
		std::cout << b2 << std::endl;
		b2.signForm(f6);

		std::cout << std::endl << "After signing:" << std::endl;
		std::cout << f6 << std::endl;

	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << YELLOW << "------------ TEST 6: BUREAUCRAT SIGNING FORM WITH SUFFICIENT GRADE --------------------- " << RESET << std::endl;
	Form f7("Form4", 6, 5);
	try {

		std::cout << std::endl << "Before signing:" << std::endl;
		std::cout << f7 << std::endl;

		std::cout << std::endl << "Bureaucrat signing the form:" << std::endl;
		std::cout << b1 << std::endl;
		b1.signForm(f7);

		std::cout << std::endl << "After signing:" << std::endl;
		std::cout << f7 << std::endl;

	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	Form f8("Form5", 6, 5);
	std::cout << std::endl << YELLOW << "------------ TEST 7: FORM CALLING beSigned() --------------------- " << RESET << std::endl;
	try {

		std::cout << std::endl << "Bureaucrat signing the form:" << std::endl;
		std::cout << b1 << std::endl;
		f8.beSigned(b1);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	Form f9("Form6", 6, 5);
	std::cout << std::endl << YELLOW << "------------ TEST 8: BUREAUCRAT CALLING signForm() --------------------- " << RESET << std::endl;
	try {
		std::cout << std::endl << "Bureaucrat signing the form:" << std::endl;
		std::cout << b1 << std::endl;
		b1.signForm(f9);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << YELLOW << "------------ TEST 9: TRYING TO SIGN A SIGNED FORM --------------------- " << RESET << std::endl;
	try {
		std::cout << std::endl << "Before signing:" << std::endl;
		std::cout << f9 << std::endl;

		std::cout << std::endl << "Bureaucrat signing the form:" << std::endl;
		std::cout << b1 << std::endl;
		b1.signForm(f9);

		std::cout << std::endl << "After signing:" << std::endl;
		std::cout << f9 << std::endl;

	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << YELLOW << "------------ TEST 10: TRYING TO SIGN A NAMELESS FORM --------------------- " << RESET << std::endl;
	try {
		Form f10("", 6, 5);
		std::cout << std::endl << "Before signing:" << std::endl;
		std::cout << f10 << std::endl;

		std::cout << std::endl << "Bureaucrat signing the form:" << std::endl;
		std::cout << b1 << std::endl;
		b1.signForm(f10);

		std::cout << std::endl << "After signing:" << std::endl;
		std::cout << f10 << std::endl;

	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << YELLOW << "------------ END OF TESTS --------------------- " << RESET << std::endl;

	return (0);
}