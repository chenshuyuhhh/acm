#include <iostream>
#include <map>
#include <vector>

using namespace std;

//
// Created by 陈姝宇 on 2020/5/15.
//
int subarraySum(vector<int> &nums, int k) {
    // 为空
    if (nums.empty()) return 0;
    // 只有一个
    if (nums.size() == 1) {
        if (nums[0] == k) return 1;
        else return 0;
    }
    map<int, int> pre; // value - count
    pre[0] = 1;
    int sum = 0;
    int count = 0;
    for (int num : nums) {
        // 找前缀
        //pre[i] - pre[j] = k
        //pre[i] - k = pre[j]
        // 计算 i 的前缀值
        sum += num;

        // 先找pre，还是先加入？
        // 应当先找pre，此时计算出来的pre是给后面的数用的
        // 如果先加入，则find的时候，可能会找到自己，这样i-j=0，显然不符合要求
        if (pre.find(sum - k) != pre.end()) { // 找到了
            // 计入总数
            count += pre.find(sum - k)->second;
        }
        // 加入 pre
        if (pre.find(sum) == pre.end()) { // 之前没有这个前缀值
            pre[sum] = 1;
        } else pre[sum] = pre[sum] + 1;
    }
    return count;
}
//
//int main() {
//    vector<int> v = {1, 1, 1};
//    cout << subarraySum(v, 3);
//}