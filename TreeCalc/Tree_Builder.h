#pragma once
#ifndef TREE_BUILDER_H
#define TREE_BUILDER_H

#include "Addition_Node.h"
#include "Number_Node.h"
#include "Subtraction_Node.h"
#include "Multiplication_Node.h"
#include "Division_Node.h"
#include "Modulus_Node.h"


class Tree_Builder
{
    public:
        Tree_Builder(void);
        ~Tree_Builder(void);

        std::shared_ptr<Number_Node> build_number_command(int num);
        std::shared_ptr<Addition_Node> build_addition_command();
        std::shared_ptr<Subtraction_Node> build_subtraction_command();
        std::shared_ptr<Multiplication_Node> build_multiplication_command();
        std::shared_ptr<Division_Node> build_division_command();
        std::shared_ptr<Modulus_Node> build_modulus_command();
};
#include "Tree_Builder.cpp"
#endif