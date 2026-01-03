#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <iostream>
# include <string>

# define GREEN "\033[0;32m"
# define RED "\033[0;31m\033[1m"
# define ORANGE "\001\033[38;5;208m\002"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define YELLOW	"\x1b[33m"
# define ROSE	"\x1B[38;2;255;151;203m"
# define LIGHT_BLUE	"\x1B[38;2;53;149;240m"
# define LIGHT_GREEN	"\x1B[38;2;17;245;120m"
# define GRAY	"\x1B[38;2;176;174;174m"
# define RESET	"\033[0m"

class Animal {

	protected:
		std::string _type;

	public:
		Animal();
		Animal(const Animal& orig);
		Animal& operator=(const Animal& orig);
		virtual ~Animal();

		virtual void makeSound() const;
		std::string getType() const;

		std::string getIdeas(int index) const;
		void setIdeas(int index, const std::string& idea);
};

#endif