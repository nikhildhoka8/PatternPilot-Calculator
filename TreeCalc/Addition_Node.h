#ifndef ADDITION_NODE_H
#define ADDITION_NODE_H
#include "Op_Node.h"

class Addition_Node : public Op_Node
{
public:
    Addition_Node (std::unique_ptr<Command_Node> leftNode, std::unique_ptr<Command_Node> rightNode);
    ~Addition_Node ();

    std::unique_ptr<Number_Node> execute() override;
};
#include "Addition_Node.cpp"
#endif // !ADDITION_NODE_H
