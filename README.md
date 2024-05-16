# Pattern Pilot Calculator: Crafted in C++, this GitHub repository houses a powerful stack-based calculator enriched with innovative design patterns.

## Overview
This program utilizes the Composite, Visitor, Builder, Command, Abstract Factory, and Facade Patterns to implement an expression evaluator. It offers two versions of the Calculator: one stack-based postfix expression evaluator and another tree-based expression evaluator

## Features
- Supports operators: +, -, /, *, %, (, )
- Handles integers (positive and negative)
- Parses expressions with spaces between tokens
- Accepts input from STDIN
- Outputs results to STDOUT
- Continuously evaluates expressions until the user inputs "QUIT" (case-sensitive)

## Implementation Details
The program is built in C++ and utilizes the MPC library.

## Usage
1. Ensure you have MPC installed on your system.
2. Build the project using the provided `assignment4.mpc` file.
3. Run the executable generated after building.
4. Enter expressions to evaluate. Separate tokens with spaces.
5. To exit the program, type "QUIT" and press Enter.

## Build Instructions
1. Clone this repository to your local machine.
2. Navigate to the project directory.
3. Run the following commands in your terminal:
   ```
   make
   ```
4. To run the program use the following command:
```
./assignment4
```

## Runtime Environment
This program is designed to run on Linux. Ensure you meet the following requirements:
- C++ compiler
- MPC library

