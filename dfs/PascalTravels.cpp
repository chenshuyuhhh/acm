#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <queue>

using namespace std;

//
// Created by 陈姝宇 on 2020/9/16.
//

class PascalTravels {
    static const int MAXN = 35;
    int board[MAXN][MAXN];

    unsigned long long dp[MAXN][MAXN];

    string line;
    int n;

    unsigned long long dfs(int i, int j) {
        //visit[i][j] = 1;
        int step = board[i][j];
        if (dp[i][j])
            return dp[i][j];
        if (step == 0)
            return 0;

        if (i + step < n) {
            dp[i][j] += dfs(i + step, j);
        }

        if (j + step < n) {
            dp[i][j] += dfs(i, j + step);
        }

        return dp[i][j];
    }

    int main() {
        while (cin >> n) {
            if (n == -1)break;

            for (int i = 0; i < n; ++i) {
                cin >> line;
                for (int j = 0; j < n; ++j) {
                    board[i][j] = line[j] - '0';
                }
                memset(dp[i], 0, sizeof(unsigned long long) * n);
            }
            dp[n - 1][n - 1] = 1;

            cout << dfs(0, 0) << endl;
        }
        return 0;
    }
};