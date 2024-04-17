#ifndef MODULUS_NODE_H
#define MODULUS_NODE_H

#include "Op_Node.h"



class Modulus_Node : public Op_Node
{
public:
    Modulus_Node (std::unique_ptr<Command_Node> leftNode, std::unique_ptr<Command_Node> rightNode);
    ~Modulus_Node(void);
};
#include "Modulus_Node.cpp"
#endif // !MODULUS_NODE_H
