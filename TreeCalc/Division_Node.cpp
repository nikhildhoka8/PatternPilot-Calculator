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
