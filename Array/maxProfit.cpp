#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

//
// Created by 陈姝宇 on 2020/3/26.
//
//给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
// 注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

int maxProfit(vector<int> &prices) {
    int size = prices.size();
    map<int, map<int, int>> profit;
    map<int, int> profit_max;
    map<int, int> second_max;
    for (int i = 0; i < size - 1; ++i) {
        if (i > 0 && prices[i] == prices[i - 1]) continue;

        for (int j = i + 1; j < size; ++j) {
            int ab = prices[j] - prices[i];
            if (ab > 0) { // ab > 0 , prices[i] < prices[j]
                if (profit.find(i) != profit.end()) {
                    profit[i].insert(pair<int, int>(j, ab));
                    if (ab > profit_max[i]) profit_max[i] = ab;
                } else {
                    map<int, int> m;
                    m[j] = ab;
                    profit[i] = m;
                    profit_max[i] = ab;
                }
            }
        }
    }

    int max = 0;

    for (auto &it : profit) {
        map<int, int> first = it.second;
        for (auto &it_first : first) { // for every first
            int first_profit = it_first.second;
            max = first_profit > max ? first_profit : max;
            int profit_day = it_first.first;
            if (second_max.find(profit_day + 1) != second_max.end()) {
                int tmp = first_profit + second_max[profit_day + 1];
                max = tmp > max ? tmp : max;
            } else {
                int second = 0;
                for (int i = profit_day + 1; i < size; i++) { // find second
                    if (second_max.find(i) != second_max.end()) {
                        second = second_max[i] > second ? second_max[i] : second;
                        break;
                    } else if (profit_max.find(i) != profit_max.end()) {
                        second = profit_max[i] > second ? profit_max[i] : second;
                    }
                }
                second_max[profit_day + 1] = second;
                int tmp = first_profit + second;
                max = tmp > max ? tmp : max;
            }
        }
    }
    return max;
}

int main123() {
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << maxProfit(prices);
}