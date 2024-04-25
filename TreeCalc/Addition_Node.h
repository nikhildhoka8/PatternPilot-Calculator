#ifndef ADDITION_NODE_H
#define ADDITION_NODE_H
#include "Op_Node.h"
#include "../Templates/Stack.h"
#include "Node_Visitor.h"

class Addition_Node : public Op_Node
{
public:
    
    Addition_Node ();
    ~Addition_Node ();
    int getPrecedence() override;
    std::string token();
    void accept(Node_Visitor& visitor) override;
    void execute(Stack<int>& stack);
};
#include "Addition_Node.cpp"
#endif // !ADDITION_NODE_H
