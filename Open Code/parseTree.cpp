#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

string input;
size_t pos = 0;
int level = 0;

// Match a specific character in the input string
bool match(char expected) {
    if (pos < input.length() && input[pos] == expected) {
        pos++;
        return true;
    }
    return false;
}

// Print tree node with indentation to represent parse tree structure
void printNode(const string& label, bool isLast) {
    for (int i = 0; i < level - 1; ++i) {
        cout << "|   ";
    }
    if (level > 0) {
        cout << (isLast ? "`-- " : "|-- ");
    }
    cout << label << endl;
}

// Forward declarations for recursive functions
bool E(bool isLast = true);
bool EPrime(bool isLast = true);
bool T(bool isLast = true);
bool TPrime(bool isLast = true);
bool F(bool isLast = true);

// Grammar rule: E -> T E'
bool E(bool isLast) {
    printNode("E", isLast);
    level++;
    bool result = T(false) && EPrime(true);
    level--;
    return result;
}

// Grammar rule: E' -> + T E' | ε
bool EPrime(bool isLast) {
    printNode("E'", isLast);
    level++;
    if (match('+')) {
        printNode("+", false);
        bool result = T(false) && EPrime(true);
        level--;
        return result;
    }
    // E' -> ε
    printNode("ε", true);
    level--;
    return true;
}

// Grammar rule: T -> F T'
bool T(bool isLast) {
    printNode("T", isLast);
    level++;
    bool result = F(false) && TPrime(true);
    level--;
    return result;
}

// Grammar rule: T' -> * F T' | ε
bool TPrime(bool isLast) {
    printNode("T'", isLast);
    level++;
    if (match('*')) {
        printNode("*", false);
        bool result = F(false) && TPrime(true);
        level--;
        return result;
    }
    // T' -> ε
    printNode("ε", true);
    level--;
    return true;
}

// Grammar rule: F -> (E) | id
bool F(bool isLast) {
    printNode("F", isLast);
    level++;
    if (match('(')) {
        printNode("(", false);
        bool result = E(false) && match(')');
        if (result) printNode(")", true);
        level--;
        return result;
    } else if (match('i') && match('d')) {  // matching "id" as a single token
        printNode("id", true);
        level--;
        return true;
    }
    level--;
    return false;
}

int main() {
    input = "id*(id+id)";
    pos = 0;

    cout << "Parsing input: " << input << endl;
    cout << "Parse Tree:" << endl;

    if (E(true) && pos == input.length()) {
        cout << "\nThe string \"" << input << "\" was successfully derived." << endl;
    } else {
        cout << "\nError: The string \"" << input << "\" could not be derived." << endl;
    }

    return 0;
}
