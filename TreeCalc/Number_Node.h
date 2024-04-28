#pragma once
#ifndef NUMBER_NODE_H
#define NUMBER_NODE_H

#include <memory>
#include "Command_Node.h"
class Node_Visitor;

class Number_Node: public Command_Node{
public:
    Number_Node(int num);
    ~Number_Node();
    int getNumber();
    std::string token();
    void accept(Node_Visitor& visitor);
private:
    int num_;

};
#include "Number_Node.cpp"
#endif // !NUMBER_NODE_H