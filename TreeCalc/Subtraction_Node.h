#ifndef SUBTRACTION_NODE_H
#define SUBTRACTION_NODE_H
#include "Op_Node.h"
class Subtraction_Node : public Op_Node
{
public:
    Subtraction_Node(void);
    ~Subtraction_Node();
    int getPrecedence();
    void token();
    
};
#include "Subtraction_Node.cpp"
#endif