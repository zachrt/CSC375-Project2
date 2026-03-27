#include <iostream>

#include "ExpressionTree.h"
#include "Stack.h"
#include "TreeNode.h"

using namespace std;

int main() {
    cout << "GREETINGS....WELCOME TO TREE CALCULATOR" << endl;
    
    ExpressionTree tree;
    string input;
    while (true) {
        cout << "Enter an infix expression to evaluate (0-9, +, -, *, -, (, )), or 'Q' to quit: ";
        while (!(cin >> input)) {
            cout << "Invalid input, try again: ";
            cin.clear();
        }

        if (input == "q" || input == "Q") {
            cout << "CLOSING TREE CALCULATOR....GOODBYE";
            return 0;
        }

        tree.buildTreeFromInfix(input);

        cout << "Prefix: ";
        tree.displayPrefix(tree.getRoot());
        cout << endl;

        cout << "Postfix: ";
        tree.displayPostfix(tree.getRoot());
        cout << endl;
        
        cout << "Result: " << tree.evaluateTree(tree.getRoot());
        cout << endl << endl;
    }
    
    return 0;
}