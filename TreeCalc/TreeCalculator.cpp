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
    operandStack.push(op); // Push back as Op_Node, not as Number_Node
}



std::shared_ptr<Op_Node> TreeCalculator::buildTree(const std::string& expression) {
    Stack<std::shared_ptr<Command_Node>> operandStack; // Store all nodes here
    Stack<std::shared_ptr<Op_Node>> operatorStack;

    std::istringstream iss(expression);
    char ch;
    while (iss >> std::skipws >> ch) {
        if (isdigit(ch)) {
            iss.putback(ch);
            int value;
            iss >> value;
            operandStack.push(std::dynamic_pointer_cast<Command_Node>(factory.create_number_command(value)));
        } else if (isOperator(ch)) {
            auto opNode = create_command(ch);
            while (!operatorStack.is_empty() && operatorStack.top() != nullptr && operatorStack.top()->getPrecedence() >= opNode->getPrecedence() ) {
                processOperator(operatorStack, operandStack);
            }
            operatorStack.push(opNode);
        } else if (ch == '(') {
            operatorStack.push(nullptr);  // Push nullptr as a marker for '('
        } else if (ch == ')') {
            while (operatorStack.top() != nullptr) {
                processOperator(operatorStack, operandStack);
            }
            operatorStack.pop();  // Pop the '(' marker
        }
    }

    // Process remaining operators in the stack
    while (!operatorStack.is_empty()) {
        processOperator(operatorStack, operandStack);
    }

    // The root of the expression tree should be the last operator processed
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
        // It's an operator node, evaluate left and right children first
        int leftValue = evaluateExpression(opNode->getLeft());
        int rightValue = evaluateExpression(opNode->getRight());

        std::string token = opNode->token(); // Ensure you get the token as a string
        // Perform the operation based on the operator type
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
        // It must be a Number_Node or similar, so return its integer value
        return std::stoi(node->token());  // Assuming the token can be directly converted to an integer
    }
}




void TreeCalculator::run(const std::string &infix) {
    root = buildTree(infix);
    //check type of root with Op_Node
    if(!std::dynamic_pointer_cast<Op_Node>(root)){
        throw std::runtime_error("Root node is not an operation node");
    }
    //convert root to OP_NODE
    std::shared_ptr<Op_Node> opRoot = std::dynamic_pointer_cast<Op_Node>(root);
    
    if(root){
        std::cout << evaluateExpression(opRoot) << std::endl;
    }
}

