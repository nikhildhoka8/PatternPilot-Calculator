#pragma once
#ifndef TREE_CALCULATOR_H
#define TREE_CALCULATOR_H

#include <string>
#include <cctype>
#include <iostream>
#include <memory>
#include "../Templates/Array.h"
#include "../Templates/Stack.h"
#include "Tree_Builder.h"
#include "Command_Node.h"
#include "Op_Node.h"
#include "Execute_Visitor.h"

class TreeCalculator {
public:
    TreeCalculator();
    ~TreeCalculator();
    void run (const std::string& infix);
    std::shared_ptr<Command_Node> buildTree(const std::string& expression);
    int evaluateExpression(const std::shared_ptr<Command_Node>& node);
    std::string preProcessExpression(const std::string& infixParam);
    std::string ensureSpaceAroundParentheses(const std::string& infix);

private:
    std::shared_ptr<Command_Node> root;
    Tree_Builder builder;
    bool isOperator(char c) const;
    bool isOperator(const std::string& c) const;
    std::shared_ptr<Op_Node> build_command(char op);
};
#include "TreeCalculator.cpp"
#endif // TREE_CALCULATOR_H
