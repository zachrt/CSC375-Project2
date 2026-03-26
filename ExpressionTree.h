#include <string>
#include "TreeNode.h"
#include "Stack.h"

using namespace std;

class ExpressionTree {
private:
    TreeNode* root;

    int getPrecedence(char op);

    bool isOperator(char c);

    void attachOperator(Stack<TreeNode*>& nodeStack, Stack<char>& opStack);

public:
    ExpressionTree();

    void buildTreeFromInfix(string expression);
    
    double evaluateTree(TreeNode* node);
};