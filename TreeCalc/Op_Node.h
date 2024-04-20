#ifndef OP_NODE_H
#define OP_NODE_H
#include <memory>

#include "Command_Node.h"
#include "Number_Node.h"

class Op_Node : public Command_Node
{
    public:
        //constructor
        Op_Node(void);
        //destructor
        ~Op_Node();
        void setLeft(std::unique_ptr<Command_Node> left);
        void setRight(std::unique_ptr<Command_Node> right);
        std::unique_ptr<Command_Node> getLeft();
        std::unique_ptr<Command_Node> getRight();
        virtual int getPrecedence() = 0;
        virtual void token() = 0;
    protected:
        std::unique_ptr<Command_Node> left_;
        std::unique_ptr<Command_Node> right_;
};
#include "Op_Node.cpp"
#endif