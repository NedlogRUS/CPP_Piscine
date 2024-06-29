#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) {
    *this = other;
}

RPN &RPN::operator=(const RPN &other) {
    (void)other;
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::performOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: throw std::invalid_argument("Invalid operator");
    }
}

int RPN::evaluate(const std::string &expression) {
    std::stack<int> stack;
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (token.size() == 1 && isOperator(token[0])) {
            if (stack.size() < 2) throw std::runtime_error("Error");
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            int result = performOperation(a, b, token[0]);
            stack.push(result);
        } else {
            int number;
            std::stringstream ss(token);
            if (!(ss >> number)) {
                throw std::runtime_error("Invalid input");
            }
            stack.push(number);
        }
    }

    if (stack.size() != 1) throw std::runtime_error("Error");
    return stack.top();
}
