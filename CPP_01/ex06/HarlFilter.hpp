#ifndef HARLFILTER_HPP
# define HARLFILTER_HPP


# include <iostream>
# include <string>
# include <iomanip>

# define GREEN "\033[0;32m"
# define RED "\033[0;31m\033[1m"
# define ORANGE "\001\033[38;5;208m\002"
# define RESET "\033[0m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"

class HarlFilter
{
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);

    public:
        HarlFilter();
        ~HarlFilter();
        void complain(std::string level);

};

# endif