#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
#include <limits>

using namespace std;

//
// Created by 陈姝宇 on 2020/3/26.
//
// 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
// 注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

int maxProfit2(vector<int> &prices) {
    int size = prices.size();
    int array_000 = 0;
    int array_010 = 0;
    int array_001 = INT32_MIN;
    int array_011 = INT32_MIN;

    for (int i = 0; i < size; ++i) {
        array_010 = max(array_010, array_011 + prices[i]);
        array_011 = max(array_011, array_000 - prices[i]);
        array_000 = max(array_000, array_001 + prices[i]);
        array_001 = max(array_001, -prices[i]);

        //  array[i][0][0] = max(array[i - 1][0][0], array[i - 1][0][1] + prices[i]);
        // array[i][1][0] = max(array[i - 1][1][0], array[i - 1][1][1] + prices[i]);
        //  array[i][0][1] = max(array[i - 1][0][1], -prices[i]);
        // array[i][1][1] = max(array[i - 1][0][1], array[i - 1][0][0] - prices[i]);
    }
    return max(0, max(array_000, array_010));
}

