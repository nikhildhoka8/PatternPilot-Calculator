Division_Node::Division_Node(void)
    :Op_Node()
{
}

Division_Node::~Division_Node()
{
}



int Division_Node::getPrecedence()
{
    return 2;
}

std::string Division_Node::token()
{
    return "/";
}

void execute(Stack<int>& stack){
    int right = stack.top();
    stack.pop();
    if(right == 0){
        throw std::runtime_error("Division by zero.");
    }
    int left = stack.top();
    stack.pop();
    stack.push(left / right);
}

void accept(Node_Visitor& visitor) override {
        visitor.visit(*this);
    }
