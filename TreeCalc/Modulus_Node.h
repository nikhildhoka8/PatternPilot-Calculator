#ifndef MODULUS_NODE_H
#define MODULUS_NODE_H

#include "Op_Node.h"

class Modulus_Node : public Op_Node
{
public:
    Modulus_Node ();
    ~Modulus_Node(void);
    int getPrecedence();
    void token();

};
#include "Modulus_Node.cpp"
#endif // !MODULUS_NODE_H
