#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;
//
// Created by 陈姝宇 on 2020/9/14.
//

// '+','-','*','/'
// (  )
class JudgePoint24 {

private:
    bool solve(vector<double> nums) {
        if (nums.size() == 1) {
            return fabs(nums[0] - 24) < 10e-6;
        }
        for (int i = 0; i < nums.size() - 1; ++i) {
            double n1 = nums[i];
            for (int j = i + 1; j < nums.size(); ++j) {
                double n2 = nums[j];

                vector<double> v;
                for (int k = 0; k < nums.size(); ++k) {
                    if (k != i && k != j) {
                        v.push_back(nums[k]);
                    }
                }

                v.emplace_back(n1 - n2);
                if (solve(v)) return true;
                v.pop_back();

                v.emplace_back(n2 - n1);
                if (solve(v)) return true;
                v.pop_back();

                v.emplace_back(n1 + n2);
                if (solve(v)) return true;
                v.pop_back();

                v.emplace_back(n1 * n2);
                if (solve(v)) return true;
                v.pop_back();

                if (fabs(n1) > 10e-6) {
                    v.emplace_back(n2 / n1);
                    if (solve(v)) return true;
                    v.pop_back();
                }

                if (fabs(n2) > 10e-6) {
                    v.emplace_back(n1 / n2);
                    if (solve(v)) return true;
                    v.pop_back();
                }
            }
        }
        return false;
    }

public:
    bool judgePoint24(vector<int> nums) {
        vector<double> numsd;
        for (int num : nums) {
            numsd.push_back((double) num);
        }

        return solve(numsd);
    }
};

//int main() {
//    auto *judgePoint24 = new JudgePoint24();
//    cout << judgePoint24->judgePoint24({4, 3, 1, 6});
//}