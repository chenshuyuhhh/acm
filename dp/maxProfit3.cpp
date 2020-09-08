#include <vector>

using namespace std;
//
// Created by 陈姝宇 on 2020/7/10.
//

int maxProfit3(vector<int> &prices) {
    //int profits[prices.size()][3];
    int profits0 = -prices[0]; // have p
    int profits1 = 0; //don't have p, in cold
    int profits2 = 0; //don't have p, not in cold
    int temp0 = profits0;
    int temp1 = profits1;
    int temp2 = profits2;
    for (int i = 1; i < prices.size(); ++i) {
        profits0 = max(temp0, temp2 - prices[i]);
        profits1 = temp0 + prices[i];
        profits2 = max(temp1, temp2);
        temp0 = profits0;
        temp1 = profits1;
        temp2 = profits2;
//        profits[i][0] = max(profits[i - 1][0], profits[i - 1][2] - prices[i]);
//        profits[i][1] = profits[i - 1][0] + prices[i];
//        profits[i][2] = max(profits[i - 1][1], profits[i - 1][2]);
    }
    return max(temp1, temp2);
}