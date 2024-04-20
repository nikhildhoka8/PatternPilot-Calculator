
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

void Addition_Node::token()
{
    std::cout << " + ";
}
