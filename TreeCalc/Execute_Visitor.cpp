void Execute_Visitor::visit(Number_Node& node) {
    stack_.push(std::stoi(node.token()));  // Assuming token returns a string that can be converted to int
}

void Execute_Visitor::visit(Addition_Node& node) {
    node.execute(stack_);
}

void Execute_Visitor::visit(Subtraction_Node& node) {
    node.execute(stack_);
}

void Execute_Visitor::visit(Multiplication_Node& node) {
    node.execute(stack_);
}

void Execute_Visitor::visit(Division_Node& node) {
    node.execute(stack_);
}

void Execute_Visitor::visit(Modulus_Node& node) {
    node.execute(stack_);
}

int Execute_Visitor::getResult() {
    if (stack_.is_empty()) {
        throw std::runtime_error("No result available.");
    }
    int result = stack_.top();
    stack_.pop();
    return result;
}