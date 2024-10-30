#include <iostream>
#include <string>
#include <cctype>

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

bool isValidExpression(const std::string& expression) {
    size_t equalSignPos = expression.find('=');

    // If there's no '=' or it's the first/last character, it's invalid
    if (equalSignPos == std::string::npos || equalSignPos == 0 || equalSignPos == expression.length() - 1) {
        return false;
    }

    std::string leftSide = expression.substr(0, equalSignPos);
    std::string rightSide = expression.substr(equalSignPos + 1);

    // Check if the left side has any operators
    for (char ch : leftSide) {
        if (isOperator(ch)) {
            return false; // Invalid if the left side contains operators
        }
    }

    // Count operators in the right side
    int operatorCount = 0;
    for (char ch : rightSide) {
        if (isOperator(ch)) {
            operatorCount++;
        }
    }

    // Valid if there are at most 2 operators in the right side
    return operatorCount <= 2;
}

int main() {
    std::string expression;

    std::cout << "Enter an expression: ";
    std::getline(std::cin, expression);

    if (isValidExpression(expression)) {
        std::cout << "The expression is valid." << std::endl;
    } else {
        std::cout << "The expression is invalid." << std::endl;
    }

    return 0;
}
