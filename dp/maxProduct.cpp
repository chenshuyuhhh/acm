#include <vector>
#include <math.h>

using namespace std;
//
// Created by 陈姝宇 on 2020/5/18.
//

int maxProduct(vector<int> &nums) {
    if (nums.empty())
        return 0;
    if (nums.size() == 1)
        return nums[0];

    int maxNum = nums[0];
    int minNum = nums[0];
    int mm = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        int numNow = nums[i];
        int maxtemp = maxNum * numNow;
        int mintemp = minNum * numNow;
        maxNum = max(numNow, max(maxtemp, mintemp));
        minNum = min(numNow, min(maxtemp, mintemp));
        mm = max(max(maxNum, minNum), mm);
    }
    return mm;
}

