#include "Subtraction_Command.h"

Subtraction_Command::Subtraction_Command() 
{
}
Subtraction_Command::~Subtraction_Command() 
{
}

void Subtraction_Command::execute(Stack<int>& stack) {
    int n1 = stack.top(); stack.pop();
    int n2 = stack.top(); stack.pop();
    stack.push(n2 - n1);
}

int Subtraction_Command::getPrecedence() {
    return 1;
}


void Subtraction_Command::token(void)
{
    std::cout << "-";
}