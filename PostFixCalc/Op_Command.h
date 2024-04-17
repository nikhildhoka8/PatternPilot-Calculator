#ifndef OP_COMMAND_H
#define OP_COMMAND_H

#include "Command.h"


class Op_Command : public Command
{
    public:
        Op_Command() = default;
        virtual ~Op_Command() = default;
        virtual void execute(Stack <int> & stack) = 0;
        virtual int getPrecedence() = 0;
};
#endif