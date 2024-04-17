#include "Multiplication_Command.h"

Multiplication_Command::Multiplication_Command() 
{
}

Multiplication_Command::~Multiplication_Command()
{
}

void Multiplication_Command::execute(Stack<int>& stack) {
    int n1 = stack.top(); stack.pop();
    int n2 = stack.top(); stack.pop();
    stack.push(n2 * n1);
}

int Multiplication_Command::getPrecedence() {
    return 2;
}

void Multiplication_Command::token(void)
{
    std::cout << "*";
}
