#include <iostream>
#include <vector>

using namespace std;
//
// Created by 陈姝宇 on 2020/3/26.
// 123

int numRookCaptures(vector<vector<char>> &board) {
    int n = 8;
    int x = 0, y = 0;
    int nums = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 'R') { // rock
                x = i;
                y = j;
                break;
            }
        }
    }

    for (int j = y - 1; j >= 0; --j) { // to left
        char tmp = board[x][j];
        if (tmp == 'p') {
            ++nums;
            break;
        } else if (tmp == 'B') break;
    }
    for (int j = y + 1; j < n; ++j) { // to right
        char tmp = board[x][j];
        if (tmp == 'p') {
            ++nums;
            break;
        } else if (tmp == 'B') break;
    }
    for (int i = x - 1; i >= 0; --i) { // to top
        char tmp = board[i][y];
        if (tmp == 'p') {
            ++nums;
            break;
        } else if (tmp == 'B') break;
    }
    for (int i = x + 1; i < n; ++i) { // to down
        char tmp = board[i][y];
        if (tmp == 'p') {
            ++nums;
            break;
        } else if (tmp == 'B') break;
    }
    return nums;
}