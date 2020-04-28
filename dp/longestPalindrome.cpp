#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

//
// Created by 陈姝宇 on 2020/4/6.
//
// solution two
string longestPalindrome1(string s) {
    string s_rev = s; // original
    reverse(s.begin(), s.end());
    int N = s.size();
    int p[N + 2][N + 2];
    int max = 0;
    string maxS = "";
    for (int i = 0; i < N; ++i) {
        p[0][i] = 0;
        p[i][0] = 0;
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (s_rev[i - 1] != s[j - 1]) p[i][j] = 0;
            else p[i][j] = p[i - 1][j - 1] + 1;

            if (p[i][j] > max && (i + j) == (N + p[i][j])) {
                max = p[i][j];
                maxS = s_rev.substr(i - max, max);
            }
        }
    }
    return maxS;
}

int main5() {
    //cout << longestPalindrome("abc435cba");
    cout << longestPalindrome1("babad");
}