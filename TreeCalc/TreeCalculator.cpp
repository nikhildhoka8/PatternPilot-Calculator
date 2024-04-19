TreeCalculator::TreeCalculator()
{
    this->factory_ = Tree_Command_Factory();
    this->postfix_ = Array<std::unique_ptr<Command_Node>>();
}

TreeCalculator::~TreeCalculator()
{
}

void infixToPostfix(const std::string& infix)
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
            std::unique_ptr<Number_Node> numCmd = factory_.create_number_node(std::stoi(token));
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
                std::unique_ptr<Op_Node> cmd = create_command(operators.top());
                this->postfix_.push_back(cmd);
                operators.pop();

            }
            operators.pop(); //pop the "(" itself and do not add it to postfix
        } else 
        {
            //operator
            while (!operators.is_empty() && operators.top() != "(") 
            {
                std::unique_ptr<Op_Node> tempTokenCommand = create_command(token);
                int tokenPrecedence = tempTokenCommand->getPrecedence();
                std::unique_ptr<Op_Node> tempStackTopCommand = create_command(operators.top());
                int stackTopPrecedence = tempStackTopCommand->getPrecedence();
                if(stackTopPrecedence >= tokenPrecedence)
                {
                    std::unique_ptr<Op_Node> cmd = create_command(operators.top());
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
        std::unique_ptr<Op_Node> cmd = create_command(operators.top());
        this->postfix_.push_back(cmd);
        operators.pop();
    }
}


void run(const std::string &input)
{
    
    
}