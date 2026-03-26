#include <iostream>
#include "ExpressionTree.h"
#include "Stack.h"

using namespace std;

// Private
int ExpressionTree::getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
};

bool ExpressionTree::isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
};

void ExpressionTree::attachOperator(Stack<TreeNode*>& nodeStack, Stack<char>& opStack) {
        TreeNode* opNode = new TreeNode(string(1, opStack.pop()));
        
        opNode->right = nodeStack.pop();
        opNode->left = nodeStack.pop();
        
        nodeStack.push(opNode);
    }

// Public
ExpressionTree::ExpressionTree() {
    root = nullptr;
};

void ExpressionTree::buildTreeFromInfix(string expression) {
    Stack<TreeNode*> nodeStack(100);
    Stack<char> opStack(100);

    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];

        if (c == ' ') continue;

        if (isdigit(c)) {
            string numStr = "";
            while (i < expression.length() && isdigit(expression[i])) {
                numStr += expression[i];
                i++;
            }
            i--;
            
            TreeNode* numNode = new TreeNode(numStr);
            nodeStack.push(numNode);
        }
        
        else if (c == '(') {
            opStack.push(c);
        }
        
        else if (c == ')') {
            while (!opStack.isEmpty() && opStack.peek() != '(') {
                attachOperator(nodeStack, opStack);
            }
            if (!opStack.isEmpty()) {
                opStack.pop();
            }
        }
       
        else if (isOperator(c)) {
            
            while (!opStack.isEmpty() && getPrecedence(opStack.peek()) >= getPrecedence(c)) {
                attachOperator(nodeStack, opStack);
            }
            opStack.push(c);
        }
    }

    while (!opStack.isEmpty()) {
        attachOperator(nodeStack, opStack);
    }

    if (!nodeStack.isEmpty()) {
        root = nodeStack.pop();
    }
}

double ExpressionTree::evaluateTree(TreeNode* node) {
        if (node->left == nullptr && node->right == nullptr) {
            return stod(node->value);
        }

        double leftVal = evaluateTree(node->left);
        double rightVal = evaluateTree(node->right);

        if (node->value == "+") return leftVal + rightVal;
        if (node->value == "-") return leftVal - rightVal;
        if (node->value == "*") return leftVal * rightVal;
        if (node->value == "/") return leftVal / rightVal;

        return 0;
    }