#include <iostream>

int main()
{
	std::string name = "HI THIS IS BRAIN";
	std::string *ptr = &name;
	std::string &ref = name;

	// Display the address of the string, the adress of the pointer and the address of the reference
	std::cout << "Address of the string: " << &name << std::endl;
	std::cout << "Address of the pointer: " << ptr << std::endl;
	std::cout << "Address of the reference: " << &ref << std::endl;


	// Display the string using the pointer
	std::cout << "String using the pointer: " << *ptr << std::endl;
	std::cout << "String using the reference: " << ref << std::endl;
	std::cout << "String using the string: " << name << std::endl;

	return (0);
}