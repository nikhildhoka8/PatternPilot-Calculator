#include "Modulus_Command.h"
#include <stdexcept> // For std::runtime_error

Modulus_Command::Modulus_Command() 
{
}

Modulus_Command::~Modulus_Command() 
{
}

void Modulus_Command::execute(Stack<int>& stack) {
    int n1 = stack.top(); stack.pop();
    int n2 = stack.top(); stack.pop();
    if (n1 == 0) 
    {
        throw std::runtime_error("Modulus by zero.");
    }
    stack.push(n2 % n1);
}

int Modulus_Command::getPrecedence() 
{
    return 2;
}

void Modulus_Command::token(void)
{
    std::cout << "%";
}