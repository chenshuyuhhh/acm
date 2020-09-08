#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//
// Created by 陈姝宇 on 2020/3/17.
//
// 用栈解决
int largestRectangleArea2(vector<int> &heights) {
    int size = heights.size();
    if (size == 0) {
        return 0;
    }
    stack<int> s;
    s.push(-1);
    s.push(0);
    int maxarea = 0;
    for (int i = 1; i < size; i++) {
        while (!s.empty() && s.top() != -1 && heights[s.top()] > heights[i]) {
            int h = heights[s.top()];
            s.pop(); // remove top ele
            int index = s.top(); // position
            maxarea = max((i - index - 1) * h, maxarea);
        }
        // heights[s.top()] <= heights[i]
        s.push(i);
    }
    // 栈中剩下的元素，右边都是可以达到右边界
    --size; // 右边界
    int h;
    while (!s.empty()) {
        // 已经达到最左边了
        if (s.top() == -1) break;
        h = heights[s.top()];
        s.pop();
        maxarea = max((size - s.top()) * h, maxarea);
    }
    return maxarea;
}

//int main() {
//    vector<int> heights = {5, 4, 1, 2};
//    cout << largestRectangleArea2(heights);
//}
