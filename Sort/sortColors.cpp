#include <vector>
#include <iostream>

using namespace std;
//
// Created by 陈姝宇 on 2020/3/29.
//

// 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
//
// 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
//
// 注意:
// 不能使用代码库中的排序函数来解决这道题。
void sortColors(vector<int> &nums) {
    int red = 0;
    int white = 0;
    int blue = 0;
    for (int num : nums) {
        if (num == 0) ++red;
        else if (num == 1) ++white;
        else ++blue;
    }

    nums.clear();
    for (int i = 0; i < red; ++i) nums.push_back(0);
    for (int i = 0; i < white; ++i) nums.push_back(1);
    for (int i = 0; i < blue; ++i) nums.push_back(2);
}
//
//int main() {
//    vector<int> nums = {2, 0, 2, 1, 1, 0};
//    sortColors(nums);
//    cout << nums.size();
//}