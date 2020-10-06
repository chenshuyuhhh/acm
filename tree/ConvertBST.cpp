#include <iostream>
#include <stack>

using namespace std;

//
// Created by 陈姝宇 on 2020/9/8.
//
class ConvertBST {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

public:
    TreeNode *convertBST(TreeNode *root) {
        TreeNode *node = root;
        stack<TreeNode *> stack;
        int sum = 0;

        while (!stack.empty() || root != nullptr) {
            if (node != nullptr) {
                while (node->right != nullptr) {
                    stack.push(node);
                    node = node->right;
                }
            } else {
                node = stack.top();
                stack.pop();
            }

            int temp = node->val;
            node->val += sum;
            sum += temp;

            node = node->left;
        }
        return root;
    }
};