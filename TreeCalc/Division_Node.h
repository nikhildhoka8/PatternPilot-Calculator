#ifndef DIVISION_NODE_H
#define DIVISION_NODE_H

#include "Op_Node.h"

class Division_Node : public Op_Node
{
public:
    Division_Node (void);
    ~Division_Node ();
    int getPrecedence();
    void token() override;
};
#include "Division_Node.cpp"
#endif