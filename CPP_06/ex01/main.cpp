#include "Serializer.hpp"
#include <iostream>
#include <string>

#include "Serializer.hpp"

void print_data(const std::string& label, Data* d)
{
	if (!d)
	{
		std::cout << RED << label << " [ERROR]: NULL Pointer" << RESET << std::endl;
		return;
	}
	std::cout << label << std::endl;
	std::cout << "id:      " << d->identifier << std::endl;
	std::cout << "content: " << d->content << std::endl;
}

int main()
{
	Data original;
	original.identifier = 42;
	original.content = "Control Flow Obfuscation";

	print_data("--- Original ---", &original);

	// 1. Valid Serialization
	uintptr_t raw = Serializer::serialize(&original);
	std::cout << "\nSerialized: 0x" << std::hex << raw << std::dec << std::endl;

	Data* deserialized = Serializer::deserialize(raw);

	// Validate before accessing memory
	if (deserialized == &original)
	{
		std::cout << GREEN << "[SUCCESS] Pointers match!" << RESET << std::endl;
		print_data("--- Deserialized ---", deserialized);
	}
	else
	{
		std::cout << RED << "[ERROR] Pointer mismatch detected!" << RESET << std::endl;
	}

	// 2. Controlled Corruption Test
	std::cout << "\n--- Testing Corruption Handling ---" << std::endl;
	uintptr_t corruptedRaw = raw + 100; // Simulated corrupt address
	Data* corruptedPtr = Serializer::deserialize(corruptedRaw);

	// CHECK FIRST: Never print/dereference corruptedPtr directly!
	if (corruptedPtr != &original)
	{
		std::cout << YELLOW << "[CONTROLLED TEST] Corrupted address detected (0x" 
				  << std::hex << corruptedRaw << std::dec 
				  << "). Access blocked to prevent SEGV." << RESET << std::endl;
	}
	else
	{
		print_data("--- Corrupted Deserialized ---", corruptedPtr);
	}

	return 0;
}
