#pragma once
#ifndef COMMAND_NODE_H
#define COMMAND_NODE_H
#include "Node_Visitor.h"

class Command_Node
{
public:
    friend class Node_Visitor;
    Command_Node (void);
    virtual ~Command_Node (void);
    virtual std::string token (void) = 0;
    virtual void accept(Node_Visitor& visitor) = 0;
};
#include "Command_Node.cpp"
#endif
