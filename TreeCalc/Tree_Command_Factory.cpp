
Tree_Command_Factory::Tree_Command_Factory (void)
{
}


Tree_Command_Factory::~Tree_Command_Factory (void)
{
}

std::shared_ptr<Addition_Node> Tree_Command_Factory::create_addition_command() {
    return std::shared_ptr<Addition_Node>(new Addition_Node());
}

std::shared_ptr<Subtraction_Node> Tree_Command_Factory::create_subtraction_command() {
    return std::shared_ptr<Subtraction_Node>(new Subtraction_Node());
}

std::shared_ptr<Multiplication_Node> Tree_Command_Factory::create_multiplication_command() {
    return std::shared_ptr<Multiplication_Node>(new Multiplication_Node());
}

std::shared_ptr<Division_Node> Tree_Command_Factory::create_division_command() {
    return std::shared_ptr<Division_Node>(new Division_Node());
}

std::shared_ptr<Modulus_Node> Tree_Command_Factory::create_modulus_command() {
    return std::shared_ptr<Modulus_Node>(new Modulus_Node());
}

std::shared_ptr<Number_Node> Tree_Command_Factory::create_number_command(int num)
{
    return std::shared_ptr<Number_Node>(new Number_Node(num));
}


