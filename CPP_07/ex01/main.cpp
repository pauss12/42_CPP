#include "iter.hpp"
#include <cctype>

// Regular function taking non-const reference
void add_and_print(int &n)
{
    std::cout << CYAN << "Before change: " << n;
    n = n + 1;
    std::cout << ROSE << " | After change: " << n << RESET << std::endl;
}

// Regular function taking non-const reference
void up_and_print(std::string &str)
{
    std::cout << CYAN << "Before change: " << str;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (std::islower(str[i]))
            str[i] = std::toupper(str[i]);
        else if (std::isupper(str[i]))
            str[i] = std::tolower(str[i]);
    }
    std::cout << ROSE << " | After change: " << str << RESET << std::endl;
}

// Function template taking CONST reference (Read-Only)
template <typename T>
void print_elem(const T &elem)
{
    std::cout << GREEN << elem << " " << RESET;
}

int main(void)
{
    std::cout << BLUE << "=== Test 1: Non-const Int Array ===" << RESET << std::endl;
    {
        int tab[] = {0, 1, 2, 3, 4};
        iter(tab, 5, add_and_print);
    }

    std::cout << std::endl << BLUE << "=== Test 2: Non-const String Array ===" << RESET << std::endl;
    {
        std::string tab[] = {"Hola", "Mundo", "Desde", "CPP"};
        iter(tab, 4, up_and_print);
    }

    std::cout << std::endl << BLUE << "=== Test 3: Const Array with Instantiated Template Function ===" << RESET << std::endl;
    {
        const int const_tab[] = {10, 20, 30, 40, 50};
        std::cout << "Const int array elements: ";
        // Here we pass an instantiated template function print_elem<int>
        iter(const_tab, 5, print_elem<int>);
        std::cout << std::endl;
    }

    std::cout << std::endl << BLUE << "=== Test 4: Const String Array ===" << RESET << std::endl;
    {
        const std::string const_str_tab[] = {"Const", "String", "Test"};
        std::cout << "Const string array elements: ";
        iter(const_str_tab, 3, print_elem<std::string>);
        std::cout << std::endl;
    }

    return 0;
}