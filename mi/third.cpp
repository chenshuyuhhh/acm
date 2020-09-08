#include <iostream>
#include <queue>

using namespace std;
//
// Created by 陈姝宇 on 2020/5/9.
//

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
};

int sum_mi_third;

void dfs(TreeNode *treeNode, int k, int num) {
    // get value
    int value = treeNode->val;
    // caculate num
    num += value * k;
    // next digit
    k *= 10;
    if (treeNode->right == nullptr && treeNode->left == nullptr) {
        sum_mi_third += num;
        return;
    }
    if (treeNode->left != nullptr) {
        dfs(treeNode->left, k, num);
    }
    if (treeNode->right != nullptr) {
        dfs(treeNode->right, k, num);
    }
}

long long getNumber(TreeNode *treeNode) {
    if (treeNode == nullptr) return 0;
    int k;
    dfs(treeNode, 1, 0);
    int result = sum_mi_third;
    sum_mi_third = 0;
    return result;
    queue<TreeNode *> q;
    q.push(treeNode);
    while (!q.empty()) {
        // get size of q
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode *tn = q.front();
            q.pop();
            int value = tn->val;
            // caculate num
            sum_mi_third += value * k;
            // next digit
            q.push(treeNode->left);
            q.push(treeNode->right);
        }
        k *= 10;
    }
}

// convert to tree by array
void getTree(TreeNode *tn, vector<string> input) {
    // "null" | number
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == "null") {
            tn->left = nullptr;
        }
    }
}

int mainmi() {
//    vector<string> input;
//    string value;
//    while (cin >> value) {
//        input.push_back(value);
//    }
    auto *tn = new TreeNode(1);
    TreeNode *head = tn;
    tn->left = new TreeNode(2);
    tn->right = new TreeNode(3);
    tn = tn->left;
    tn->left = new TreeNode(4);
    tn->right = new TreeNode(5);
    cout << getNumber(head);
//    getTree(tn, input);

}