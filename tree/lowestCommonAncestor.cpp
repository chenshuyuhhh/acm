//
// Created by 陈姝宇 on 2020/5/10.
//

struct TreeNode2 {
    int val;
    TreeNode2 *left;
    TreeNode2 *right;

    TreeNode2(int x) : val(x), left(nullptr), right(nullptr) {}
};


TreeNode2 *lowestCommonAncestor(TreeNode2 *root, TreeNode2 *p, TreeNode2 *q) {
    if (root == nullptr) return nullptr;
    if (root == p)return root;
    if (root == q)return root;

    auto *left = lowestCommonAncestor(root->left, p, q);
    auto *right = lowestCommonAncestor(root->right, p, q);

    if (left == nullptr) return right;
    if (right == nullptr) return left;
    return root;
}