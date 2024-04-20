#ifndef NUMBER_NODE_H
#define NUMBER_NODE_H

#include <memory>
#include "Command_Node.h"

class Number_Node: public Command_Node{
public:
    Number_Node(int num);
    ~Number_Node();
    int getNumber();
    void token();
private:
    int num_;

};
#include "Number_Node.cpp"
#endif // !NUMBER_NODE_H