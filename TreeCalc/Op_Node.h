#ifndef OP_NODE_H
#define OP_NODE_H
#include <memory>

#include "Command_Node.h"
#include "Number_Node.h"

class Op_Node : public Command_Node
{
    public:
        //constructor
        Op_Node(std::unique_ptr<Command_Node> left, std::unique_ptr<Command_Node> right);
        //destructor
        ~Op_Node();
        virtual std::unique_ptr<Number_Node> execute() = 0;
    protected:
        std::unique_ptr<Command_Node> left_;
        std::unique_ptr<Command_Node> right_;
};
#include "Op_Node.cpp"
#endif