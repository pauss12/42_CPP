#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void)
{
	std::cout << YELLOW << "------------ CREATING AN INTERN --------------------- " << RESET << std::endl;
	Intern someRandomIntern;

	std::cout << std::endl << YELLOW << "------------ CREATING A BUREAUCRAT --------------------- " << RESET << std::endl;
	Bureaucrat b1("Paula", 4);

	std::cout << std::endl << YELLOW << "------------ SHOWING BUREAUCRAT INFORMATION --------------------- " << RESET << std::endl;
	std::cout << b1 << std::endl;

	std::cout << std::endl << YELLOW << "------------ TESTING INTERN MAKEFORM --------------------- " << RESET << std::endl;
	AForm *rrf;
	rrf = someRandomIntern.makeForm("robotomy", "Bender");

	std::cout << std::endl << YELLOW << "------------ SHOWING FORM INFORMATION --------------------- " << RESET << std::endl;
	std::cout << *rrf << std::endl;

	std::cout << std::endl << YELLOW << "------------ TESTING EXECUTION FORM BEFORE SIGNING --------------------- " << RESET << std::endl;
	rrf->execute(b1);

	std::cout << std::endl << YELLOW << "------------ TESTING SIGNING FORM --------------------- " << RESET << std::endl;
	rrf->beSigned(b1, false);

	std::cout << std::endl << YELLOW << "------------ SHOWING FORM INFORMATION AFTER SIGNING --------------------- " << RESET << std::endl;
	std::cout << *rrf << std::endl;

	std::cout << std::endl << YELLOW << "------------ TESTING EXECUTION FORM AFTER SIGNING --------------------- " << RESET << std::endl;
	rrf->execute(b1);

	std::cout << std::endl << YELLOW << "------------ DELETING FORM --------------------- " << RESET << std::endl;
	delete rrf;

	std::cout << std::endl << YELLOW << "------------ END OF TESTS --------------------- " << RESET << std::endl;

	return (0);
}