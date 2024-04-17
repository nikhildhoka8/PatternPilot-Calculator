#ifndef COMMAND_FACTORY_H
#define COMMAND_FACTORY_H
#include "Addition_Command.h"
#include "Number_Command.h"
#include "Subtraction_Command.h"
#include "Multiplication_Command.h"
#include "Division_Command.h"
#include "Modulus_Command.h"
#include <string>



class Command_Factory
{
public:
    Command_Factory();
    ~Command_Factory();
    Addition_Command* create_addition_command();
    Subtraction_Command* create_subtraction_command();
    Multiplication_Command* create_multiplication_command();
    Division_Command* create_division_command();
    Modulus_Command* create_modulus_command();
    Number_Command* create_number_command(int num);
private:
    Addition_Command* addition_command_;
    Subtraction_Command* subtraction_command_;
    Multiplication_Command* multiplication_command_;
    Division_Command* division_command_;
    Modulus_Command* modulus_command_;

};
#include "Command_Factory.cpp"
#endif
