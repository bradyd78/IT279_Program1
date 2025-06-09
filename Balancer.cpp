// Brady Davidson
// IT 279
//Fixed the balance function for /* and */

#include "Stack.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

// Check if symbols match
bool matching(char open, char close) {
    return (open == '(' && close == ')') || 
           (open == '{' && close == '}') || 
           (open == '/' && close == '*') ||
           (open == '*' && close == '/') ||
           (open == '[' && close == ']');
}

// Check opening symbol
bool isOpening(char c) {
    return (c == '(' || c == '{' || c == '[' || c == '/' || c == '*');
}

// Check closing symbol
bool isClosing(char c) {
    return (c == ')' || c == '}' || c == ']' || c == '*' || c == '/');
}

//Function to read file and check balance
void balance(const string& input) {
    ifstream file(input);
    if (!file) {
        cerr << "Error: Cannot open file " << input << endl;
        return;
    }

    Stack symbolStack;  
    Stack lineStack;

    string line;
    int lineNumber = 0;
    bool inComment = false;

    while (getline(file, line)) {
        lineNumber++;
        for (size_t i = 0; i < line.length(); i++) {
            char c = line[i];
            if (isOpening(c) && !inComment) {
                symbolStack.push(c);
                lineStack.push(lineNumber);
                if (c == '/' && i + 1 < line.length() && line[i + 1] == '*') {
                    inComment = true;
                    i++; // skip the '*' character
                }
            } else if (isClosing(c) && inComment) {
                if (c == '*' && i + 1 < line.length() && line[i + 1] == '/') {
                    symbolStack.pop();
                    lineStack.pop();
                    inComment = false;
                    i++; // skip the '/' character
                }
            } else if (isClosing(c) && !inComment) {
                if (symbolStack.isEmpty()) {
                    cout << '"' << c << "\" on line " << lineNumber << " has no matching opening symbol." << endl;
                    return;
                }

                char topSymbol = symbolStack.top();
                int topLine = lineStack.top();
                symbolStack.pop();
                lineStack.pop();

                if (!matching(topSymbol, c)) {
                    cout << '"' << topSymbol << "\" does not match \"" << c << "\" on line " << lineNumber << '.' << endl;
                    return;
                }
            }
        }
    }

    // Check if stack is empty
    if (!symbolStack.isEmpty()) {
        cout << "End of program reached with unmatched \"" << symbolStack.top() << "\"." << endl;
        return;
    }

    //Print result
    cout << "All symbols correctly balanced." << endl;
}

// Main
int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: <filename>" << endl;
        return 1;
    }
    
    balance(argv[1]);
    return 0;
}
