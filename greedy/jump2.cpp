#include <vector>

using namespace std;

//
// Created by 陈姝宇 on 2020/9/11.
//

class Jump {
public:
    int jump(vector<int> &nums) {
        if (nums.size() <= 1) return 0;
        int cnt = 0;
        for (int i = 0; i < nums.size();) {
            int num = nums[i];
            int maxStep = 0;
            int maxj = 1;
            for (int j = 1; j <= num; ++j) {
                if (i + j >= nums.size()) break;
                if (nums[i + j] + j > maxStep) {
                    maxStep = nums[i + j] + j;
                    maxj = j;
                }
            }
            ++cnt;
            i += maxj;
        }
        return cnt;
    }
};