#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//
// Created by 陈姝宇 on 2020/5/4.
//
int jump(vector<int> &nums) {
    int i = 0;
    int step = 0;
    while (i < nums.size()) {
        int l = nums[i];
        // 边界条件，自己已经是最后一个
        if (i + 1 == nums.size())return step;
        // 从自己这里跨出去就是最后一个
        else if (i + 1 + l >= nums.size())
            return ++step;
        int max = 0;
        int i_next = i + 1;
        for (int j = 1; j <= l && i + j < nums.size(); ++j) {
            int l_temp = nums[j + i] + j;
            if (l_temp > max) {
                max = l_temp;
                i_next = j + i;
            }
        }
        i = i_next;
        ++step;
    }
    return step;
}
