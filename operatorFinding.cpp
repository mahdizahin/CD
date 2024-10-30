#include <iostream>
#include <string>

using namespace std;

int main() {
    string expression;

    // Prompt the user for input
    cout << "Enter an expression: ";
    getline(cin, expression);

    // Iterate through the expression and look for operators
    cout << "Operators found at positions: ";
    bool found = false;

    for (size_t i = 0; i < expression.length(); ++i) {
        char ch = expression[i];
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            cout << i << " (" << ch << ") ";
            found = true; // Indicate that at least one operator was found
        }
    }

    if (!found) {
        cout << "No operators found." << endl;
    } else {
        cout << endl; // New line for clarity
    }

    return 0;
}

