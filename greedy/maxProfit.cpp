#include <vector>

using namespace std;
//
// Created by 陈姝宇 on 2020/9/8.
//

class MaxProfit {
public:
    int maxProfit(vector<int> &prices) {
        int has = -7;
        int notHas = 0;
        for (int i = 1; i < prices.size(); ++i) {
            has = max(has, notHas - prices[i]);
            notHas = max(notHas, has + prices[i]);
        }
        return notHas;
    }
};