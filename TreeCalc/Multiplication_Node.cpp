
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


void Multiplication_Node::accept(Node_Visitor& visitor)
{
    visitor.visit_multiplication_node(*this);
}