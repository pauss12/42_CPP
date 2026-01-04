#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <fstream>
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

class Replace
{
	private:
		std::string filename;
		std::string lookFor;
		std::string replaceWith;
		std::string createdFile;

		std::ifstream infile;
		std::ofstream outfile;

		int			checkInfile(void);
		void		writeFile(void);
		std::string	replaceLine(std::string line)
;
	public:
		Replace();
		~Replace();
		Replace(std::string filename, std::string lookFor, std::string replaceWith);
		void	CreateNewFile(void);
		
};

# endif