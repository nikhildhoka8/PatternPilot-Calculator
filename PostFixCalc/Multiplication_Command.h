#ifndef MULTIPLICATION_COMMAND_H
#define MULTIPLICATION_COMMAND_H

#include "Op_Command.h"
#include "../Templates/Stack.h"

class Multiplication_Command : public Op_Command {
public:
    Multiplication_Command();
    ~Multiplication_Command();
    void execute(Stack<int>& stack) override;
    int getPrecedence() override;
    void token(void) override;
};
#include "Multiplication_Command.cpp"
#endif // MULTIPLICATION_COMMAND_H
