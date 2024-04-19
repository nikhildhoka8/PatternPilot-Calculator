
Tree_Command_Factory::Tree_Command_Factory (void)
{
}


Tree_Command_Factory::~Tree_Command_Factory (void)
{
}

std::unique_ptr<Addition_Node> Tree_Command_Factory::create_addition_command(std::unique_ptr<Command_Node> leftNode, std::unique_ptr<Command_Node> rightNode)
{
    return std::make_unique<Addition_Node>(std::move(leftNode), std::move(rightNode));
}

std::unique_ptr<Subtraction_Node> Tree_Command_Factory::create_subtraction_command(std::unique_ptr<Command_Node> leftNode, std::unique_ptr<Command_Node> rightNode)
{
    return std::make_unique<Subtraction_Node>(std::move(leftNode), std::move(rightNode));
}

std::unique_ptr<Multiplication_Node> Tree_Command_Factory::create_multiplication_command(std::unique_ptr<Command_Node> leftNode, std::unique_ptr<Command_Node> rightNode)
{
    return std::make_unique<Multiplication_Node>(std::move(leftNode), std::move(rightNode));
}

std::unique_ptr<Division_Node> Tree_Command_Factory::create_division_command(std::unique_ptr<Command_Node> leftNode, std::unique_ptr<Command_Node> rightNode)
{
    return std::make_unique<Division_Node>(std::move(leftNode), std::move(rightNode));
}

std::unique_ptr<Modulus_Node> Tree_Command_Factory::create_modulus_command(std::unique_ptr<Command_Node> leftNode, std::unique_ptr<Command_Node> rightNode)
{
    return std::make_unique<Modulus_Node>(std::move(leftNode), std::move(rightNode));
}

std::unique_ptr<Number_Node> Tree_Command_Factory::create_number_command(int num)
{
    return std::make_unique<Number_Node>(num);
}

