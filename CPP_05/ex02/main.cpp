#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << std::endl << YELLOW << "------------ CREATING A BUREAUCRAT WITH PARAMETERS --------------------- " << RESET << std::endl;
	Bureaucrat b1("Paula", 4);

	std::cout << std::endl << YELLOW << "################################# TESTS ##############################" << RESET << std::endl;

	std::cout << std::endl << YELLOW << "------------ TEST 1: TRYING TO INSTANTIATE A FORM --------------------- " << RESET << std::endl;
	std::cout << GRAY << "It has comments because Abstract Form Class cannot be instantiated " << RESET << std::endl;
	//AForm f1("Form1", false, 5, 10);

	std::cout << std::endl << YELLOW << "------------ TEST 2: CREATING A SHRUBBERY CREATION FORM --------------------- " << RESET << std::endl;
	try {
		ShrubberyCreationForm form("shrubbery");

		b1.signForm(form);
		form.execute(b1);

	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << YELLOW << "------------ TEST 3: CREATING A ROBOTOMY REQUEST FORM --------------------- " << RESET << std::endl;
	try {
		
		RobotomyRequestForm form("Robotomy");

		b1.signForm(form);
		form.execute(b1);

	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << YELLOW << "------------ TEST 4: CREATING A PRESIDENTIAL PARDON FORM --------------------- " << RESET << std::endl;
	try {
		PresidentialPardonForm form("Presidential");

		b1.signForm(form);
		form.execute(b1);

	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << YELLOW << "------------ END OF TESTS --------------------- " << RESET << std::endl;

	return (0);
}