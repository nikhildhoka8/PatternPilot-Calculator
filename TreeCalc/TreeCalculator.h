#ifndef TREE_CALCULATOR_H
#define TREE_CALCULATOR_H

#include "Tree_Command_Factory.h"
#include "Templates/Array.h"

class TreeCalculator
{
public:
    TreeCalculator (void);
    ~TreeCalculator (void);
    void infixToPostfix(const std::string& infix);
    void run(const std::string &input);

private:
    int result;
    Array <std::unique_ptr<Command_Node>> postfix_;
    Tree_Command_Factory factory_;
};
#include "TreeCalculator.cpp"
#endif