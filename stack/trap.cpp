#include <iostream>
#include <vector>
#include <stack>

using namespace std;
//
// Created by 陈姝宇 on 2020/3/19.
//

// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
int trap(vector<int> &height) {
    // bool onIncrease = false;
    stack<int> s;
    s.push(0);
    int left = height[0];
    int maxarea = 0;
    for (int i = 0; i < height.size(); i++) {
        int top = s.top();
        int ele = height[i];
        if (top <= ele) {
            s.push(ele);
        } else { // top > ele
            int height = top > left ? left : top; // height = min(top,left)
            while(!s.empty() ){

            }
        }
    }
}

int maintrap() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
}