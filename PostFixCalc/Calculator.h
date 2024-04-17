#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "Addition_Command.h"
#include "Subtraction_Command.h"
#include "Multiplication_Command.h"
#include "Division_Command.h"
#include "Modulus_Command.h"
#include "../Templates/Array.h"
#include "../Templates/Stack.h"
#include "../Templates/Array_Iterator.h"
#include "Command_Factory.h"
#include <string>
#include <iostream>
#include <sstream>
#include <typeinfo>

class Calculator
{
    public:
        Calculator();
        ~Calculator();
        void infixToPostfix(const std::string& infix);
        void printCommands();
        int evaluatePostfix();
        void run (const std::string & infix);
        Op_Command * create_command(const std::string& token);
        std::string preProcessExpression(const std::string& infixParam);
        bool isOperator(const std::string& c);
        std::string ensureSpaceAroundParentheses(const std::string& infix);
    private:
        int result_;
        Array<Command*> postfix_;
        Stack<int> stack_;
        Command_Factory factory_;
};
#include "Calculator.cpp"
#endif