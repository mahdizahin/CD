
#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Function to perform operations
int performOperation(int operand1, int operand2, char op) {
    switch (op) {
        case '@': return operand1 + operand2;  // Addition
        case '#': return operand1 - operand2;  // Subtraction
        case '&': return operand1 * operand2;  // Multiplication
        case 'S': return operand1 / operand2;  // Division
        default: return 0;
    }
}

// Function to handle precedence
int precedence(char op) {
    if (op == '&' || op == 'S') return 2;  // Multiplication and division have higher precedence
    if (op == '@' || op == '#') return 1;  // Addition and subtraction have lower precedence
    return 0;
}

// Function to evaluate the expression
int evaluateExpression(const string& expr) {
    stack<int> values;  // Stack for operands
    stack<char> operators;  // Stack for operators

    for (int i = 0; i < expr.size(); ++i) {
        if (isdigit(expr[i])) {
            // If the character is a number, push it to the stack
            values.push(expr[i] - '0');
        } else {
            // While the operator at the top of the stack has greater or equal precedence
            // perform the operation
            while (!operators.empty() && precedence(operators.top()) >= precedence(expr[i])) {
                int operand2 = values.top();
                values.pop();
                int operand1 = values.top();
                values.pop();
                char op = operators.top();
                operators.pop();
                values.push(performOperation(operand1, operand2, op));
            }
            // Push the current operator to the stack
            operators.push(expr[i]);
        }
    }

    // Perform remaining operations
    while (!operators.empty()) {
        int operand2 = values.top();
        values.pop();
        int operand1 = values.top();
        values.pop();
        char op = operators.top();
        operators.pop();
        values.push(performOperation(operand1, operand2, op));
    }

    return values.top();  // Final result
}

int main() {
    string expr;
    cout << "Enter the expression: ";
    cin >> expr;

    int result = evaluateExpression(expr);
    cout << "Output: " << result << endl;

    return 0;
}
