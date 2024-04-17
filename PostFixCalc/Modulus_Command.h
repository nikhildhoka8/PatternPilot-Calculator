#ifndef MODULUS_COMMAND_H
#define MODULUS_COMMAND_H

#include "Op_Command.h"
#include "../Templates/Stack.h"

class Modulus_Command : public Op_Command {
public:
    Modulus_Command();
    ~Modulus_Command();
    void execute(Stack<int>& stack) override;
    int getPrecedence() override;
    void token(void) override;
};
#include "Modulus_Command.cpp"
#endif // MODULUS_COMMAND_H
