#pragma once
#ifndef NODE_VISITOR_H
#define NODE_VISITOR_H


class Number_Node;
class Addition_Node;
class Subtraction_Node;
class Multiplication_Node;
class Division_Node;
class Modulus_Node;


class Node_Visitor
{
public:
    Node_Visitor();
    ~Node_Visitor();
    virtual void visit_number_node(Number_Node& node) = 0;
    virtual void visit_addition_node(Addition_Node& node) = 0;
    virtual void visit_subtraction_node(Subtraction_Node& node) = 0;
    virtual void visit_multiplication_node(Multiplication_Node& node) = 0;
    virtual void visit_division_node(Division_Node& node) = 0;
    virtual void visit_modulus_node(Modulus_Node& node) = 0;
};
#include "Node_Visitor.cpp"
#endif // NODE_VISITOR_H