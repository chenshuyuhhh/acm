#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

//
// Created by 陈姝宇 on 2020/9/15.
//

class Nightmare {
    static const int MAXN = 10;
    int gong[MAXN][MAXN];
    int visit[MAXN][MAXN][8]; // 用时间标记，便于区别不同状态
    int m, n;// m --> hang,n --> lie
    int min_cnt = 2147483647;
    int beginm, beginn;
    int endm, endn;
    set<pair<int, int>> s;

// time 为走到i，j处的时间
    bool dfs(int i, int j, int time, int cnt) {
        // 走到这个位置，标记已经看过
        visit[i][j][time] = cnt;

        // 是0，就不能再挣扎了
        if (time == 0) return false;

        // 达到终点
        if (i == endm && j == endn) {
            min_cnt = min(cnt, min_cnt);
            return true;
        }

        // 可以重置时间
        if (s.find(pair<int, int>(i, j)) != s.end()) {
            time = 6;
            visit[i][j][time] = cnt;
        }

        // 走下一步，时间需-1
        --time;
        ++cnt;
        bool hasSucess = false;
        if (i + 1 < m && gong[i + 1][j] == 1 && (visit[i + 1][j][time] == -1 || visit[i + 1][j][time] > cnt)) {
            hasSucess |= dfs(i + 1, j, time, cnt);
        }

        if (j + 1 < n && gong[i][j + 1] == 1 && (visit[i][j + 1][time] == -1 || visit[i][j + 1][time] > cnt)) {
            hasSucess |= dfs(i, j + 1, time, cnt);
        }

        if (i - 1 >= 0 && gong[i - 1][j] == 1 && (visit[i - 1][j][time] == -1 || visit[i - 1][j][time] > cnt)) {
            hasSucess |= dfs(i - 1, j, time, cnt);
        }

        if (j - 1 >= 0 && gong[i][j - 1] == 1 && (visit[i][j - 1][time] == -1 || visit[i][j - 1][time] > cnt)) {
            hasSucess |= dfs(i, j - 1, time, cnt);
        }

        return hasSucess;
    }


    int main() {
        int cases;
        cin >> cases;
        //    n0 n1 n2
        // m0
        // m1

        while (cases--) {
            cin >> m >> n;
            min_cnt = 2147483647;
            s.clear();
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    cin >> gong[i][j];
                    if (gong[i][j] == 2) {
                        beginm = i;
                        beginn = j;
                        gong[i][j] = 1;
                    } else if (gong[i][j] == 3) {
                        endm = i;
                        endn = j;
                        gong[i][j] = 1;
                    } else if (gong[i][j] == 4) {
                        s.insert(pair<int, int>(i, j));
                        gong[i][j] = 1;
                    }
                    memset(visit[i][j], -1, sizeof(int) * 8);
                }
            }


            bool isSuccess = dfs(beginm, beginn, 6, 0);
            if (isSuccess) {
                cout << min_cnt << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
};