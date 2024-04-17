#ifndef SUBTRACTION_NODE_H
#define SUBTRACTION_NODE_H
#include "Op_Node.h"

class Subtraction_Node : public Op_Node
{
public:
    Subtraction_Node(std::unique_ptr<Command_Node> leftNode, std::unique_ptr<Command_Node> rightNode);
    ~Subtraction_Node();
    
};
#endif