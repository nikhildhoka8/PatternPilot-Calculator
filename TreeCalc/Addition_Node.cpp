
Addition_Node::Addition_Node(std::unique_ptr<Command_Node> leftNode, std::unique_ptr<Command_Node> rightNode)
    :Op_Node(leftNode, rightNode)
{

}

Addition_Node::~Addition_Node(void)
{

}