#include <vector>
#include <string>
#include <iostream>

using namespace std;

//
// Created by 陈姝宇 on 2020/7/12.
//

int calculateMinimumHP(vector<vector<int>> dungeon) {
    int m = dungeon.size();
    if (m == 0)
        return 0;
    int n = dungeon[0].size();
    int dp[m + 1][n + 1];
    --m;
    --n;
    dp[m][n] = -dungeon[m][n] + 1;
    for (int i = n - 1; i >= 0; --i) {
        dp[m][i] = max(dp[m][i + 1] - dungeon[m][i], 1);
    }
    for (int i = m - 1; i >= 0; --i) {
        dp[i][n] = max(dp[i + 1][n] - dungeon[i][n], 1);
    }

    --m;
    --n;

    for (int i = m; i >= 0; --i) {
        for (int j = n; j >= 0; --j) {
            dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 1);
        }
    }
    return dp[0][0];
}

int main() {
    cout << calculateMinimumHP({
                                       {-2, -3,  3},
                                       {-5, -10, 1},
                                       {10, 30,  -5}
                               });
}