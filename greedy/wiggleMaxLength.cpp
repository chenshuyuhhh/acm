#include <vector>

using namespace std;

//
// Created by 陈姝宇 on 2020/9/9.
//

class WiggleMaxLength {
public:
    int wiggleMaxLength(vector<int> &nums) {
        if (nums.size() <= 1)
            return 0;

        int cnt = 0;
        int i;
        bool isPositive;
        for (i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                isPositive = true;
                cnt += 2;
                break;
            } else if (nums[i] < nums[i - 1]) {
                isPositive = false;
                cnt += 2;
                break;
            }
        }

        for (; i < nums.size(); ++i) {
            if (isPositive && nums[i] - nums[i - 1] < 0) {
                ++cnt;
                isPositive = false;
            } else if (!isPositive && nums[i] - nums[i - 1] > 0) {
                ++cnt;
                isPositive = true;
            }
        }
        return cnt;
    }
};