#include "Bureaucrat.hpp"

// ###################### CONSTRUCTORES ###################################
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << LIGHT_BLUE << "The default Bureaucrat has been created! " << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name.empty() ? "Default" : name), _grade(grade)
{
	if (name.empty() || this->_name.compare("Default") == 0)
		std::cout << ORANGE << "WARNING" << RESET << std::endl << "Your Bureaucrat has been named as 'Default' " << std::endl;
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException("Bureaucrat cannot be created because grade is too low!");
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException("Bureaucrat cannot be created because grade is too high!");
	else
		std::cout << BLUE << "Bureaucrat with name [ " << this->getName() << " ] and Grade " << this->getGrade() <<  " has been created" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &orig) : _name(orig._name), _grade(orig._grade)
{
	std::cout << LIGHT_BLUE << "Bureaucrat has been created with the the copy constructor called " << RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
	{
		std::cout << CYAN << "Bureaucrat has been created with the the copy assignment operator called " << RESET << std::endl;
		this->_grade = src._grade;
	}
	return (*this); 
}

// ###################### DESTRUCTORES ###################################
Bureaucrat::~Bureaucrat()
{
	if (this->getName().empty())
		std::cout << PURPLE << "Destructor for a Bureaucrat with no NAME has been called " << RESET << std::endl;
	else
		std::cout << PURPLE << "Destructor for " << this->getName() << " has been called " << RESET << std::endl;
}

// ###################### GETTERS ###################################
std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

// ###################### INCREMENT / DECREMENT / SIGN FORM ###################################
void Bureaucrat::decrementGrade()
{
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException("Bureaucrat grade cannot be Decremented. It is already 150!");
	this->_grade++;
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		if (form.getIsSigned())
		{
			std::cout << "[" << this->getName() << "] cannot sign " << form.getName() << " because it is already signed." << std::endl;
			return ;
		}
		form.beSigned(*this);
		std::cout << GREEN << "[" << this->getName() << "] signed " << form.getName() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "[" << this->getName() << "] couldn't sign " << form.getName() << " because " << e.what() << RESET << std::endl;
	}
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException("Bureaucrat grade cannot be Incremented. It is already 1!");
	this->_grade--;
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << GREEN << this->getName() << " executed " << form.getName() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "ERROR" << RESET << std::endl << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << RESET << std::endl;
	}
}

// ###################### EXCEPCIONES ###################################

Bureaucrat::GradeTooHighException::GradeTooHighException(const char *errorMessage) 
    : _errorMessage(errorMessage) {}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return (_errorMessage);
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const char *errorMessage) 
	: _errorMessage(errorMessage) {}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return (_errorMessage);
}

// ###################### PRINTING ###################################
std::ostream& operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	std::string name = bureaucrat.getName();
	if (bureaucrat.getName().empty() || bureaucrat.getName().compare("Default") == 0)
	{
		os << ORANGE << "WARNING" << RESET << std::endl << "Bureaucrat has been created before with no NAME " << std::endl;
		std::cout << "It will be printed as 'Default'" << std::endl << std::endl;
		name = "Default";
	}
	os << CYAN << name << RESET << ", bureaucrat grade " << ROSE << bureaucrat.getGrade() << RESET << std::endl;
	return (os);
}