#include "Division_Command.h"
#include <stdexcept> // For std::runtime_error

Division_Command::Division_Command() 
{
}

Division_Command::~Division_Command() 
{
}

void Division_Command::execute(Stack<int>& stack) {
    int n1 = stack.top(); stack.pop();
    int n2 = stack.top(); stack.pop();
    if (n1 == 0)
    {
        throw std::runtime_error("Division by zero.");
    }
    stack.push(n2 / n1);
}

int Division_Command::getPrecedence() {
    return 2;
}

void Division_Command::token(void)
{
    std::cout << "/";
}