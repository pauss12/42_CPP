#include "Form.hpp"

// ###################### CONSTRUCTORS #################################
Form::Form() : _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << BLUE << "The default Form has been created! " << RESET << std::endl;
}


Form::Form(const std::string name, bool isSigned, const int gradeToSign, const int gradeToExecute) : _name(name), _isSigned(isSigned), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_name.empty())
		std::cout << ORANGE << "WARNING" << RESET << std::endl << "The form has been named as 'Default' " << std::endl;
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw Form::GradeTooHighException();
	else if (gradeToExecute > 150 || gradeToSign > 150)
		throw Form::GradeTooLowException();
	std::cout << LIGHT_BLUE << "The parameter Form with [ " << name << " ] as name, has been created!" << RESET << std::endl;
}

Form::Form(const Form &src) : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	std::cout << CYAN << "The copy constructor has been called, it has given to the Form the name: " << src.getName() << RESET << std::endl;
}

Form& Form::operator=(const Form& orig)
{
	if (this != &orig)
	{
		_isSigned = orig._isSigned;
		std::cout << BLUE << "The Form with assignment operator has been created! " << RESET << std::endl;
	}
	return (*this);
}

// ###################### DESTRUCTORS ##################################
Form::~Form()
{
	if (this->getName().empty())
		std::cout << PURPLE << "The form with no NAME has been deleted " << RESET << std::endl;
	else
		std::cout << PURPLE << "The form with [" << this->getName() << "] has been deleted " << RESET << std::endl;
}


// ###################### EXCEPTIONS ###################################
const char *Form::GradeTooHighException::what() const throw()
{
	static const char* msg = RED "ERROR" RESET " Grade too HIGH";
	return (msg);
}

const char *Form::GradeTooLowException::what() const throw()
{
	static const char* msg = RED "ERROR" RESET " Grade too LOW";
	return (msg);
}

// ###################### GETTERS ######################################
const std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getIsSigned() const
{
	return (this->_isSigned);
}

int Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}


//  ###################### FUNCTION BE SIGNED ##########################
void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_name.empty())
	{
		std::cout << RED << "ERROR" << RESET << " Form has no NAME" << std::endl;
		return ;
	}
	if (this->_isSigned)
	{
		std::cout << YELLOW << "Form [" << this->getName() << "] is already signed." << RESET << std::endl;
		return;
	}
	if (bureaucrat.getGrade() <= this->_gradeToSign)
	{
		this->_isSigned = true;
		std::cout << GREEN << "Bureaucrat [" << bureaucrat.getName() << "] signed [" << this->getName() << "]" << RESET << std::endl;
	}
	else
		throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, Form const& form)
{
	os << "Form Name: " << form.getName() << std::endl
		<< "Signed: " << (form.getIsSigned() ? "Yes" : "No") << std::endl
		<< "Grade Required to Sign: " << form.getGradeToSign() << std::endl
		<< "Grade Required to Execute: " << form.getGradeToExecute();
	return (os);
}