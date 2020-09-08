#include <iostream>
#include <stack>

using namespace std;

//
// Created by 陈姝宇 on 2020/5/5.
//
class IsValidBST {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

public:

    bool isValidBST(TreeNode *root) {
        TreeNode *node = root;
        stack<TreeNode *> s;
        int last = INT32_MIN;
        while (node != nullptr || !s.empty()) {
            if (node != nullptr) {
                while (node->left != nullptr) {
                    s.push(node);
                    node = node->left;
                }
            } else {
                node = s.top();
                s.pop();
            }
            if (node->val < last)
                return false;
            last = node->val;
            node = node->right;
        }

        return true;
    }
};