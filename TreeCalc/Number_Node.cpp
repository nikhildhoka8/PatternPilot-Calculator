#include <iostream>

Number_Node::Number_Node(int num)
{
    this->num_ = num;
}

Number_Node::~Number_Node()
{
}

int Number_Node::get_value()
{
    return this->num_;
}