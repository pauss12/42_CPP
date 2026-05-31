#include "RPN.hpp"

int main(int argc, char *argv[])
{
    RPN rpn;
    std::string result;

    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <file.rpn>" << std::endl;
        return (1);
    }
    // Se le va a pasar una operacion
    result = rpn.evaluate(argv[1]);
    std::cout << result << std::endl;
    return (0);
}