#include <string>

using namespace std;
//
// Created by 陈姝宇 on 2020/4/6.
//

int minthree(int a, int b, int c) {
    return min(min(a, b), c);
}

int minDistance(string word1, string word2) {
    int dp[word1.size() + 1][word2.size() + 1];

    // boundary
    for (int i = 0; i <= word1.size(); ++i) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= word2.size(); ++j) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= word1.size(); ++i) {
        for (int j = 1; j <= word2.size(); ++j) {
            int modify = dp[i - 1][j - 1];
            if (word1[i - 1] != word2[j - 1]) ++modify;
            dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), modify);
        }
    }
    return dp[word1.size()][word2.size()];
}

int main72() {
    minDistance("horse","ros");
}