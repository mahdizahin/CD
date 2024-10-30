#include <iostream>
#include <string>

using namespace std;

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

    // Count characters on both sides
    int leftCount = leftSide.length();
    int rightCount = rightSide.length();

    // Output the results
    cout << "Characters on the left side: " << leftCount << endl;
    cout << "Characters on the right side: " << rightCount << endl;

    return 0;
}

