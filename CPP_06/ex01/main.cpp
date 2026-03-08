#include "Serializer.hpp"
#include <iostream>
#include <string>

static void print_data(const char *label, const Data &d)
{
	std::cout << "--- " << label << " ---" << std::endl;
	std::cout << "id:      " << d.identifier << std::endl;
	std::cout << "content: " << d.content << std::endl << std::endl;
}

int main(void)
{
	Data data;

	data.identifier = 42;
	data.content = "Hello, World!";

	print_data("Original", data);

	std::cout << "It has been serialized into a uintptr_t" << std::endl << std::endl;
	uintptr_t raw = Serializer::serialize(&data);
	Data *deserialized = Serializer::deserialize(raw);

	if (deserialized)
		print_data("Deserialized", *deserialized);
	else
		std::cerr << "Deserialization failed (null pointer)\n";

	return 0;
}