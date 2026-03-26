#include <string>

#ifndef MY_STRUCT_H
#define MY_STRUCT_H

using namespace std;

struct TreeNode {
    string value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

#endif