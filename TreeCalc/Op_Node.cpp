

Op_Node::Op_Node() 
        :left_(nullptr), right_(nullptr) 
        {}


Op_Node::~Op_Node() 
        {}
        
void Op_Node::setLeft(std::unique_ptr<Command_Node> left)
{
    this->left_ = std::move(left);
}


void Op_Node::setRight(std::unique_ptr<Command_Node> right)
{
    this->right_ = std::move(right);
}

std::unique_ptr<Command_Node> Op_Node::getLeft()
{
    return std::move(this->left_);
}


std::unique_ptr<Command_Node> Op_Node::getRight()
{
    return std::move(this->right_);
}
