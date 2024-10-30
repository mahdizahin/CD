
#include <iostream>
#include <string>
#include <cctype>

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

bool hasValidRightSide(const std::string& rightSide) {
    int operatorCount = 0;
    bool lastWasOperator = true;

    for (char ch : rightSide) {
        if (isOperator(ch)) {
            operatorCount++;
            lastWasOperator = true;
        } else if (std::isalnum(ch)) {

            if (!lastWasOperator) {
                return false;
            }
            lastWasOperator = false;
        } else {
            return false;
        }
    }


    return operatorCount <= 2;
}

bool isValidExpression(const std::string& expression) {
    size_t equalSignPos = expression.find('=');


    if (equalSignPos == std::string::npos || equalSignPos == 0 || equalSignPos == expression.length() - 1) {
        return false;
    }

    std::string leftSide = expression.substr(0, equalSignPos);
    std::string rightSide = expression.substr(equalSignPos + 1);


    for (char ch : leftSide) {
        if (isOperator(ch)) {
            return false;
        }
    }

    return hasValidRightSide(rightSide);
}

bool isValidUnaryExpression(const std::string& expression) {
    if (expression.empty()) {
        return false;
    }


    if (expression.length() >= 2) {
        if ((expression.substr(0, 2) == "++" || expression.substr(0, 2) == "--") &&
            expression.length() == 2) {
            return true;
        }

        if (std::isalnum(expression[0]) && expression.length() == 2) {
            return (expression[1] == '+' || expression[1] == '-');
        }

        if ((expression.substr(0, 2) == "++" || expression.substr(0, 2) == "--") &&
            std::isalnum(expression[2])) {
            return true;
        }
    }


    return std::isalnum(expression[0]) && expression.length() == 1;
}

int main() {
    std::string expression;




    std::cout << "Enter a unary expression: ";
    std::getline(std::cin, expression);

    if (isValidUnaryExpression(expression)) {
        std::cout << "The unary expression is valid." << std::endl;
    } else {
        std::cout << "The unary expression is invalid." << std::endl;
    }

    return 0;
}



