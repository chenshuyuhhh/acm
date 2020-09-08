#include <string>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

//
// Created by 陈姝宇 on 2020/5/8.
//
int maximalSquare(vector<vector<string>> &matrix) {
    if (matrix.size() == 0) return 0;
    int m = matrix.size();
    int n = matrix[0].size();
    int dp[m + 1][n + 1];
    for (int i = 0; i <= n; ++i) {
        dp[0][i] = 0;
    }
    int max = 0;
    for (int i = 1; i <= m; ++i) {
        dp[i][0] = 0;
        for (int j = 1; j <= n; ++j) {
            if (matrix[i - 1][j - 1] == "1") {
                int value = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                cout << value << " ";
                dp[i][j] = value;
                if (value > max) max = value;
            } else dp[i][j] = 0;
        }
    }
    return max * max;
}

//int main() {
//    vector<vector<string>> matrix = {
//            {"1", "0", "1", "0", "0"},
//            {"1", "0", "1", "1", "1"},
//            {"1", "1", "1", "1", "1"},
//            {"1", "0", "0", "1", "0"}
//    };
//    cout << maximalSquare(matrix);
//}
