#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>

class RPN {
private:
    bool isOperator(char c);
    double performOperation(double a, double b, char op);
public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();
    double evaluate(const std::string &expression);
};

#endif //RPN_HPP
