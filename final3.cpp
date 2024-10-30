#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to check if the right side is valid
bool isValidRightSide(const string& rightSide) {
    // Remove spaces from the right side
    string trimmedRight;
    for (char ch : rightSide) {
        if (!isspace(ch)) {
            trimmedRight += ch;
        }
    }

    // Check if there are no adjacent characters without an operator
    bool lastWasOperator = true; // Start as true to allow the first character
    for (char ch : trimmedRight) {
        if (isalpha(ch)) {
            if (!lastWasOperator) {
                return false; // Two characters are joined without an operator
            }
            lastWasOperator = false; // Next should be an operator
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            lastWasOperator = true; // Last was an operator
        } else {
            return false; // Invalid character
        }
    }

    // If the last character was not an operator, the expression is invalid
    return !lastWasOperator;
}

// Function to count characters excluding spaces
int countCharacters(const string& side) {
    int count = 0;
    for (char ch : side) {
        if (!isspace(ch)) {
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

    // Count characters on both sides excluding spaces
    int leftCount = countCharacters(leftSide);
    int rightCount = countCharacters(rightSide);

    // Validate left side
    bool isValid = true; // To keep track of validity

    if (leftCount > 1) {
        cout << "Invalid expression: More than 1 character on the left side." << endl;
        isValid = false;
    }
    if (!isValidRightSide(rightSide)) {
        cout << "Invalid expression: Right side must contain valid operators between characters." << endl;
        isValid = false;
    }

    // Output character counts and validity status
    if (isValid) {
        cout << "Valid expression!" << endl;
        cout << "Characters on the left side: " << leftCount << endl;
        cout << "Characters on the right side: " << rightCount << endl;
    } else {
        cout << "Invalid expression." << endl;
    }

    return 0;
}
