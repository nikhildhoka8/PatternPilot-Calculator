#ifndef OP_NODE_H
#define OP_NODE_H
#include <memory>

#include "Command_Node.h"
#include "Number_Node.h"
#include "Node_Visitor.h"


class Op_Node : public Command_Node
{
    public:
        //constructor
        Op_Node(void);
        //destructor
        ~Op_Node();
        void setLeft(std::shared_ptr<Command_Node> left);
        void setRight(std::shared_ptr<Command_Node> right);
        std::shared_ptr<Command_Node> getLeft();
        std::shared_ptr<Command_Node> getRight();
        virtual int getPrecedence() = 0;
        virtual std::string token() = 0;
        virtual void execute(Stack<int>& stack) = 0;
    protected:
        std::shared_ptr<Command_Node> left_;
        std::shared_ptr<Command_Node> right_;
};
#include "Op_Node.cpp"
#endif