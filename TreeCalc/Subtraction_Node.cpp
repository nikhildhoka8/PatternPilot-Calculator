
Subtraction_Node::Subtraction_Node (std::unique_ptr<Command_Node> leftNode, std::unique_ptr<Command_Node> rightNode) 
    :Op_Node(leftNode, rightNode)
{
}

Subtraction_Node::~Subtraction_Node(void)
{
}