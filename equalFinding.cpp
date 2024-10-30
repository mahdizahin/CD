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

    // Check if the '=' symbol is found
    if (equalPos != string::npos) {
        cout << "The '=' symbol is found at position: " << equalPos << endl;
    } else {
        cout << "The '=' symbol is not found in the expression." << endl;
    }

    return 0;
}

