
#include <iostream>
#include <string>

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
bool Expr();
bool Term();
bool Factor();

// Parsing Expr according to: Expr -> Expr + Term | Term
bool Expr() {
    size_t start = pos;
    if (Term()) {
        while (true) {
            if (match('+')) {
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

// Parsing Term according to: Term -> Term * Factor | Factor
bool Term() {
    size_t start = pos;
    if (Factor()) {
        while (true) {
            if (match('*')) {
                if (!Factor()) return false;
            } else {
                break;
            }
        }
        return true;
    }
    pos = start;
    return false;
}

// Parsing Factor according to: Factor -> (Expr) | a | b
bool Factor() {
    size_t start = pos;
    if (match('a') || match('b')) {
        return true;
    } else if (match('(')) {
        if (Expr() && match(')')) {
            return true;
        }
    }
    pos = start;
    return false;
}

// Check if the CFG is ambiguous by trying to parse the input twice
bool isAmbiguous() {
    pos = 0;
    // First parse
    if (!Expr() || pos != input.length()) {
        return false;  // Invalid expression, so cannot be ambiguous
    }

    // Reset position and try parsing again to detect ambiguity
    pos = 0;
    return Expr() && pos == input.length();
}

int main() {

    cout<<"Write the CFG here : ";
    cin>>input;
    //input = "(a+b)*a";
    if (isAmbiguous()) {
        cout << "The CFG is ambiguous for the given input.\n";
    } else {
        cout << "The CFG is not ambiguous for the given input.\n";
    }
    return 0;
}
