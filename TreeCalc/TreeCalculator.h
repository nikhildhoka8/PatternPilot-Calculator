#pragma once
#ifndef TREE_CALCULATOR_H
#define TREE_CALCULATOR_H

#include <string>
#include <cctype>
#include <iostream>
#include <memory>
#include "../Templates/Stack.h"
#include "Tree_Command_Factory.h"
#include "Command_Node.h"
#include "Op_Node.h"

class TreeCalculator {
public:
    TreeCalculator();
    ~TreeCalculator();
    void run (const std::string& infix);
    std::shared_ptr<Op_Node> buildTree(const std::string& expression);
    int evaluateExpression(const std::shared_ptr<Command_Node>& node);

private:
    std::shared_ptr<Command_Node> root;
    Tree_Command_Factory factory;
    bool isOperator(char c) const;
    std::shared_ptr<Op_Node> create_command(char op);
};
#include "TreeCalculator.cpp"
#endif // TREE_CALCULATOR_H
