#ifndef DIVISION_NODE_H
#define DIVISION_NODE_H

#include "Op_Node.h"

class Division_Node : public Op_Node
{
public:
    Division_Node (std::unique_ptr<Command_Node> leftNode, std::unique_ptr<Command_Node> rightNode);
    ~Division_Node ();
};
#include "Division_Node.h"
#endif