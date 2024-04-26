#ifndef MODULUS_NODE_H
#define MODULUS_NODE_H

#include "Op_Node.h"
#include "../Templates/Stack.h"

class Modulus_Node : public Op_Node
{
public:
    Modulus_Node ();
    ~Modulus_Node(void);
    int getPrecedence();
    std::string token();
};
#include "Modulus_Node.cpp"
#endif // !MODULUS_NODE_H
