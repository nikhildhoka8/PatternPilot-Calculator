#include <iostream>
#include <string>
#include "PostFixCalc/Calculator.h"



int main() {

    //run a while loop for user input, until they type QUIT
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
            Calculator calc;
            calc.run(input);
        } catch (std::exception& e) 
        {
            std::cout << e.what() << std::endl;
        }
    }


    return 0;
}