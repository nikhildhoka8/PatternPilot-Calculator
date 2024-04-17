

Command_Factory::Command_Factory (void)
{
    addition_command_ = new Addition_Command();
    subtraction_command_ = new Subtraction_Command();
    multiplication_command_ = new Multiplication_Command();
    division_command_ = new Division_Command();
    modulus_command_ = new Modulus_Command();
}

Command_Factory::~Command_Factory (void)
{
    if(addition_command_!=nullptr)
    {
        delete addition_command_;
    }
    if(subtraction_command_!=nullptr)
    {
        delete subtraction_command_;
    }
    if(multiplication_command_!=nullptr)
    {
        delete multiplication_command_;
    }
    if(division_command_!=nullptr)
    {
        delete division_command_;
    }
    if(modulus_command_!=nullptr)
    {
        delete modulus_command_;
    }
}

Addition_Command* Command_Factory::create_addition_command (void)
{
    return this->addition_command_;
}

Subtraction_Command* Command_Factory::create_subtraction_command (void)
{
    return this->subtraction_command_;
}

Multiplication_Command* Command_Factory::create_multiplication_command (void)
{
    return this->multiplication_command_;
}

Division_Command* Command_Factory::create_division_command (void)
{
    return this->division_command_;
}

Modulus_Command* Command_Factory::create_modulus_command (void)
{
    return this->modulus_command_;
}

Number_Command* Command_Factory::create_number_command (int num)
{
    return new Number_Command(num);
}