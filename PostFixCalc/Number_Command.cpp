#include <iostream>


Number_Command::Number_Command (int num)
    : num_(num)
{
}

Number_Command::~Number_Command (void)
{
}

int Number_Command::getNumber (void)
{
    return this->num_;
}

void Number_Command::token(void)
{
    std::cout << "Number: " << this->num_;
}

void Number_Command::execute (Stack<int>& stack)
{
    stack.push(this->num_);
}