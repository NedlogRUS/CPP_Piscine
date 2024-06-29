#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>

class RPN {
private:
    bool isOperator(char c);
    int performOperation(int a, int b, char op);
public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();
    int evaluate(const std::string &expression);
};

#endif //RPN_HPP
