// Execute_Visitor.h
#ifndef EXECUTE_VISITOR_H
#define EXECUTE_VISITOR_H

#include "../Templates/Stack.h"
#include "Number_Node.h"
#include "Addition_Node.h"
#include "Subtraction_Node.h"
#include "Multiplication_Node.h"
#include "Division_Node.h"
#include "Modulus_Node.h"
#include <stdexcept>

class Execute_Visitor : public Node_Visitor {
private:
    Stack<int> stack_;

public:
    void visit(Number_Node& node) override;
    void visit(Addition_Node& node) override;
    void visit(Subtraction_Node& node) override;
    void visit(Multiplication_Node& node) override;
    void visit(Division_Node& node) override;
    void visit(Modulus_Node& node) override;

    int getResult();
};
#include "Execute_Visitor.cpp"
#endif // EXECUTE_VISITOR_H
