#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cmath>
#include <cstdio>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class RunAwayGong {
    static const int MAXN = 101;
    char gong[MAXN][MAXN];
    int turn[MAXN][MAXN];
    int visit[MAXN][MAXN];
    int m, n;
    int k, X1, Y1, X2, Y2;

/**
 *
 * @param i 行数
 * @param j 列
 * @param cnt 还可以转几次弯
 * @param isHen 之前是横着的，如果是false则是竖着走
 * @return
 */
    bool dfs(int i, int j, int cnt, bool isHen) {

        // 已经不能再转了
        if (cnt < 0) return false;

        // 看过了，不看了
        if (visit[i][j])
            return false;

        // 记录下这个位置还可以转几次
        turn[i][j] = cnt;

        // 找到了
        if (i == X2 && j == Y2) return true;

        // 已经不能再转弯了，但是终点不在现在这个点的线上，那就一定不行，剪枝
        if (cnt == 0 && X2 != i && Y2 != j) {
            return false;
        }

        // 是否成功找到
        bool isSuccess = false;
        visit[i][j] = 1;
        if (isHen) { // 之前是横着走的情况
            if (cnt > 0) {
                // 竖着走，得转弯，可能转不动
                if (i - 1 >= 0 && gong[i - 1][j] == '.' && cnt - 1 >= turn[i - 1][j]) {
                    if (dfs(i - 1, j, cnt - 1, false)) return true;
                }

                if (i + 1 < m && gong[i + 1][j] == '.' && cnt - 1 >= turn[i + 1][j]) {
                    if (dfs(i + 1, j, cnt - 1, false)) return true;
                }
            }
            // 继续横着走
            if (j - 1 >= 0 && gong[i][j - 1] == '.' && cnt >= turn[i][j - 1]) {
                if (dfs(i, j - 1, cnt, true)) return true;
            }
            if (j + 1 < n && gong[i][j + 1] == '.' && cnt >= turn[i][j + 1]) {
                if (dfs(i, j + 1, cnt, true)) return true;
            }
        } else { // 之前是竖着走的情况
            if (i - 1 >= 0 && gong[i - 1][j] == '.' && cnt >= turn[i - 1][j]) {
                if (dfs(i - 1, j, cnt, false)) return true;
            }

            if (i + 1 < m && gong[i + 1][j] == '.' && cnt >= turn[i + 1][j]) {
                if (dfs(i + 1, j, cnt, false)) return true;
            }
            if (cnt > 0) {
                if (j - 1 >= 0 && gong[i][j - 1] == '.' && cnt - 1 >= turn[i][j - 1]) {
                    if (dfs(i, j - 1, cnt - 1, true)) return true;
                }
                if (j + 1 < n && gong[i][j + 1] == '.' && cnt - 1 >= turn[i][j + 1]) {
                    if (dfs(i, j + 1, cnt - 1, true)) return true;
                }
            }
        }
        visit[i][j] = 0;
        return isSuccess;

    }

    bool getStar() {
        // 初始化
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                turn[i][j] = -1;
                visit[i][j] = 0;
            }
        }

        // 开始不算转弯
        if (X1 - 1 >= 0 && gong[X1 - 1][Y1] == '.') {
            if (dfs(X1 - 1, Y1, k, false)) return true;
        }

        if (X1 + 1 < m && gong[X1 + 1][Y1] == '.') {
            if (dfs(X1 + 1, Y1, k, false)) return true;
        }
        if (Y1 - 1 >= 0 && gong[X1][Y1 - 1] == '.') {
            if (dfs(X1, Y1 - 1, k, true)) return true;
        }
        if (Y1 + 1 < n && gong[X1][Y1 + 1] == '.') {
            if (dfs(X1, Y1 + 1, k, true)) return true;
        }
        return false;
    }

    int main(int argc, char **argv) {
        int t;
        cin >> t;
        while (t--) {
            cin >> m >> n;

            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    cin >> gong[i][j];
                }
            }

            // y-lie, x--hang
            cin >> k >> Y1 >> X1 >> Y2 >> X2;
            --X1;
            --X2;
            --Y1;
            --Y2;
            bool isSuccess = false;
            if (X1 == X2 && Y1 == Y2) isSuccess = true;
            else if (gong[X1][Y1] != '*' && gong[X2][Y2] != '*') {
                isSuccess = getStar();
            }

            if (isSuccess) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
        return 0;
    }
};