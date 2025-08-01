# include "Replace.hpp"	

Replace::Replace()
{
	this->filename = "";
	this->lookFor = "";
	this->replaceWith = "";
}

Replace::~Replace()
{
	if (this->infile.is_open())
		this->infile.close();
	if (this->outfile.is_open())
		this->outfile.close();
}

