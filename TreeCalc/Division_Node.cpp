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


void Division_Node::accept(Node_Visitor& visitor)
{
    visitor.visit_division_node(*this);
}