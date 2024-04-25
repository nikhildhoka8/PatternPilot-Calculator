#include <iostream>
#include <string>
#include "PostFixCalc/Calculator.h"
#include "TreeCalc/TreeCalculator.h"
#include "TreeCalc/Tree_Command_Factory.h"
#include "TreeCalc/Addition_Node.h"



int main() {
    //un a while loop for user input, until they type QUIT
    std::string input;
    while (true) 
    {
        std::cout << "Enter expression: ";
        std::getline(std::cin, input);
        //print the input
        std::cout << "Input: " << input << std::endl;
        if (input == "QUIT") 
        {
            break;
        }
        try 
        {
            
            TreeCalculator calc;
            calc.run(input);
        } catch (std::exception& e) 
        {
            std::cout << e.what() << std::endl;
        }
    }

    return 0;
}

