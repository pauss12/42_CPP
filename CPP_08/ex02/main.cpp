#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "El top del mstack es: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "El tamaño del mstack es: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << std::endl;

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    std::cout << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}

/**
 * 17
 * 5
 * 
 */


 /**
  * 0
  * 735
  * 5
  * 3
  * 5
  */

/**
 * IT ==> 5
 * ITE ==> 0
 */