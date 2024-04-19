
Addition_Node::Addition_Node(std::unique_ptr<Command_Node> leftNode, std::unique_ptr<Command_Node> rightNode)
    :Op_Node(leftNode, rightNode)
{

}

Addition_Node::~Addition_Node(void)
{

}

std::unique_ptr<Number_Node> Addition_Node::execute()
{
    //if either are operators, then go recursively, otherwise evaluate the numbers
    if(typeid(*left_) == typeid(Op_Node) || typeid(*right_) == typeid(Op_Node))
    {
       
    }
    else
    {
        return std::make_unique<Number_Node>(left_->getNumber() + right_->getNumber());
    }
}