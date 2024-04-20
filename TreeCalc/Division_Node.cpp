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

void Division_Node::token()
{
    std::cout << "/";
}
