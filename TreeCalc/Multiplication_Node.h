#ifndef MUltiplication_Node_h
#define MUltiplication_Node_h
#include "Op_Node.h"

class Multiplication_Node : public Op_Node
{
    public:
        Multiplication_Node (std::unique_ptr<Command_Node> leftNode, std::unique_ptr<Command_Node> rightNode);
        virtual ~Multiplication_Node();
};
#include "Multiplication_Node.cpp"
#endif // !MUltiplication_Node_h