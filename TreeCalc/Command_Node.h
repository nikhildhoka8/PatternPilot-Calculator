#ifndef COMMAND_NODE_H
#define COMMAND_NODE_H
#include "Node_Visitor.h"


class Command_Node
{
public:
    Command_Node (void) = default;
    virtual ~Command_Node (void) = default;
    virtual std::string token (void) = 0;
    virtual void accept (Node_Visitor& visitor) = 0;
};
#endif
