#ifndef ADDITION_NODE_H
#define ADDITION_NODE_H
#include "Op_Node.h"
#include "../Templates/Stack.h"

class Addition_Node : public Op_Node
{
public:
    
    Addition_Node ();
    ~Addition_Node ();
    int getPrecedence() override;
    std::string token();
};
#include "Addition_Node.cpp"
#endif // !ADDITION_NODE_H
