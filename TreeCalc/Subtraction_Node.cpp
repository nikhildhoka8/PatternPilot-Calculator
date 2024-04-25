
Subtraction_Node::Subtraction_Node (void) 
    :Op_Node()
{
}

Subtraction_Node::~Subtraction_Node(void)
{
}

int Subtraction_Node::getPrecedence()
{
    return 1;
}

std::string Subtraction_Node::token()
{
    return "-";
}

void Subtraction_Node::execute(Stack<int>& stack)
{
    int right = stack.top; stack.pop();
    int left = stack.top(); stack.pop();
    stack.push(left - right);
}

void accept(Node_Visitor& visitor) override {
        visitor.visit(*this);
}
