#pragma once
#ifndef SUBTRACTION_NODE_H
#define SUBTRACTION_NODE_H

#include "Op_Node.h"
class Node_Visitor;
#include "../Templates/Stack.h"

class Subtraction_Node : public Op_Node
{
public:
    Subtraction_Node(void);
    ~Subtraction_Node();
    int getPrecedence();
    std::string token();
    void accept (Node_Visitor &visitor);
    
};
#include "Subtraction_Node.cpp"
#endif