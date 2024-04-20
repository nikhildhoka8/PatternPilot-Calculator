#ifndef EXECUTE_VISITOR_H
#define EXECUTE_VISITOR_H
#include "Node_Visitor.h"
#include "Number_Node.h"
#include "Addition_Node.h"
#include "Subtraction_Node.h"
#include "Multiplication_Node.h"
#include "Division_Node.h"
#include "Modulus_Node.h"


class Execute_Visitor: public Node_Visitor
{
public:
    void visit(Number_Node & node) override;
    void visit(Addition_Node & node) override;
    void visit(Subtraction_Node & node) override;
    void visit(Multiplication_Node & node) override;
    void visit(Division_Node & node) override;
    void visit(Modulus_Node & node) override;
};
#include "Execute_Visitor.cpp"
#endif