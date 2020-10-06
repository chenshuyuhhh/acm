#include <vector>
#include <iostream>

using namespace std;

//
// Created by 陈姝宇 on 2020/9/13.
//
class ThreeSum {
public:
    vector<vector<int>> threeSum(vector<int> nums) {

        if (nums.size() < 3) // 不够三个数
            return {};
        sort(nums.begin(), nums.end());
        int size = nums.size();

        // 最小的大于0，最大的小于0，不可能加起来为0
        if (nums[0] > 0 | nums[size - 1] < 0) return {};
        vector<vector<int>> result;

        for (int i = 0; i < size - 2; ++i) {
            int num = nums[i];
            if (i > 0 && num == nums[i - 1]) continue;
            int left = i + 1;
            int right = size - 1;

            if (num > 0) break;
            do {
                int sum = num + nums[left] + nums[right];
                if (sum == 0) {
                    result.push_back({num, nums[left], nums[right]});
                    while (right > left && nums[right - 1] == nums[right]) {
                        --right;
                    }
                    --right;
                    while (left < right && nums[left] == nums[left + 1]) {
                        ++left;
                    }
                    ++left;
                } else if (sum > 0) {
                    while (right > left && nums[right - 1] == nums[right]) {
                        --right;
                    }
                    --right;
                } else {
                    while (right > left && nums[left] == nums[left + 1]) {
                        ++left;
                    }
                    ++left;
                }
            } while (left < right);
        }
        return result;
    }
};

//int main() {
//    ThreeSum *threeSum = new ThreeSum();
//    vector<vector<int>> v = threeSum->threeSum({0, 0, 0});
//    cout << v.size();
//}