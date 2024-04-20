
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

void Subtraction_Node::token()
{
    std::cout << "-";
}
