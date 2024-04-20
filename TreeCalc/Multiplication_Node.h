#ifndef MUltiplication_Node_h
#define MUltiplication_Node_h
#include "Op_Node.h"

class Multiplication_Node : public Op_Node
{
    public:
        Multiplication_Node ();
        virtual ~Multiplication_Node();
        int getPrecedence();
        void token();
};
#include "Multiplication_Node.cpp"
#endif // !MUltiplication_Node_h