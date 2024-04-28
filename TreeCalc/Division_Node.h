#pragma once
#ifndef DIVISION_NODE_H
#define DIVISION_NODE_H

#include "Op_Node.h"
#include "../Templates/Stack.h"
class Node_Visitor;


class Division_Node : public Op_Node
{
public:
    Division_Node (void);
    ~Division_Node ();
    int getPrecedence();
    std::string token() override;
    void accept(Node_Visitor& visitor);
};
#include "Division_Node.cpp"
#endif