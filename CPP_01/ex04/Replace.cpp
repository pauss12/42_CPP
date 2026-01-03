# include "Replace.hpp"

static int check_if_full_empty(std::ifstream &file)
{
	std::string line;
	while (std::getline(file, line))
	{
		if (!line.empty())
			return (0);
	}
	return (1);
}

Replace::Replace()
{
	this->filename = "";
	this->lookFor = "";
	this->replaceWith = "";
	this->createdFile  = "";
}

Replace::~Replace()
{
	if (this->infile.is_open())
		this->infile.close();
	if (this->outfile.is_open())
		this->outfile.close();
}

Replace::Replace(std::string filename, std::string lookFor, std::string replaceWith)
{
	this->filename = filename;
	this->lookFor = lookFor;
	this->replaceWith = replaceWith;
	this->createdFile = filename + ".replace";
}

int Replace::checkInfile()
{
	this->infile.open(this->filename.c_str());
	if (!this->infile.is_open()) 
	{
		std::cout << RED "Error" RESET << std::endl;
		std::cout << "Error de apertura: El fichero '" << this->filename << "' no se pudo abrir." << std::endl;
		return (1);
	}
	if (this->infile.peek() == EOF) 
	{
		this->infile.close();
		std::cout << ORANGE << "ADVERTENCIA" << RESET << std::endl;
		std::cout << "El fichero de entrada '" << this->filename << "' está vacío." << std::endl;
		return (1);
	}
	if (check_if_full_empty(this->infile))
	{
		this->infile.close();
		std::cout << ORANGE << "ERROR" << RESET << std::endl;
		std::cout << "El fichero de entrada '" << this->filename << "' solo contiene saltos de linea." << std::endl;
		return (1);
	}
	return (0);
}

static bool containsMatch(std::ifstream &infile, const std::string &lookFor)
{
	std::string line;

	while (std::getline(infile, line))
	{
		if (line.find(lookFor) != std::string::npos)
			return true;
	}
	return false;
}

void Replace::CreateNewFile()
{
	if (checkInfile() == 1)
		return ;
	if (!containsMatch(this->infile, this->lookFor))
	{
		this->infile.close();
		std::cout << RED << "ERROR" << RESET << std::endl;
		std::cout << "No se encontraron coincidencias en el fichero: " << this->filename << std::endl;
		return ;
	}
	this->outfile.open(this->createdFile.c_str());
	if (!this->outfile.is_open())
	{
		this->infile.close();
		std::cout << RED "Error" RESET << std::endl << "Fallo al abrir el fichero: " << this->filename << std::endl;
		return ;
	}
	this->writeFile();
	this->infile.close();
	this->outfile.close();	
}

std::string Replace::replaceLine(std::string line)
{
	size_t	pos;

	pos = 0;
	while ((pos = line.find(this->lookFor, pos)) != std::string::npos)
	{
		line.erase(pos, this->lookFor.length());
		line.insert(pos, this->replaceWith);
		pos += this->replaceWith.length();
	}
	return (line);
}

void Replace::writeFile()
{
	std::string line;
	std::string replaced;

	while (std::getline(this->infile, line))
	{
		replaced = this->replaceLine(line);
		this->outfile << replaced;
		if (!this->infile.eof())
			this->outfile << std::endl;

	}
}