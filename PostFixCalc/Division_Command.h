#ifndef DIVISION_COMMAND_H
#define DIVISION_COMMAND_H

#include "Op_Command.h"
#include "../Templates/Stack.h"

class Division_Command : public Op_Command {
public:
    Division_Command();
    ~Division_Command();
    void execute(Stack<int>& stack) override;
    int getPrecedence() override;
    void token(void) override;
};
#include "Division_Command.cpp"
#endif // DIVISION_COMMAND_H
