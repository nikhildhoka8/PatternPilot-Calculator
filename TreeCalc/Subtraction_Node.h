#ifndef SUBTRACTION_NODE_H
#define SUBTRACTION_NODE_H
#include "Op_Node.h"
#include "../Templates/Stack.h"
#include "Node_Visitor.h"

class Subtraction_Node : public Op_Node
{
public:
    Subtraction_Node(void);
    ~Subtraction_Node();
    int getPrecedence();
    std::string token();
    void execute(Stack<int>& stack);
    void accept(Node_Visitor& visitor) override;
    
};
#include "Subtraction_Node.cpp"
#endif