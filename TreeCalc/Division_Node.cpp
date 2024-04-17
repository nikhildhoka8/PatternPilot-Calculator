Division_Node::Division_Node(std::unique_ptr<Command_Node> leftNode, std::unique_ptr<Command_Node> rightNode)
    :Op_Node(leftNode, rightNode)
{
}

Division_Node::~Division_Node()
{
}