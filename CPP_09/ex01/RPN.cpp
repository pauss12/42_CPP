#include "RPN.hpp"

RPN::RPN()
{
    // std::cout << "RPN Constructor called" << std::endl;
}

RPN::RPN(const RPN &other)
{
    // std::cout << "RPN Copy constructor called" << std::endl;
    this->_stack = other._stack;
}

RPN &RPN::operator=(const RPN &other)
{
    // std::cout << "RPN Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_stack = other._stack;
    return (*this);
}

RPN::~RPN()
{
    // std::cout << "RPN Destructor called" << std::endl;
}

// ######################## FUNCIONES --------------------------------------
std::string RPN::evaluate(const std::string operations)
{
    int i;

    i = 0;
    while (operations[i])
    {
            if (operations[i] >= '0' && operations[i] <= '9')
                _stack.push(operations[i] - '0');
            else if (operations[i] == '+' || operations[i] == '-' || operations[i] == '*' || operations[i] == '/')
            {
                if (_stack.size() < 2)
                    return "Error: not enough operands for operator '" + std::string(1, operations[i]) + "'";
                int b = _stack.top();
                _stack.pop();
                int a = _stack.top();
                _stack.pop();
                int result;
                switch (operations[i])
                {
                    case '+':
                        result = a + b;
                        break;
                    case '-':
                        result = a - b;
                        break;
                    case '*':
                        result = a * b;
                        break;
                    case '/':
                        if (b == 0)
                            return "Error: division by zero";
                        result = a / b;
                        break;
                }
                _stack.push(result);
            }
            else if (operations[i] != ' ')
                return std::string("Error: invalid character '") + operations[i] + "'";
        i++;
    }
    if (_stack.size() != 1)
        return "Error: too many operands";
    return (std::to_string(_stack.top()));
}