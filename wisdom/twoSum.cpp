#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

//
// Created by 陈姝宇 on 2020/4/26.
//
vector<int> twoSum(vector<int> &nums, int target) {
    map<int, int> hashnum;
    vector<int> halfresult;
    for (int i = 0; i < nums.size(); ++i) {
        int temp = nums[i];
        if ((temp + temp) == target) {
            halfresult.push_back(i);
        } else {
            hashnum.insert(pair<int, int>(temp, i));
        }
    }
    if (halfresult.size() == 2) {
        return halfresult;
    }
    map<int, int>::iterator it;
    for (it = hashnum.begin(); it != hashnum.end(); ++it) {
        int num2 = target - it->first;
        if (hashnum.find(num2) != hashnum.end()) {
            int num1 = it->second;
            num2 = hashnum.find(num2)->second;
            if (num1 != num2) {
                return {num1, num2};
            }
        }
    }
    return {};
}

//int main() {
//    vector<int> nums = {3, 3};
//    vector<int> sum = twoSum(nums, 6);
//    cout << sum[0] << " " << sum[1];
//}