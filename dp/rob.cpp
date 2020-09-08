#include <vector>
#include <iostream>

using namespace std;
//
// Created by 陈姝宇 on 2020/5/29.
//

int rob(vector<int> &nums) {
    if (nums.size() == 0) return 0;
    else if (nums.size() == 1) return nums[0];
    else if (nums.size() == 2) return max(nums[0], nums[1]);

    int dp[nums.size()];
    dp[nums.size() - 1] = nums[nums.size() - 1];
    dp[nums.size() - 2] = max(nums[nums.size() - 2], nums[nums.size() - 1]);
    for (int i = nums.size() - 3; i >= 0; ++i) {
        dp[i] = max(dp[i + 1], dp[i + 2] + nums[i]);
    }
    return dp[0];
}

//int main() {
//    vector<int> nums = {1, 2, 3, 1};
//    cout << rob(nums);
//}