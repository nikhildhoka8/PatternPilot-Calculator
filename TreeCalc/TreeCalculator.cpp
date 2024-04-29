TreeCalculator::TreeCalculator() 
{
    factory = Tree_Command_Factory();
    root = nullptr;
}

TreeCalculator::~TreeCalculator() 
{
}

bool TreeCalculator::isOperator(char c) const {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

std::shared_ptr<Op_Node> TreeCalculator::create_command(char op) {
    switch (op) {
        case '+': return factory.create_addition_command();
        case '-': return factory.create_subtraction_command();
        case '*': return factory.create_multiplication_command();
        case '/': return factory.create_division_command();
        case '%': return factory.create_modulus_command();
        default:
            throw std::runtime_error("Unsupported operator");
    }
}

void processOperator(Stack<std::shared_ptr<Op_Node>>& operatorStack, Stack<std::shared_ptr<Command_Node>>& operandStack) {
    auto op = operatorStack.top();
    operatorStack.pop();
    if (!operandStack.is_empty()) {
        op->setRight(operandStack.top());
        operandStack.pop();
    }
    if (!operandStack.is_empty()) {
        op->setLeft(operandStack.top());
        operandStack.pop();
    }
    operandStack.push(op); //push back as Op_Node
}



std::shared_ptr<Command_Node> TreeCalculator::buildTree(const std::string& expression) {
    Stack<std::shared_ptr<Command_Node>> operandStack;
    Stack<std::shared_ptr<Op_Node>> operatorStack;
    std:: string infixProcessed = preProcessExpression(expression);
    //check if it is only one number. If it is, return a number node
    if(infixProcessed.find(' ') == std::string::npos){
        return std::dynamic_pointer_cast<Command_Node>(factory.create_number_command(std::stoi(infixProcessed)));
    }
    std::istringstream iss(infixProcessed);
    char ch;
    while (iss >> std::skipws >> ch) {
        if (isdigit(ch)) {
            iss.putback(ch);
            int value;
            iss >> value;
            operandStack.push(std::dynamic_pointer_cast<Command_Node>(factory.create_number_command(value)));
        } else if (ch == '-') {
            //check if the next character is a digit
            if (iss.peek() && isdigit(iss.peek())) {
                int value;
                iss >> value;
                operandStack.push(std::dynamic_pointer_cast<Command_Node>(factory.create_number_command(-value)));
            } else {
                //treat as a separate operator
                auto opNode = create_command(ch);
                while (!operatorStack.is_empty() && operatorStack.top() != nullptr && operatorStack.top()->getPrecedence() >= opNode->getPrecedence() ) {
                    processOperator(operatorStack, operandStack);
                }
                operatorStack.push(opNode);
            }
        } else if (isOperator(ch)) {
            auto opNode = create_command(ch);
            while (!operatorStack.is_empty() && operatorStack.top() != nullptr && operatorStack.top()->getPrecedence() >= opNode->getPrecedence() ) {
                processOperator(operatorStack, operandStack);
            }
            operatorStack.push(opNode);
        } else if (ch == '(') {
            operatorStack.push(nullptr);  //push nullptr as a marker for '('
        } else if (ch == ')') {
            while (operatorStack.top() != nullptr) {
                processOperator(operatorStack, operandStack);
            }
            operatorStack.pop();  //pop the '(' marker
        }
    }

    //process remaining operators in the stack
    while (!operatorStack.is_empty()) {
        processOperator(operatorStack, operandStack);
    }

    if (!operandStack.is_empty()) {
        auto result = std::dynamic_pointer_cast<Op_Node>(operandStack.top());
        if (result) {
            return result;
        }
    }
    throw std::runtime_error("Final node is not an operation node");
}

int TreeCalculator::evaluateExpression(const std::shared_ptr<Command_Node>& node) {
    if (!node) {
        throw std::runtime_error("Null node encountered in expression tree.");
    }

    // Dynamic cast to check if it is an Op_Node
    std::shared_ptr<Op_Node> opNode = std::dynamic_pointer_cast<Op_Node>(node);
    if (opNode) {
        int leftValue = evaluateExpression(opNode->getLeft());
        int rightValue = evaluateExpression(opNode->getRight());

        std::string token = opNode->token();
        if (token == "+") {
            return leftValue + rightValue;
        } else if (token == "-") {
            return leftValue - rightValue;
        } else if (token == "*") {
            return leftValue * rightValue;
        } else if (token == "/") {
            if (rightValue == 0) {
                throw std::runtime_error("Division by zero.");
            }
            return leftValue / rightValue;
        } else if (token == "%") {
            if (rightValue == 0) {
                throw std::runtime_error("Modulo by zero.");
            }
            return leftValue % rightValue;
        } else {
            throw std::runtime_error("Unsupported operation: " + token);
        }
    } else {
        return std::stoi(node->token());
    }
}

std::string TreeCalculator::ensureSpaceAroundParentheses(const std::string& infix)
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

std::string TreeCalculator::preProcessExpression(const std::string& infixParam) 
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

bool TreeCalculator::isOperator(const std::string& c) const {
    return c == "+" || c == "-" || c == "*" || c == "/" || c == "%";
}



void TreeCalculator::run(const std::string &infix) {
    root = buildTree(infix);
    if(root){
        Execute_Visitor ev;
        //call the accept method on the root node, passing the visitor object
        root->accept(ev);

        //get the result from the visitor
        int result = ev.getResult();

        //print the result
        std::cout << "Result: " << result << std::endl;
    }

}

