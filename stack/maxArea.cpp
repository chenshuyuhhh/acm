#include <iostream>
#include <vector>

using namespace std;
//
// Created by 陈姝宇 on 2020/3/29.
//

int maxArea(vector<int> &height) {
    int maxArea = 0;
    int i = 0;
    int j = height.size() - 1;
    while (i != j) {
        if (height[i] < height[j]) {
            maxArea = max((j - i) * height[i], maxArea);
            ++i;
        } else {
            maxArea = max((j - i) * height[j], maxArea);
            --j;
        }
    }
    return maxArea;
}

//int main() {
//    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
//    cout << maxArea(height);
//}