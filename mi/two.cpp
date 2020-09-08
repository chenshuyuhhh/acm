#include <iostream>
#include <queue>
#include <stack>

using namespace std;
//
// Created by 陈姝宇 on 2020/5/9.
//

struct TreeNode2 {
    int val;
    TreeNode2 *left;
    TreeNode2 *right;

    explicit TreeNode2(int val) : val(val), left(nullptr), right(nullptr) {};
};


int visit(TreeNode2 *tn) {
    if (tn == nullptr) return 0;
    int sum = 0;
    int k = 1;
    int num = 0;
    stack<TreeNode2 *> stack;
    while (tn != nullptr) {
        while (tn) {
            // 入栈
            stack.push(tn);
            // 入栈对应增加
            num += tn->val * k;
            k *= 10;
            cout << tn->val << endl;
            tn = tn->left;
        }
        sum += num;
        tn = stack.top();
        stack.pop();
        while (tn->right == nullptr && !stack.empty()) {
            tn = stack.top();
            stack.pop();
        }
        tn = tn->right;
    }
}

int maintwo() {
    auto *tn = new TreeNode2(1);
    TreeNode2 *head = tn;
    tn->left = new TreeNode2(2);
    tn->right = new TreeNode2(3);
    tn = tn->left;
    tn->left = new TreeNode2(4);
    tn->right = new TreeNode2(5);
    visit(head);
}