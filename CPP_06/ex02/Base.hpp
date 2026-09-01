#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <string>
# include <ctime>
# include <cstdlib>

class Base 
{
	public:
		virtual ~Base();
};

// Required functions -----------------
Base *generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
