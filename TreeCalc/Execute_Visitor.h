// Execute_Visitor.h
#pragma once
#ifndef EXECUTE_VISITOR_H
#define EXECUTE_VISITOR_H

#include "../Templates/Stack.h"
#include "Node_Visitor.h"
class Number_Node;
class Addition_Node;
class Subtraction_Node;
class Multiplication_Node;
class Division_Node;
class Modulus_Node;
class Command_Node;
class Op_Node;
#include <stdexcept>

class Execute_Visitor : public Node_Visitor {
private:
    Stack<int> stack_;

public:
    Execute_Visitor();
    ~Execute_Visitor();
    void visit_number_node(Number_Node& node) override;
    void visit_addition_node(Addition_Node& node) override;
    void visit_subtraction_node(Subtraction_Node& node) override;
    void visit_multiplication_node(Multiplication_Node& node) override;
    void visit_division_node(Division_Node& node) override;
    void visit_modulus_node(Modulus_Node& node) override;
    int getResult();
};
#include "Execute_Visitor.cpp"
#endif // EXECUTE_VISITOR_H
