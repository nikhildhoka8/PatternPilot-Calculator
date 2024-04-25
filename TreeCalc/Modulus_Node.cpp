

Modulus_Node::Modulus_Node()
    : Op_Node()
{
}

Modulus_Node::~Modulus_Node(void)
{
}

int Modulus_Node::getPrecedence()
{
    return 2;
}

std::string Modulus_Node::token()
{
    return "%";
}

void Modulus_Node::execute(Stack<int>& stack)
{
    int right = stack.top();
    stack.pop();
    if(right == 0){
        throw std::runtime_error("Modulus by zero.");
    }
    int left = stack.top();
    stack.pop();
    stack.push(left % right);
}

void Modulus_Node::accept(Node_Visitor& visitor)
{
    visitor.visit(*this);
}
