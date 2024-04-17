#include <iostream>

Op_Node::Op_Node(std::unique_ptr<Command_Node> leftNode, std::unique_ptr<Command_Node> rightNode) 
        :left_(std::move(leftNode)), right_(std::move(rightNode)) {}