#include <vector>

using namespace std;

//
// Created by 陈姝宇 on 2020/9/11.
//

class MaxProfit {
public:
    int maxProfit(vector<int> &prices, int fee) {
        if (prices.size() <= 1)
            return 0;
        int has = -prices[0] - fee;
        int noHas = 0;
        int temp = has;
        for (int i = 1; i < prices.size(); ++i) {
            has = max(has, noHas - prices[i] - fee);
            noHas = max(noHas, temp + prices[i]);
            temp = has;
        }
        return noHas;
    }
};