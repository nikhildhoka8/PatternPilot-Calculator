

Number_Node::Number_Node(int num): num_(num)
{
}

Number_Node::~Number_Node()
{
}

int Number_Node::getNumber()
{
    return this->num_;
}

std::string Number_Node::token()
{
    return std::to_string(this->num_);
}

void Number_Node::accept(Node_Visitor& visitor) {
    visitor.visit(*this);
}

