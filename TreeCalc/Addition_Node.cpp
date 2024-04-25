
Addition_Node::Addition_Node()
    :Op_Node()
{

}

Addition_Node::~Addition_Node(void)
{

}

int Addition_Node::getPrecedence()
{
    return 1;
}

std::string Addition_Node::token()
{
    return "+";
}

void Addition_Node::execute(Stack<int>& stack)
{
    int right = stack.top();
    stack.pop();
    int left = stack.top();
    stack.pop();
    stack.push(left + right);
}

void accept(Node_Visitor& visitor) override {
        visitor.visit(*this);
}
