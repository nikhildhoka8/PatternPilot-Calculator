#ifndef COMMAND_H
#define COMMAND_H
#include "../Templates/Stack.h"

class Command
{

public:
    Command(void) = default;
    virtual ~Command(void) = default;
    virtual void execute(Stack<int>& stack) = 0;
    virtual void token(void) = 0;
};

#endif // !COMMAND_H