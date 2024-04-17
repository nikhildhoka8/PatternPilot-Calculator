

Modulus_Node::Modulus_Node(std::unique_ptr<Command_Node> leftNode, std::unique_ptr<Command_Node> rightNode)
    : Op_Node(std::move(leftNode), std::move(rightNode))
{
}

Modulus_Node::~Modulus_Node(void)
{
}