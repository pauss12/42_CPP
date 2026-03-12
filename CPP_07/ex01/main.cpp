#include <iostream>
#include <string>
#include "whatever.hpp"

int main()
{
    // int test
    int a = 2;
    int b = 3;
    std::cout << "ints: a = " << a << ", b = " << b << '\n';
    ::swap(a, b);
    std::cout << " after swap: a = " << a << ", b = " << b << '\n';
    std::cout << " min(a,b) = " << ::min(a, b) << ", max(a,b) = " << ::max(a, b) << "\n\n";

    // string test
    std::string s1 = "chaine1";
    std::string s2 = "chaine2";
    std::cout << "strings: s1 = " << s1 << ", s2 = " << s2 << '\n';
    ::swap(s1, s2);
    std::cout << " after swap: s1 = " << s1 << ", s2 = " << s2 << '\n';
    std::cout << " min(s1,s2) = " << ::min(s1, s2) << ", max(s1,s2) = " << ::max(s1, s2) << "\n\n";

    // const correctness test
    const int c1 = 42;
    const int c2 = 24;
    std::cout << "const min: min(c1,c2) = " << ::min(c1, c2) << "\n\n";

    // float test
    float f1 = 1.5f;
    float f2 = 2.5f;
    std::cout << "floats: f1 = " << f1 << ", f2 = " << f2 << '\n';
    ::swap(f1, f2);
    std::cout << " after swap: f1 = " << f1 << ", f2 = " << f2 << '\n';
    std::cout << " min(f1,f2) = " << ::min(f1, f2) << ", max(f1,f2) = " << ::max(f1, f2) << "\n";

    return 0;
}
```// filepath: /home/pmendez-/Desktop/cpp/CPP_07/ex01/main.cpp
#include <iostream>
#include <string>
#include "whatever.hpp"

int main()
{
    // int test
    int a = 2;
    int b = 3;
    std::cout << "ints: a = " << a << ", b = " << b << '\n';
    ::swap(a, b);
    std::cout << " after swap: a = " << a << ", b = " << b << '\n';
    std::cout << " min(a,b) = " << ::min(a, b) << ", max(a,b) = " << ::max(a, b) << "\n\n";

    // string test
    std::string s1 = "chaine1";
    std::string s2 = "chaine2";
    std::cout << "strings: s1 = " << s1 << ", s2 = " << s2 << '\n';
    ::swap(s1, s2);
    std::cout << " after swap: s1 = " << s1 << ", s2 = " << s2 << '\n';
    std::cout << " min(s1,s2) = " << ::min(s1, s2) << ", max(s1,s2) = " << ::max(s1, s2) << "\n\n";

    // const correctness test
    const int c1 = 42;
    const int c2 = 24;
    std::cout << "const min: min(c1,c2) = " << ::min(c1, c2) << "\n\n";

    // float test
    float f1 = 1.5f;
    float f2 = 2.5f;
    std::cout << "floats: f1 = " << f1 << ", f2 = " << f2 << '\n';
    ::swap(f1, f2);
    std::cout << " after swap: f1 = " << f1 << ", f2 = " << f2 << '\n';
    std::cout << " min(f1,f2) = " << ::min(f1, f2) << ", max(f1,f2) = " << ::max(f1, f2) << "\n";

    return 0;
}