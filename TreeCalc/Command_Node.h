#ifndef COMMAND_NODE_H
#define COMMAND_NODE_H

class Command_Node
{
public:
    Command_Node (void) = default;
    virtual ~Command_Node (void) = default;
    virtual void token (void) = 0;
};
#endif
