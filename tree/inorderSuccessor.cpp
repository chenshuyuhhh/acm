#include <stack>

using namespace std;
//
// Created by 陈姝宇 on 2020/9/8.
//

class Solution {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

public:
    TreeNode *nodeP;

    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        TreeNode *node = root;
        stack<TreeNode *> s;

        while (!s.empty() || node != nullptr) {
            if (node != nullptr) {
                while (node->left != nullptr) {
                    s.push(node);
                    node = node->left;
                }
            } else {
                node = s.top();
                s.pop();
            }
            if (node == p) {
                break;
            }
            node = node->right;
        }
        if (node != nullptr) {
            while (node->left != nullptr) {
                s.push(node);
                node = node->left;
            }
        } else {
            node = s.top();
            s.pop();
        }
        return node;
    }
};