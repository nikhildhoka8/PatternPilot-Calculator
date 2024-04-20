#ifndef NODE_VISITOR_H
#define NODE_VISITOR_H

#include "Number_Node.h"
#include "Addition_Node.h"
#include "Subtraction_Node.h"
#include "Multiplication_Node.h"
#include "Division_Node.h"
#include "Modulus_Node.h"

class Node_Visitor
{
public:
    virtual void visit(Number_Node& node) = 0;
    virtual void visit(Addition_Node& node) = 0;
    virtual void visit(Subtraction_Node& node) = 0;
    virtual void visit(Multiplication_Node& node) = 0;
    virtual void visit(Division_Node& node) = 0;
    virtual void visit(Modulus_Node& node) = 0;
};
#endif