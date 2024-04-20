#ifndef ADDITION_NODE_H
#define ADDITION_NODE_H
#include "Op_Node.h"
class Addition_Node : public Op_Node
{
public:
    
    Addition_Node ();
    ~Addition_Node ();
    int getPrecedence() override;
    void token();
};
#include "Addition_Node.cpp"
#endif // !ADDITION_NODE_H
