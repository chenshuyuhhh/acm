#include <vector>
#include <algorithm>

using namespace std;

//
// Created by 陈姝宇 on 2020/9/9.
//

class CombinationSum {

private:
    vector<int> cands;
    vector<vector<int>> combination;
    int tar;

    void backTrack(int begin, int sum, vector<int> result) {
        if (sum == tar) {
            combination.push_back(result);
            return;
        }

        for (int i = begin; i < cands.size(); ++i) {
            if (cands[i] + sum <= tar) {
                result.push_back(cands[i]);
                backTrack(i, sum + cands[i], result);
                result.pop_back();
            } else break;
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        tar = target;
        sort(candidates.begin(), candidates.end());
        cands = candidates;
        backTrack(0,0,{});
        return  combination;
    }
};