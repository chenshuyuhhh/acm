#include <vector>

using namespace std;
//
// Created by 陈姝宇 on 2020/9/9.
//

class CanJump {
public:
    bool canJump(vector<int> &nums) {
        for (int i = 0; i < nums.size();) {
            int step = nums[i];
            int maxStep = 0;
            int maxj = 0;
            for (int j = 1; j <= step; ++j) {
                if (nums[i + j] + j > maxStep) {
                    maxStep = nums[i + j] + j;
                    maxj = j;
                }
            }
            if (maxj == 0) return false;

            if (i + maxStep + 1 >= nums.size()) return true;

            i += maxj;
        }
        return true;
    }
};