#include <iostream>

Addition_Command::Addition_Command()
{
}

Addition_Command::~Addition_Command()
{
}

void Addition_Command::execute(Stack<int>& stack)
{
    int n1 = stack.top();
    stack.pop();
    int n2 = stack.top();
    stack.pop();
    int num = n1 + n2;
    stack.push(num);
}

int Addition_Command::getPrecedence()
{
    return 1;
}

void Addition_Command::token(void)
{
    std::cout << "+";
}