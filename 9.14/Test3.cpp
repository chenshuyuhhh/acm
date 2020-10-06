#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <cstring>
#include <algorithm>

using namespace std;

//
// Created by 陈姝宇 on 2020/9/13.
//
class Test3 {
    int nn;
    int mm;
    int **hen;
    int **shu;
    int **moneys;
    int **visit;
    int sum = 0;
    set<pair<int, int>> s;
    set<pair<int, int>> gc;

    void dfs(int i, int j, int m) {
        if (moneys[i][j] <= m)
            return;
        moneys[i][j] = m;

        if (gc.find(pair<int, int>(i, j)) != gc.end()) return;

        if (i - 1 >= 0) {
            dfs(i - 1, j, m + shu[i - 1][j]);
        }
        if (i + 1 < nn) {
            dfs(i + 1, j, m + shu[i][j]);
        }
        if (j - 1 >= 0) {
            dfs(i, j - 1, m + hen[i][j - 1]);
        }
        if (j + 1 < mm) {
            dfs(i, j + 1, m + hen[i][j]);
        }
    }

//void findPath(int i, int j, int m) {
//    if (i - 1 >= 0 && !visit[i - 1][j] && m + shu[i - 1][j] == moneys[i - 1][j]) {
//        visit[i - 1][j] = 1;
//        sum += shu[i - 1][j];
//        findPath(i - 1, j, m);
//    }
//    if (i + 1 < nn && !visit[i + 1][j] && m + shu[i][j] == moneys[i + 1][j]) {
//        visit[i + 1][j] = 1;
//        sum += shu[i][j];
//        findPath(i + 1, j, m);
//    }
//    if (j - 1 >= 0 && !visit[i][j - 1] && m + hen[i][j - 1] == moneys[i][j - 1]) {
//        visit[i][j - 1] = 1;
//        sum += hen[i][j - 1];
//        findPath(i, j - 1, m);
//    }
//    if (j + 1 < mm && !visit[i][j + 1] && m + hen[i][j] == moneys[i][j + 1]) {
//        visit[i][j + 1] = 1;
//        sum += hen[i][j];
//        findPath(i, j + 1, m);
//    }
//}

    int mainTest3() {
        int n, m;
        cin >> n >> m;
        nn = n;
        mm = m;

        int stations[n][m];
        moneys = new int *[n];
        for (int i = 0; i < n; ++i) {
            moneys[i] = new int[m];
            for (int j = 0; j < m; ++j) {
                moneys[i][j] = INT32_MAX;
            }
        }


        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> stations[i][j];
                if (stations[i][j] > 0) s.insert(pair<int, int>(i, j));
                else if (stations[i][j] < 0) gc.insert(pair<int, int>(i, j));
            }
        }

        hen = new int *[n];
        for (int i = 0; i < n; ++i) {
            hen[i] = new int[m - 1];
            for (int j = 0; j < m - 1; ++j) {
                cin >> hen[i][j];
            }
        }

        shu = new int *[n - 1];
        for (int i = 0; i < n - 1; ++i) {
            shu[i] = new int[m];
            for (int j = 0; j < m; ++j) {
                cin >> shu[i][j];
            }
        }

        for (const auto &it : s) {
            dfs(it.first, it.second, stations[it.first][it.second]);
        }

//    visit = new int *[n];
//    for (int i = 0; i < n; ++i) {
//        visit[i] = new int[m];
//        memset(visit[i], 0, sizeof(int) * m);
//    }

        for (const auto &it : gc) {
            int i = it.first;
            int j = it.second;
            sum += moneys[i][j];
//        if (!visit[i][j] && moneys[i][j] == stations[i][j]) {
//            sum += stations[i][j];
//            findPath(i, j, stations[i][j]);
//        }
        }
        cout << sum << endl;
    }
};