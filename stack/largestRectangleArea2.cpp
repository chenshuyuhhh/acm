#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//
// Created by 陈姝宇 on 2020/3/17.
//
int largestRectangleArea2(vector<int> &heights) {
    int size = heights.size();
    if (size == 0) {
        return 0;
    }
    stack<int> s;
    s.push(-1);
    int maxarea = 0;
    for (int i = 0; i < size; i++) {
        while (!s.empty() && s.top() != -1 && heights[s.top()] > heights[i]) {
            int index = s.top(); // position
            maxarea = max((i - index) * heights[index], maxarea);
            s.pop(); // remove top ele
        }
        s.push(i);
    }
    --size;
    int h = heights[s.top()];
    s.pop(); // remove top ele
    while (!s.empty()) {
        int left = s.top();
        maxarea = max((size - left) * h, maxarea);
        if (left == -1) break;
        h = heights[left]; // update next height
        s.pop();
    }
    return maxarea;
}

int main84_2() {
    vector<int> heights = {5,4,1,2};
    cout << largestRectangleArea2(heights);
}
