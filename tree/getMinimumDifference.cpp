#include <iostream>
#include <stack>

using namespace std;
//
// Created by 陈姝宇 on 2020/9/8.
//

class GetMinimumDifference {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

public:

    int getMinimumDifference(TreeNode *root) {
        if (root == nullptr)
            return -1;
        stack<TreeNode *> s;
        TreeNode *node = root;
        int minD = -1;
        int last = 0;
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

            if (minD == -1) {
                last = node->val;
                minD = INT32_MAX;
            } else {
                minD = min(minD, node->val - last);
                last = node->val;
            }
            cout << node->val << endl;
            node = node->right;
        }
    }

};