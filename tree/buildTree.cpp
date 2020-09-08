#include <vector>
#include <stack>
#include <iostream>

using namespace std;

//
// Created by 陈姝宇 on 2020/5/22.
//
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//preorder = [3,9,20,15,7]
//inorder = [9,3,15,20,7]
//       13
//     /   \
//    9    20
//   / \  /  \
//  2  8 15   7
// /
//4
// \
//  1
// / \
//3  5
// preorder = [13,9,2,4|,1,3,5,8,20,15,7] i
// inorder =  [4|,3,1,5,2,9,8,13,15,20,7] j
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int size = preorder.size() - 1;
    if (size == -1)
        return nullptr;
    stack<TreeNode *> s;
    int i = 0; // point to preorder
    int j = 0; // point to inorder
    auto *head = new TreeNode(preorder[i]); // 这个不是真正的根节点
    s.push(head);
    TreeNode *result = head;
    while (i != size) {
        // 左孩子
        while (preorder[i] != inorder[j] && i < size) {
            head->left = new TreeNode(preorder[++i]);
            head = head->left;
            s.push(head);
        }

        // 回溯找具有右孩子的结点
        while (!s.empty() && s.top()->val == inorder[j]) {
            ++j;
            head = s.top();
            s.pop();
        }

        // 说明当前结点存在 right child
        if (i < size) {
            head->right = new TreeNode(preorder[++i]);
            head = head->right;
            s.push(head);
        }
    }

    return result;
}

//int main() {
//    vector<int> preorder = {1, 2};
//    vector<int> inorder = {2, 1};
//    TreeNode *head = buildTree(preorder, inorder);
//    cout << head->val;
//}
