#include <string>
#include <iostream>
#include <set>
#include <map>

using namespace std;
//
// Created by 陈姝宇 on 2020/4/20.
//

// S1=[s1,n1] and S2=[s2,n2].
// Find the maximum integer M such that [S2,M] can be obtained from S1.

int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    int p1 = 0; // ===>s1
    int p2 = 0; // ===>s2
    int size2 = s2.size();
    int size1 = s1.size();
    set<int> begin;
    int n = 0;
    int now_begin;
    pair<int, int> before_begin;
    map<int, pair<int, int>> m;
    map<int, int> end;
    // while loop
    while (p1 < n1 * size1) {
        p2 = 0;
        // first char
        int k = 0;
        while (s1[p1 % size1] != s2[p2] && k < size1) {
            ++p1;
            ++k;
        }
        if (n == 0 && k == size1) return 0;
        now_begin = p1 % size1;
        if (!begin.insert(now_begin).second) {
            before_begin = m[now_begin];
            break;
        }
        m[now_begin] = pair<int, int>(p1 / size1, n);
        ++p2;
        ++p1;
        for (; p2 < size2; ++p2) {
            while (s1[p1 % size1] != s2[p2]) {
                ++p1;
            }
            ++p1;
        }
        // 第n个s2的结尾在p1的段落位置
        end[n] = (p1 - 1) / size1;
        ++n;
    }  // not insert before
    if (p1 >= n1 * size1) {
        return n / n1;
    }
    // p1/size1-before_begin.first ==> n1
    //(n-before_begin.second) ==> n2
    int s2_len = n - before_begin.second;
    int s1_sum_right = n1 - before_begin.first;
    int s1_num = (p1 / size1 - before_begin.first);
    int cnt = s1_sum_right / s1_num * s2_len + before_begin.second;
    int right = s1_sum_right % s1_num;
    if (right == 0) {
        cnt -= s2_len;
        right = s1_num;
    }
    for (int i = before_begin.second; i < n; ++i) {
        if (end[i] - before_begin.first < right) {
            ++cnt;
        } else break;
    }
    return cnt / n2;
}

//int main() {
//    string s1 = "musicforeve", s2 = "lovelive";
//    int n1 = 10, n2 = 100000;
//    cout << getMaxRepetitions(s1, n1, s2, n2);
//}