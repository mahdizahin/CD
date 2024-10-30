#include <iostream>
#include <string>

using namespace std;

// Function to count operators in a given side of the expression
int countOperators(const string& side) {
    int count = 0;
    for (char ch : side) {
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            count++;
        }
    }
    return count;
}

int main() {
    string expression;

    // Prompt the user for input
    cout << "Enter an expression: ";
    getline(cin, expression);

    // Find the position of the '=' symbol
    size_t equalPos = expression.find('=');
    if (equalPos == string::npos) {
        cout << "The expression does not contain an '=' symbol." << endl;
        return 1; // Exit if '=' is not found
    }

    // Extract left and right sides of the expression
    string leftSide = expression.substr(0, equalPos);
    string rightSide = expression.substr(equalPos + 1);

    // Count operators on both sides
    int leftCount = countOperators(leftSide);
    int rightCount = countOperators(rightSide);

    // Output the results
    cout << "Operators on the left side: " << leftCount << endl;
    cout << "Operators on the right side: " << rightCount << endl;

    return 0;
}

