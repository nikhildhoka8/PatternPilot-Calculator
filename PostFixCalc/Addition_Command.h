#ifndef ADDITION_COMMAND_H
#define ADDITION_COMMAND_H

#include "Op_Command.h"
#include "../Templates/Stack.h"

class Addition_Command : public Op_Command
{
public:
    Addition_Command (void);
    ~Addition_Command (void);
    void execute (Stack <int> & stack) override;
    int getPrecedence (void) override;
    void token(void) override;
};
#include "Addition_Command.cpp"
#endif