//
// Created by 陈姝宇 on 2020/9/8.
//
class Solution {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    int sum = 0;

public:
    // node is supposed not to be nullptr
    void dfs(TreeNode *node, int val) {
        val = (val << 1) + node->val;
        if (node->left == nullptr && node->right == nullptr) {
            sum += val;
            return;
        }
        if (node->left != nullptr) {
            dfs(node->left, val);
        }
        if (node->right != nullptr) {
            dfs(node->right, val);
        }
    }

    int sumRootToLeaf(TreeNode *root) {
        if(root== nullptr)
            return 0;
        dfs(root, 0);
        return sum;
    }
};