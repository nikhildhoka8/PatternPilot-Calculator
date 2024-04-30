
Tree_Builder::Tree_Builder (void)
{
}


Tree_Builder::~Tree_Builder (void)
{
}

std::shared_ptr<Addition_Node> Tree_Builder::build_addition_command() {
    return std::shared_ptr<Addition_Node>(new Addition_Node());
}

std::shared_ptr<Subtraction_Node> Tree_Builder::build_subtraction_command() {
    return std::shared_ptr<Subtraction_Node>(new Subtraction_Node());
}

std::shared_ptr<Multiplication_Node> Tree_Builder::build_multiplication_command() {
    return std::shared_ptr<Multiplication_Node>(new Multiplication_Node());
}

std::shared_ptr<Division_Node> Tree_Builder::build_division_command() {
    return std::shared_ptr<Division_Node>(new Division_Node());
}

std::shared_ptr<Modulus_Node> Tree_Builder::build_modulus_command() {
    return std::shared_ptr<Modulus_Node>(new Modulus_Node());
}

std::shared_ptr<Number_Node> Tree_Builder::build_number_command(int num)
{
    return std::shared_ptr<Number_Node>(new Number_Node(num));
}


