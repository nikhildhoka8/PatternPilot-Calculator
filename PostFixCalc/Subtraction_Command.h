#ifndef SUBTRACTION_COMMAND_H
#define SUBTRACTION_COMMAND_H

#include "Op_Command.h"
#include "../Templates/Stack.h"

class Subtraction_Command : public Op_Command {
public:
    Subtraction_Command();
    ~Subtraction_Command();
    void execute(Stack<int>& stack) override;
    int getPrecedence() override;
    void token(void) override;
};
#include "Subtraction_Command.cpp"
#endif // SUBTRACTION_COMMAND_H
