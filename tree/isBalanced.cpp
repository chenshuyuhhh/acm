#include <algorithm>

using namespace std;

//
// Created by 陈姝宇 on 2020/9/8.
//
class IsBalanced {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

public:

    int getDepth(TreeNode *node) {
        if (node == nullptr) return 0;

        return max(getDepth(node->left), getDepth(node->right)) + 1;
    }

    bool isBalanced(TreeNode *root) {
        if (abs(getDepth(root->left) - getDepth(root->right)) < 2) {
            return isBalanced(root->left) && isBalanced(root->right);
        } else return false;
    }
};