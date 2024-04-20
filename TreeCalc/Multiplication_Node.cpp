
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

void Multiplication_Node::token()
{
    std::cout << "*";
}