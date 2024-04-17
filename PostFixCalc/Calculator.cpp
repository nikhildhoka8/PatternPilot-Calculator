Calculator::Calculator()
{
}


Calculator::~Calculator()
{
    //delete the Command 
    Array_Iterator<Command*> iter(this->postfix_);
    for (; !iter.is_done(); iter.advance()) {
        // only delete number commands
        Command* cmd = *iter;
        if (typeid(*cmd) == typeid(Number_Command)) {
            delete cmd;
        }
    }
}



void printStack(Stack<std::string> stack) {
    std::cout << "Current Stack (top to bottom): ";
    while (!stack.is_empty()) {
        std::cout << "'" << stack.top() << "' ";
        stack.pop();
    }
}



void Calculator::printCommands()
{
    //print the postfix
    std::cout << "Postfix Size: " << this->postfix_.size() << std::endl;
    for (int i = 0; i < this->postfix_.size(); ++i) 
    {
        this->postfix_[i]->token();
    }
    std::cout << std::endl;
}

void Calculator::infixToPostfix(const std::string& infix)
{
    std::string infixProcessed = preProcessExpression(infix);
    std::istringstream iss(infixProcessed);
    Stack<std::string> operators;
    std::string token;
    int count = 0;
    while (iss >> token) 
    {           
        if (!isOperator(token) && token != "(" && token != ")") 
        {
            //create number command and push to array
            //check if the token is a number. if not throw an exception
            try 
            {
                std::stoi(token);
            } catch (std::invalid_argument& e) 
            {
                throw std::invalid_argument("Invalid token: " + token);
            }
            Number_Command *numCmd = factory_.create_number_command(std::stoi(token));
            this->postfix_.push_back(numCmd);
        } else if (token == "(") 
        {
            //push to stack
            operators.push(token);
        } else if (token == ")") 
        {
            //pop from stacks
            while (!operators.is_empty() && operators.top() != "(") 
            {
                Op_Command* cmd = create_command(operators.top());
                this->postfix_.push_back(cmd);
                operators.pop();

            }
            operators.pop(); //pop the "(" itself and do not add it to postfix
        } else 
        {
            //operator
            while (!operators.is_empty() && operators.top() != "(") 
            {
                Op_Command* tempTokenCommand = create_command(token);
                int tokenPrecedence = tempTokenCommand->getPrecedence();
                Op_Command* tempStackTopCommand = create_command(operators.top());
                int stackTopPrecedence = tempStackTopCommand->getPrecedence();
                delete tempTokenCommand;
                delete tempStackTopCommand;
                if(stackTopPrecedence >= tokenPrecedence)
                {
                    Op_Command* cmd = create_command(operators.top());
                    this->postfix_.push_back(cmd);
                    operators.pop();
                }
                else
                {
                    break;
                }
            }
            operators.push(token);
        }
    }
    //pop any remaining operators from the stack to the output
    while (!operators.is_empty()) 
    {
        Op_Command* cmd = create_command(operators.top());
        this->postfix_.push_back(cmd);
        operators.pop();
    }
}


int Calculator::evaluatePostfix()
{
    Array_Iterator<Command*> iter(this->postfix_);
    for (; !iter.is_done(); iter.advance()) 
    {
        Command* cmd = *iter;
        cmd->execute(stack_);
    }
    this->result_ = stack_.top();
    stack_.pop();
    return this->result_;
}


void Calculator::run (const std::string & infix)
{
    infixToPostfix(infix);
    int result = evaluatePostfix();
    std::cout << "Result: " << result << std::endl;
}

Op_Command * Calculator::create_command(const std::string& token)
{
    if (token == "+") 
    {
        return factory_.create_addition_command();
    } else if (token == "-") 
    {
        return factory_.create_subtraction_command();
    } else if (token == "*") 
    {
        return factory_.create_multiplication_command();
    } else if (token == "/") 
    {
        return factory_.create_division_command();
    } else if (token == "%") 
    {
        return factory_.create_modulus_command();
    } else {
        throw std::invalid_argument("Invalid token: " + token);
    }
}


bool Calculator::isOperator(const std::string& c) 
{
    return c == "+" || c == "-" || c == "*" || c == "/" || c == "%";
}


std::string Calculator::ensureSpaceAroundParentheses(const std::string& infix)
{
    std::string processed;

    for (size_t i = 0; i < infix.size(); ++i) 
    {
        char c = infix[i];
        if (c == '(' || c == ')') 
        {
            //ensure there is a space before the parenthesis if it's not the first character and not already preceded by a space
            if (i > 1 && infix[i-1] != ' ') 
            {
                processed += ' ';
            }
            processed += c;
            //ensure there is a space after the parenthesis if it's not the last character and not already followed by a space
            if (i < infix.size() - 1 && infix[i+1] != ' ') 
            {
                processed += ' ';
            }
        } else {
            processed += c;
        }
    }
    return processed;
}

std::string Calculator::preProcessExpression(const std::string& infixParam) 
{

    std::string infix = ensureSpaceAroundParentheses(infixParam);

    //check if the first and last character are operators
    if (isOperator(std::string(1, infix[0]))) {
        // Allow '-' at the beginning if it's followed by a digit (indicating a negative number)
        if (!(infix[0] == '-' && infix.size() > 1 && std::isdigit(infix[1]))) {
            throw std::invalid_argument("Invalid Expression: First character cannot be an operator");
        }
    }
    // Adjust the check for the last character
    if (isOperator(std::string(1, infix[infix.size()-1]))) {
        throw std::invalid_argument("Invalid Expression: Last character cannot be an operator");
    }

    //check if the string has paranthesis in the right order
    int open = 0;
    int close = 0;
    for (int i = 0; i < infix.length(); i++) 
    {
        if (infix[i] == '(') 
        {
            open++;
        } else if (infix[i] == ')') 
        {
            close++;
        }
    }
    if (open != close) 
    {
        throw std::invalid_argument("Invalid Order or Number of Paranthesis");
    }

    //check if two operators are placed next to each other in the string
    std::istringstream iss(infix);
    std::string token;
    std::string lastToken;
    bool lastWasOperator = false;
    while (iss >> token) 
    {
        if (isOperator(token)) 
        {
            if (lastWasOperator) 
            {
                //two operators in a row, throw an exception
                throw std::invalid_argument("Invalid Expression: Consecutive operators not allowed");
            }
            lastWasOperator = true;
        } else 
        {
            //if it's not an operator, reset the flag
            lastWasOperator = false;
        }
        //keep track of the last token
        lastToken = token; 
    }
    return infix;

}