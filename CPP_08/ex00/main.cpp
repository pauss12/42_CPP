#include "easyFind.hpp"
#include <vector>
#include <list>
#include <iostream>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0m"

int main(void)
{
    int passed = 0;
    int failed = 0;

    std::cout << YELLOW << "=== easyfind Tester v1 ===" << RESET << std::endl;

    std::cout << "\nTest 1: Vector con valor encontrado" << std::endl;
    {
        std::vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);
        try
        {
            easyfind(v, 3);
            std::cout << GREEN << "[OK]" << RESET << " value found" << std::endl;
            passed++;
        }
        catch (const NotFoundException &e)
        {
            std::cout << RED << "[FAIL]" << RESET << " " << e.what() << std::endl;
            failed++;
        }
    }

    std::cout << "\nTest 2: Vector con valor NO encontrado" << std::endl;
    {
        std::vector<int> v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);
        try
        {
            easyfind(v, 99);
            std::cout << RED << "[FAIL]" << RESET << " value unexpectedly found" << std::endl;
            failed++;
        }
        catch (const NotFoundException &e)
        {
            std::cout << GREEN << "[OK]" << RESET << " " << e.what() << std::endl;
            passed++;
        }
    }

    std::cout << "\nTest 3: List con valor encontrado" << std::endl;
    {
        std::list<int> lst;
        lst.push_back(100);
        lst.push_back(200);
        lst.push_back(300);
        try
        {
            easyfind(lst, 200);
            std::cout << GREEN << "[OK]" << RESET << " value found" << std::endl;
            passed++;
        }
        catch (const NotFoundException &e)
        {
            std::cout << RED << "[FAIL]" << RESET << " " << e.what() << std::endl;
            failed++;
        }
    }

    std::cout << "\nTest 4: Contenedor vacío" << std::endl;
    {
        std::vector<int> empty;
        try
        {
            easyfind(empty, 5);
            std::cout << RED << "[FAIL]" << RESET << " no exception for empty container" << std::endl;
            failed++;
        }
        catch (const NotFoundException &e)
        {
            std::cout << GREEN << "[OK]" << RESET << " " << e.what() << std::endl;
            passed++;
        }
    }

    std::cout << "\nSummary: " << GREEN << passed << " passed" << RESET << ", " << (failed ? RED : GREEN) << failed << " failed" << RESET << std::endl;
    return (failed == 0 ? 0 : 1);
}
