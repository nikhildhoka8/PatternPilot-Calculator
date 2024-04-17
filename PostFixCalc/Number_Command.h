#ifndef NUMBER_COMMAND_H
#define NUMBER_COMMAND_H

#include "Command.h"


class Number_Command : public Command
{
public:
    Number_Command (int num);
    virtual ~Number_Command (void);
    virtual void execute (Stack<int>& stack) override;
    int getNumber (void);
    void token(void) override;

private:
    int num_;
};
#include "Number_Command.cpp"
#endif