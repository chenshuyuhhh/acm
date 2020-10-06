#include <vector>
#include <stack>

using namespace std;

//
// Created by 陈姝宇 on 2020/9/14.
//

class InorderTraversal {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

public:
    vector<int> inorderTraversal(TreeNode *root) {
        TreeNode *node = root;
        stack<TreeNode *> s;
        s.push(node);
        vector<int> v;

        while (!s.empty() || node != nullptr) {

            while (node != nullptr) {
                s.push(node);
                node = node->left;
            }
            node = s.top();
            s.pop();
            v.push_back(node->val);
            node = node->right;
        }
        return v;
    }
};