#include <vector>
#include <iostream>

using namespace std;

//
// Created by 陈姝宇 on 2020/6/12.
//
vector<vector<int>> threeSum(vector<int> &nums) {
    int size = nums.size();
    if (size < 3) return {};

    // 排序nums
    sort(nums.begin(), nums.end());
    --size;
    vector<vector<int>> result;

    // 先算下临界吧
    if (nums[1] >= 0 || nums[1] != nums[2]) { //排除连续负数不用算的情况
        int num = nums[1];
        int left = 0;
        int right = size;
        while (1 < right) { // left 不能再长大，right 不能小于1
            int sum = num + nums[left] + nums[right];
            if (sum == 0) { // bingo
                vector<int> one = {nums[left], num, nums[right]};
                result.push_back(one);
            } else if (sum > 0) --right;
            else break;
        }
    }
    int i = 2;
    for (auto it = nums.begin(); it != nums.end(); ++it) {
        int num = *it;
        if (num <= 0 && num == *(it + 1)) {
            ++i;
            while (*(++it) == *(it + 1)) {
                nums.erase(it);
            }
        }

        int left = 0;
        int right = size;
        while (left < i && i < right) { // left 不能再长大，right 不能小于1
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) { // bingo
                vector<int> one = {nums[left], nums[i], nums[right]};
                result.push_back(one);
            } else if (sum > 0) --right;
            else ++left;
        }

    }
    for (int i = 2; i < size; ++i) {
        if (nums[i] == nums[i - 1]) {
            // repeated number
            continue;
        } else {
            int left = 0;
            int right = size;
            while (left < i && i < right) { // left 不能再长大，right 不能小于1
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) { // bingo
                    vector<int> one = {nums[left], nums[i], nums[right]};
                    result.push_back(one);
                } else if (sum > 0) --right;
                else ++left;
            }
        }

    }

    return result;
}

//int main() {
//    vector<int> v = {-1, 0, 1, 2, -1, -4};
//    cout << threeSum(v).size();
//}