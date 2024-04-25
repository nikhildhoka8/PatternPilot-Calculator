#ifndef MUltiplication_Node_h
#define MUltiplication_Node_h
#include "Op_Node.h"
#include "Node_Visitor.h"


class Multiplication_Node : public Op_Node
{
    public:
        Multiplication_Node ();
        virtual ~Multiplication_Node();
        int getPrecedence();
        std::string token();
        void execute(Stack<int>& stack);
        void accept(Node_Visitor& visitor) override;
};
#include "Multiplication_Node.cpp"
#endif // !MUltiplication_Node_h