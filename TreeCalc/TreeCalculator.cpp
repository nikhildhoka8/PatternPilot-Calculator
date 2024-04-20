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

std::unique_ptr<Op_Node> TreeCalculator::create_command(char op) {
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

std::unique_ptr<Command_Node> TreeCalculator::buildTree(const std::string& expression) {
    Stack<std::unique_ptr<Command_Node>> operandStack;
    Stack<std::unique_ptr<Op_Node>> operatorStack;

    std::istringstream iss(expression);
    char ch;
    while (iss >> std::skipws >> ch) {
        if (isdigit(ch)) {
            iss.putback(ch);
            int value;
            iss >> value;
            operandStack.push(factory.create_number_command(value));
        } else if (isOperator(ch)) {
            auto opNode = create_command(ch);
            while (!operatorStack.is_empty() && operatorStack.top()->getPrecedence() >= opNode->getPrecedence() && operatorStack.top()->getToken() != '(') {
                auto topOp = std::move(operatorStack.top());
                operatorStack.pop();
                topOp->setRight(std::move(operandStack.top()));
                operandStack.pop();
                topOp->setLeft(std::move(operandStack.top()));
                operandStack.pop();
                operandStack.push(std::move(topOp));
            }
            operatorStack.push(std::move(opNode));
        } else if (ch == '(') {
        } else if (ch == ')') {
            while (!operatorStack.is_empty() && operatorStack.top()->token() != '(') {
                auto topOp = std::move(operatorStack.top());
                operatorStack.pop();
                topOp->setRight(std::move(operandStack.top()));
                operandStack.pop();
                topOp->setLeft(std::move(operandStack.top()));
                operandStack.pop();
                operandStack.push(std::move(topOp));
            }
        }
    }

    while (!operatorStack.is_empty()) {
        auto topOp = std::move(operatorStack.top());
        operatorStack.pop();
        topOp->setRight(std::move(operandStack.top()));
        operandStack.pop();
        if (!operandStack.is_empty()) {
            topOp->setLeft(std::move(operandStack.top()));
            operandStack.pop();
        }
        operandStack.push(std::move(topOp));
    }

    return std::move(operandStack.top());
}

void run(const std::string & infix) {
    root = buildTree(infix);
    //print the root
    root->token();
    std::cout << std::endl;
}