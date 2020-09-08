#include <vector>
#include <algorithm>

using namespace std;

//
// Created by 陈姝宇 on 2020/9/8.
//

class FindContentChildren {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cnt = 0;

        for (int i = 0, j = 0; i < s.size() && j < g.size(); ++i) {
            if (s[i] >= g[j]) {
                ++cnt;
                ++j;
            }
        }
        return cnt;
    }
};