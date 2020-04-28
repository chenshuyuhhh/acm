#include <iostream>
#include <vector>

using namespace std;

//
// Created by 陈姝宇 on 2020/4/25.
//
void dfs(int depth, int l, vector<int> &res, bool use[], vector<int> nums, vector<vector<int>> &result) {
    if (depth == l) {
        result.emplace_back(res);
        return;
    }

    for (int i = 0; i < l; ++i) {
        if (!use[i]) {
            use[i] = true;
            res.push_back(nums[i]);

            dfs(depth + 1, l, res, use, nums, result);

            res.pop_back();
            use[i] = false;
        }
    }
}

vector<vector<int>> permute(vector<int> &nums) {
    int l = nums.size();

    bool use[l];
    vector<int> res;
    vector<vector<int>> result;
    dfs(0, l, res, use, nums, result);
    return result;
}