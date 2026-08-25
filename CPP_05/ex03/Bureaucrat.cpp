#include "Bureaucrat.hpp"

// ###################### CONSTRUCTORES ###################################
Bureaucrat::Bureaucrat() : _name(""), _grade(150)
{
	std::cout << LIGHT_BLUE << "The default Bureaucrat has been created! " << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name.empty() ? "Default" : name), _grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException("Cannot create Bureaucrat grade is too low!");
	else if (grade < 1)
		throw GradeTooHighException("Cannot create Bureaucrat grade is too high!");
	if (name.empty())
		std::cout << ORANGE << "WARNING" << RESET << std::endl << "Your Bureaucrat has been named as 'Default' " << std::endl;
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
		throw GradeTooLowException("Grade cannot be decremented because is already too low!");
	this->_grade++;
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this, true);
		std::cout << GREEN << this->getName() << " signed " << form.getName() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "ERROR" << RESET << std::endl << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << RESET << std::endl;
	}
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade <= 1)
		throw GradeTooHighException("Grade cannot be incremented because is already too high!");
	this->_grade--;
}

void Bureaucrat::executeForm(AForm const &form)
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