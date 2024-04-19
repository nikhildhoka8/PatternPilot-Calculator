Division_Node::Division_Node(std::unique_ptr<Command_Node> leftNode, std::unique_ptr<Command_Node> rightNode)
    :Op_Node(leftNode, rightNode)
{
}

Division_Node::~Division_Node()
{
}

std::unique_ptr<Number_Node> Division_Node::execute()
{   
    if(right_->execute()->get_value() == 0)
    {
        throw std::runtime_error("Division by zero.");
    }
    return std::make_unique<Number_Node>(left_->execute()->get_value() / right_->execute()->get_value());
}