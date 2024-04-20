

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

void Number_Node::token()
{
    std::cout << "Number: " << this->num_;
}

