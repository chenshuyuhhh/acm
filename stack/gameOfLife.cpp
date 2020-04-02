#include <iostream>
#include <vector>

using namespace std;

int n;
int m;
//
// Created by 陈姝宇 on 2020/4/2.
//

bool increase(int i, int j) {
    return (0 <= i && i < n && 0 <= j && j < m);
}

void gameOfLife(vector<vector<int>> &board) {
    n = board.size(); // row
    m = board[0].size(); // column

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] > 0) {
                if (increase(i + 1, j)) {
                    if (board[i + 1][j] <= 0) board[i + 1][j] -= 1;
                    else board[i + 1][j] += 1;
                }
                if (increase(i + 1, j - 1)) {
                    if (board[i + 1][j - 1] <= 0) board[i + 1][j - 1] -= 1;
                    else board[i + 1][j - 1] += 1;
                }
                if (increase(i + 1, j + 1)) {
                    if (board[i + 1][j + 1] <= 0) board[i + 1][j + 1] -= 1;
                    else board[i + 1][j + 1] += 1;
                }
                if (increase(i, j + 1)) {
                    if (board[i][j + 1] <= 0) board[i][j + 1] -= 1;
                    else board[i][j + 1] += 1;
                }
                if (increase(i, j - 1)) {
                    if (board[i][j - 1] <= 0) board[i][j - 1] -= 1;
                    else board[i][j - 1] += 1;
                }
                if (increase(i - 1, j)) {
                    if (board[i - 1][j] <= 0) board[i - 1][j] -= 1;
                    else board[i - 1][j] += 1;
                }
                if (increase(i - 1, j - 1)) {
                    if (board[i - 1][j - 1] <= 0) board[i - 1][j - 1] -= 1;
                    else board[i - 1][j - 1] += 1;
                }
                if (increase(i - 1, j + 1)) {
                    if (board[i - 1][j + 1] <= 0) board[i - 1][j + 1] -= 1;
                    else board[i - 1][j + 1] += 1;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int v = board[i][j];
            if (v == -3 || v == 3 || v == 4) board[i][j] = 1;
            else board[i][j] = 0;
        }
    }
}

int main289() {
    vector<vector<int>> boards = {{0, 1, 0},
                                  {0, 0, 1},
                                  {1, 1, 1},
                                  {0, 0, 0}};
    gameOfLife(boards);
    cout << boards.size();
}
