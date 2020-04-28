#include <string>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
//
// Created by 陈姝宇 on 2020/4/28.
//

vector<int> singleNumbers(vector<int> &nums) {
    set<int> s;
    for (int num : nums) {
        if (!s.insert(num).second) {
            s.erase(num);
        }
    }
    vector<int> result;
    result.assign(s.begin(),s.end());
    return result;
}