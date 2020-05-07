#include <map>
#include <vector>
#include <iostream>

using namespace std;

//
// Created by 陈姝宇 on 2020/5/6.
//

int mincostTickets(vector<int> &days, vector<int> &costs) {
    int day_size = days.size();
    int day_after[day_size + 1][3];
    int j7 = 1;
    int j30 = j7;
    for (int i = 0; i < day_size; ++i) {
        // 记录下i天之后大于等于7天的最小一天
        day_after[i][1] = 0; // 为0说明不存在
        // 记录下i天之后大于等于30天的最小一天
        day_after[i][2] = 0; // 为0说明不存在
        // 只要不是最后一天，那么
        if (i == days.size() - 1) day_after[i][0] = 0;
            //  i天之后大于等于1天的最小一天就是days里存的下一天
        else day_after[i][0] = i + 1;
        // 一次遍历，i+1天的7天必然大于等于i天的7天
        for (; j7 < days.size(); ++j7) {
            if (days[j7] - days[i] >= 7) {
                day_after[i][1] = j7;
                break;
            }
        }
        for (; j30 < days.size(); ++j30) {
            if (days[j30] - days[i] >= 30) {
                day_after[i][2] = j30;
                break;
            }
        }
    }
    // 0--1天，1--7天，2--30天
    int dp[days.size()][4];
    // 从尾到头算
    for (int i = days.size() - 1; i >= 0; --i) {
        // 三种情况
        for (int j = 0; j < costs.size(); j++) {
            if (day_after[i][j]) dp[i][j] = costs[j] + dp[day_after[i][j]][3];
            else dp[i][j] = costs[j];
        }
        // 取小
        dp[i][3] = min(dp[i][0], min(dp[i][1], dp[i][2]));
    }
    // 从第一天开始算
    return dp[0][3];
}

//int main() {
//    // [1,4,6,7,8,20]
//    // [2,7,15]
//    vector<int> days = {1, 4, 6, 7, 8, 20};
//    vector<int> costs = {2, 7, 15};
//    cout << mincostTickets(days, costs);
//}