
Multiplication_Node::Multiplication_Node()
    :Op_Node()
{
}

Multiplication_Node::~Multiplication_Node(void)
{
}

int Multiplication_Node::getPrecedence()
{
    return 2;
}

std::string Multiplication_Node::token()
{
    return "*";
}

void Multiplication_Node::execute(Stack<int>& stack)
{
    int right = stack.top();
    stack.pop();
    int left = stack.top();
    stack.pop();
    stack.push(left * right);
}

void Multiplication_Node::accept(Node_Visitor& visitor)
{
    visitor.visit(*this);
}