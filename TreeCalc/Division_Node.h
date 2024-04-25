#ifndef DIVISION_NODE_H
#define DIVISION_NODE_H

#include "Op_Node.h"
#include "../Templates/Stack.h"
#include "Node_Visitor.h"
class Division_Node : public Op_Node
{
public:
    Division_Node (void);
    ~Division_Node ();
    int getPrecedence();
    std::string token() override;
    void execute(Stack<int>& stack) override;
    void accept(Node_Visitor& visitor) override;    
};
#include "Division_Node.cpp"
#endif