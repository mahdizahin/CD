#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to check if the left side has exactly two characters with an operator
bool isValidLeftSide(const string& leftSide) {
    // Check if left side has exactly 3 characters (2 operands and 1 operator)
    if (leftSide.length() != 3) {
        return false;
    }

    // Check if the first and last characters are letters and the middle is an operator
    return isalpha(leftSide[0]) && isalpha(leftSide[2]) &&
           (leftSide[1] == '+' || leftSide[1] == '-' ||
            leftSide[1] == '*' || leftSide[1] == '/');
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

    // Count characters on both sides
    int leftCount = leftSide.length();
    int rightCount = rightSide.length();

    // Validate left side
    if (!isValidLeftSide(leftSide)) {
        cout << "Invalid expression: Left side must contain exactly two characters with one operator." << endl;
    } else {
        // Output the character counts if valid
        cout << "Characters on the left side: " << leftCount << endl;
        cout << "Characters on the right side: " << rightCount << endl;
    }

    return 0;
}

