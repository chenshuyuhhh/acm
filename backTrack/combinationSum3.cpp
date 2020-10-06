#include <vector>

using namespace std;

//
// Created by 陈姝宇 on 2020/9/11.
//
class CombinationSum3 {
private:
    vector<vector<int>> result;
    int cs3_n;
    int cs3_k;

    void backTrack(int begin, int sum, vector<int> v) {
        if (v.size() == cs3_k && sum == cs3_n) {
            result.push_back(v);
            return;
        }

        for (int i = begin; i <= 9; ++i) {
            if (i + sum <= cs3_n) {
                v.push_back(i);
                backTrack(i + 1, sum + i, v);
                v.pop_back();
            } else break;
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        cs3_n = n;
        cs3_k = k;
        backTrack(0, 0, {});
        return result;
    }
};