#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <string>
#include <iostream>
#include <exception>

#include "Form.hpp"

# define GREEN "\033[0;32m"
# define WHITE "\033[37m"
# define RED "\033[0;31m\033[1m"
# define ORANGE "\001\033[38;5;208m\002"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define YELLOW  "\x1b[33m"
# define ROSE    "\x1B[38;2;255;151;203m"
# define LIGHT_BLUE   "\x1B[38;2;53;149;240m"
# define LIGHT_GREEN  "\x1B[38;2;17;245;120m"
# define GRAY    "\x1B[38;2;176;174;174m"
# define RESET "\033[0m"

class Form;

class Bureaucrat {

	private:
		const std::string _name;
		int	_grade;	//From 1 to 150

	public:
		
		// Clase Canonica Ortodoxa
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &orig);
		Bureaucrat operator=(const Bureaucrat &src);
		~Bureaucrat();

		// Otras funciones a crear
		int getGrade() const;
		std::string getName() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(Form &form);

	// Excepciones a crear ---
	class	GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class	GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &Bureaucrat);

#endif // BUREAUCRAT_H