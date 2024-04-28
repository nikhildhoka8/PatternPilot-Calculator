#pragma once
#ifndef MUltiplication_Node_h
#define MUltiplication_Node_h
#include "Op_Node.h"
class Node_Visitor;

class Multiplication_Node : public Op_Node
{
    public:
        Multiplication_Node ();
        virtual ~Multiplication_Node();
        int getPrecedence();
        std::string token();
        void accept(Node_Visitor &visitor);
};
#include "Multiplication_Node.cpp"
#endif // !MUltiplication_Node_h