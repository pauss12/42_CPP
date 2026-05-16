#include "Array.hpp"
#include <iostream>

int main(void)
{
	// Test 1: Constructor sin parámetros
	{
		std::cout << "=== Test 1: Constructor sin parámetros ===" << std::endl;
		Array<int> arr;
		std::cout << "Size: " << arr.size() << std::endl;
		std::cout << std::endl;
	}

	// Test 2: Constructor con tamaño
	{
		std::cout << "=== Test 2: Constructor con tamaño ===" << std::endl;
		Array<int> arr(5);
		std::cout << "Size: " << arr.size() << std::endl;
		for (unsigned int i = 0; i < arr.size(); i++)
			std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
		std::cout << std::endl;
	}

	// Test 3: Asignación de valores
	{
		std::cout << "=== Test 3: Asignación de valores ===" << std::endl;
		Array<int> arr(3);
		arr[0] = 10;
		arr[1] = 20;
		arr[2] = 30;
		for (unsigned int i = 0; i < arr.size(); i++)
			std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
		std::cout << std::endl;
	}

	// Test 4: Copy constructor
	{
		std::cout << "=== Test 4: Copy constructor ===" << std::endl;
		Array<int> original(3);
		original[0] = 1;
		original[1] = 2;
		original[2] = 3;
		
		Array<int> copy = original;
		std::cout << "Original: ";
		for (unsigned int i = 0; i < original.size(); i++)
			std::cout << original[i] << " ";
		std::cout << std::endl;
		
		std::cout << "Copy: ";
		for (unsigned int i = 0; i < copy.size(); i++)
			std::cout << copy[i] << " ";
		std::cout << std::endl;
		
		// Modificar original NO afecta copy
		original[0] = 999;
		std::cout << "Después de modificar original[0] = 999:" << std::endl;
		std::cout << "Original[0]: " << original[0] << std::endl;
		std::cout << "Copy[0]: " << copy[0] << std::endl;
		std::cout << std::endl;
	}

	// Test 5: Assignment operator
	{
		std::cout << "=== Test 5: Assignment operator ===" << std::endl;
		Array<int> a(2);
		a[0] = 100;
		a[1] = 200;
		
		Array<int> b(4);
		b[0] = 1;
		b[1] = 2;
		b[2] = 3;
		b[3] = 4;
		
		std::cout << "Antes de asignación:" << std::endl;
		std::cout << "a.size() = " << a.size() << ", b.size() = " << b.size() << std::endl;
		
		b = a;
		std::cout << "Después de b = a:" << std::endl;
		std::cout << "b.size() = " << b.size() << std::endl;
		std::cout << "b: ";
		for (unsigned int i = 0; i < b.size(); i++)
			std::cout << b[i] << " ";
		std::cout << std::endl;
		
		// Modificar a NO afecta b
		a[0] = 777;
		std::cout << "Después de a[0] = 777:" << std::endl;
		std::cout << "a[0] = " << a[0] << ", b[0] = " << b[0] << std::endl;
		std::cout << std::endl;
	}

	// Test 6: Out of bounds exception
	{
		std::cout << "=== Test 6: Out of bounds exception ===" << std::endl;
		Array<int> arr(3);
		try
		{
			std::cout << "Intentando acceder a arr[5]..." << std::endl;
			arr[5] = 10;
		}
		catch (const std::exception &e)
		{
			std::cout << "Excepción capturada: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	// Test 7: Array de strings
	{
		std::cout << "=== Test 7: Array de strings ===" << std::endl;
		Array<std::string> arr(3);
		arr[0] = "Hola";
		arr[1] = "Mundo";
		arr[2] = "CPP";
		for (unsigned int i = 0; i < arr.size(); i++)
			std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
		std::cout << std::endl;
	}

	// Test 8: Array vacío y acceso
	{
		std::cout << "=== Test 8: Array vacío ===" << std::endl;
		Array<int> empty;
		std::cout << "Size: " << empty.size() << std::endl;
		try
		{
			empty[0] = 10;
		}
		catch (const std::exception &e)
		{
			std::cout << "Excepción al acceder a array vacío: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	return (0);
}
