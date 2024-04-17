
Multiplication_Node::Multiplication_Node(std::unique_ptr<Command_Node> leftNode, std::unique_ptr<Command_Node> rightNode)
    :Op_Node(leftNode, rightNode)
{
}

Multiplication_Node::~Multiplication_Node(void)
{
}