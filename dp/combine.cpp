#include <vector>
#include <string>
#include <iostream>

using namespace std;

//
// Created by 陈姝宇 on 2020/9/8.
//

int combine_k;
int combine_n;
vector<vector<int>> combine_result;

void combineBackTrack(int begin, vector<int> one) {
    if (one.size() == combine_k) {
        combine_result.push_back(one);
        return;
    }

    for (int i = begin; i <= combine_n; ++i) {
        one.push_back(i);
        combineBackTrack(begin + 1, one);
        one.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    combine_k = k;
    combine_n = n;
    combineBackTrack(1, {});
}