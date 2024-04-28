#pragma once
#ifndef TREE_COMMAND_FACTORY_H
#define TREE_COMMAND_FACTORY_H

#include "Addition_Node.h"
#include "Number_Node.h"
#include "Subtraction_Node.h"
#include "Multiplication_Node.h"
#include "Division_Node.h"
#include "Modulus_Node.h"


class Tree_Command_Factory
{
    public:
        Tree_Command_Factory(void);
        ~Tree_Command_Factory(void);

        std::shared_ptr<Number_Node> create_number_command(int num);
        std::shared_ptr<Addition_Node> create_addition_command();
        std::shared_ptr<Subtraction_Node> create_subtraction_command();
        std::shared_ptr<Multiplication_Node> create_multiplication_command();
        std::shared_ptr<Division_Node> create_division_command();
        std::shared_ptr<Modulus_Node> create_modulus_command();
};
#include "Tree_Command_Factory.cpp"
#endif