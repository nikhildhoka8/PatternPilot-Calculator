
Addition_Node::Addition_Node()
    :Op_Node()
{

}

Addition_Node::~Addition_Node(void)
{

}

int Addition_Node::getPrecedence()
{
    return 1;
}

std::string Addition_Node::token()
{
    return "+";
}


void Addition_Node::accept(Node_Visitor& visitor)
{
    visitor.visit_addition_node(*this);
}
