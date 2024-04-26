

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
