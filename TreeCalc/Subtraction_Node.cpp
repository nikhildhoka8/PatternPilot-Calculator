
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

void Subtraction_Node::accept(Node_Visitor& visitor)
{
    visitor.visit_subtraction_node(*this);
}