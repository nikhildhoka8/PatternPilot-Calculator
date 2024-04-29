class Command_Node;
Execute_Visitor::Execute_Visitor()
{
}

Execute_Visitor::~Execute_Visitor()
{
}


void Execute_Visitor::visit_number_node(Number_Node& node)
{   
    stack_.push(node.getNumber());
}

void Execute_Visitor::visit_addition_node(Addition_Node& node){
    auto left = node.getLeft();
    auto right = node.getRight();
    if (left) {
        left->accept(*this);
    } else {
        std::cerr << "Left child is null!\n";
    }

    if (right) {
        right->accept(*this);
    } else {
        std::cerr << "Right child is null!\n";
    }

    int n1 = stack_.top(); stack_.pop();
    int n2 = stack_.top(); stack_.pop();

    stack_.push(n2 + n1);
}

void Execute_Visitor::visit_multiplication_node(Multiplication_Node& node){
    auto left = node.getLeft();
    auto right = node.getRight();
    if (left) {
        left->accept(*this);
    } else {
        std::cerr << "Left child is null!\n";
    }

    if (right) {
        right->accept(*this);
    } else {
        std::cerr << "Right child is null!\n";
    }
    int n1 = stack_.top(); stack_.pop();
    int n2 = stack_.top(); stack_.pop();
    stack_.push(n2 * n1);
}


void Execute_Visitor::visit_subtraction_node(Subtraction_Node& node){
    auto left = node.getLeft();
    auto right = node.getRight();
    if (left) {
        left->accept(*this);
    } else {
        std::cerr << "Left child is null!\n";
    }

    if (right) {
        right->accept(*this);
    } else {
        std::cerr << "Right child is null!\n";
    }
    int n1 = stack_.top(); stack_.pop();
    int n2 = stack_.top(); stack_.pop();
    stack_.push(n2 - n1);
}

void Execute_Visitor::visit_division_node(Division_Node& node){
    auto left = node.getLeft();
    auto right = node.getRight();
    if (left) {
        left->accept(*this);
    } else {
        std::cerr << "Left child is null!\n";
    }

    if (right) {
        right->accept(*this);
    } else {
        std::cerr << "Right child is null!\n";
    }
    int n1 = stack_.top(); stack_.pop();
    int n2 = stack_.top(); stack_.pop();
    if(n1 == 0)
    {
        throw std::runtime_error("Division by zero.");
    }
    stack_.push(n2 / n1);
}


void Execute_Visitor::visit_modulus_node(Modulus_Node& node){
    auto left = node.getLeft();
    auto right = node.getRight();
    if (left) {
        left->accept(*this);
    } else {
        std::cerr << "Left child is null!\n";
    }

    if (right) {
        right->accept(*this);
    } else {
        std::cerr << "Right child is null!\n";
    }
    int n1 = stack_.top(); stack_.pop();
    int n2 = stack_.top(); stack_.pop();
    if(n1 == 0)
    {
        throw std::runtime_error("Modulus by zero.");
    }
    stack_.push(n2 % n1);
}

int Execute_Visitor::getResult()
{
    return stack_.top();
}