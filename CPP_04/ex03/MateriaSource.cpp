#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_materiasSource[i] = NULL;
	std::cout << "Creating MateriaSource" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_materiasSource[i])
			delete _materiasSource[i];
	}
	std::cout << "Destroying MateriaSource" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &orig)
{
	for (int i = 0; i < 4; i++)
	{
		if (orig._materiasSource[i])
			_materiasSource[i] = orig._materiasSource[i]->clone();
		else
			_materiasSource[i] = NULL;
	}
	std::cout << "Copying the MateriaSource from another MateriaSource" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_materiasSource[i])
				delete _materiasSource[i];
			if (rhs._materiasSource[i])
				_materiasSource[i] = rhs._materiasSource[i]->clone();
			else
				_materiasSource[i] = NULL;
		}
	}
	std::cout << "Assigning the MateriaSource from another MateriaSource" << std::endl;
	return (*this);
}

void MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_materiasSource[i])
		{
			_materiasSource[i] = materia;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materiasSource[i] && _materiasSource[i]->getType() == type)
			return _materiasSource[i]->clone();
	}
	return (NULL);
}