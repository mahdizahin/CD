#include <iostream>
#include <string>
#include <vector>

using namespace std;

string input;
size_t pos = 0;

bool match(char expected) {
    if (pos < input.length() && input[pos] == expected) {
        pos++;
        return true;
    }
    return false;
}

// Forward declarations
bool S();
bool Term();
bool Factor();

bool S() {
    size_t start = pos;
    // Try matching different production rules
    if (Term()) {
        // After a term, try for operations like +, -, *, /
        while (true) {
            if (match('+') || match('-') || match('*') || match('/')) {
                if (!Term()) return false;
            } else {
                break;
            }
        }
        return true;
    }
    pos = start;
    return false;
}

bool Term() {
    size_t start = pos;
    if (Factor()) return true;
    pos = start;
    return false;
}

bool Factor() {
    size_t start = pos;
    // Match variables X, Y, Z or subexpressions (S)
    if (match('X') || match('Y') || match('Z')) {
        return true;
    } else if (match('(')) {
        if (S() && match(')')) {
            return true;
        }
    }
    pos = start;
    return false;
}

bool isAmbiguous() {
    pos = 0;
    // First parse
    if (!S() || pos != input.length()) {
        return false;  // Invalid expression, so cannot be ambiguous
    }

    // Second parse (reset position and attempt again to detect ambiguity)
    pos = 0;
    return S() && pos == input.length();
}

int main() {

    cout<<"Write the CFG here : ";
    cin>>input;
    //input = "(X+Y)*X-Z*Y/(X+X)";
    if (isAmbiguous()) {
        cout << "The CFG is ambiguous for the given input.\n";
    } else {
        cout << "The CFG is not ambiguous for the given input.\n";
    }
    return 0;
}

