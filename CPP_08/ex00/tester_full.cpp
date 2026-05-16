#include "easyFind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <iostream>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0m"

int main(void)
{
    int passed = 0;
    int failed = 0;

    std::cout << YELLOW << "=== easyfind Extended Tester ===" << RESET << std::endl;

    // 1 - First element
    std::cout << "\n[1] First element (vector)" << std::endl;
    {
        std::vector<int> v;
        v.push_back(42);
        v.push_back(1);
        v.push_back(2);
        try { easyfind(v, 42); std::cout << GREEN << "[OK]" << RESET << " found at first" << std::endl; passed++; }
        catch (const NotFoundException &e) { std::cout << RED << "[FAIL]" << RESET << " " << e.what() << std::endl; failed++; }
    }

    // 2 - Last element
    std::cout << "\n[2] Last element (vector)" << std::endl;
    {
        std::vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(99);
        try { easyfind(v, 99); std::cout << GREEN << "[OK]" << RESET << " found at last" << std::endl; passed++; }
        catch (const NotFoundException &e) { std::cout << RED << "[FAIL]" << RESET << " " << e.what() << std::endl; failed++; }
    }

    // 3 - Multiple occurrences (should find first)
    std::cout << "\n[3] Multiple occurrences (vector)" << std::endl;
    {
        std::vector<int> v;
        v.push_back(5);
        v.push_back(7);
        v.push_back(7);
        v.push_back(7);
        try { easyfind(v, 7); std::cout << GREEN << "[OK]" << RESET << " found first occurrence" << std::endl; passed++; }
        catch (const NotFoundException &e) { std::cout << RED << "[FAIL]" << RESET << " " << e.what() << std::endl; failed++; }
    }

    // 4 - Negative values
    std::cout << "\n[4] Negative values (list)" << std::endl;
    {
        std::list<int> lst;
        lst.push_back(-1);
        lst.push_back(-2);
        lst.push_back(-3);
        try { easyfind(lst, -2); std::cout << GREEN << "[OK]" << RESET << " found negative" << std::endl; passed++; }
        catch (const NotFoundException &e) { std::cout << RED << "[FAIL]" << RESET << " " << e.what() << std::endl; failed++; }
    }

    // 5 - Deque test
    std::cout << "\n[5] Deque test" << std::endl;
    {
        std::deque<int> dq;
        for (int i = 0; i < 10; ++i) dq.push_back(i*2);
        try { easyfind(dq, 8); std::cout << GREEN << "[OK]" << RESET << " found in deque" << std::endl; passed++; }
        catch (const NotFoundException &e) { std::cout << RED << "[FAIL]" << RESET << " " << e.what() << std::endl; failed++; }
    }

    // 6 - Set test (std::find works but slower)
    std::cout << "\n[6] Set test" << std::endl;
    {
        std::set<int> s;
        s.insert(10); s.insert(20); s.insert(30);
        try { easyfind(s, 20); std::cout << GREEN << "[OK]" << RESET << " found in set" << std::endl; passed++; }
        catch (const NotFoundException &e) { std::cout << RED << "[FAIL]" << RESET << " " << e.what() << std::endl; failed++; }
    }

    // 7 - Large container
    std::cout << "\n[7] Large container (1000 elements)" << std::endl;
    {
        std::vector<int> v;
        for (int i = 0; i < 1000; ++i) v.push_back(i);
        try { easyfind(v, 543); std::cout << GREEN << "[OK]" << RESET << " found in large vector" << std::endl; passed++; }
        catch (const NotFoundException &e) { std::cout << RED << "[FAIL]" << RESET << " " << e.what() << std::endl; failed++; }
    }

    // 8 - Not found
    std::cout << "\n[8] Not found case (should throw)" << std::endl;
    {
        std::vector<int> v;
        v.push_back(1); v.push_back(2);
        try { easyfind(v, 777); std::cout << RED << "[FAIL]" << RESET << " did not throw" << std::endl; failed++; }
        catch (const NotFoundException &e) { std::cout << GREEN << "[OK]" << RESET << " " << e.what() << std::endl; passed++; }
    }

    // 9 - Const container
    std::cout << "\n[9] Const container" << std::endl;
    {
        int arr_vals[] = {3, 4, 5};
        const std::vector<int> v(arr_vals, arr_vals + 3);
        try { easyfind(v, 4); std::cout << GREEN << "[OK]" << RESET << " found in const container" << std::endl; passed++; }
        catch (const NotFoundException &e) { std::cout << RED << "[FAIL]" << RESET << " " << e.what() << std::endl; failed++; }
    }

    // 10 - Repeated searches
    std::cout << "\n[10] Repeated searches" << std::endl;
    {
        std::vector<int> v;
        for (int i = 0; i < 5; ++i) v.push_back(i);
        bool ok = true;
        for (int val = 0; val < 5; ++val)
        {
            try { easyfind(v, val); }
            catch (const NotFoundException &e) { ok = false; break; }
        }
        if (ok) { std::cout << GREEN << "[OK]" << RESET << " repeated searches all found" << std::endl; passed++; }
        else { std::cout << RED << "[FAIL]" << RESET << " repeated search failure" << std::endl; failed++; }
    }

    std::cout << "\nFinal summary: " << GREEN << passed << " passed" << RESET << ", " << (failed ? RED : GREEN) << failed << " failed" << RESET << std::endl;

    return (failed == 0 ? 0 : 1);
}
