#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;
//
// Created by 陈姝宇 on 2020/4/15.
//
vector<vector<int>> mat;
queue<pair<int, int>> q;
int n, m;

void clear(queue<pair<int, int>>& q) {
    queue<pair<int, int>> empty;
    swap(empty, q);
}

int findDis(int x, int y) {
    int level = 1;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if (i - 1 >= 0) {
                if (!mat[i - 1][j]) {
                    return level;
                } else {
                    q.push(pair<int, int>(i - 1, j));
                }
            }
            if (i + 1 < n) {
                if (!mat[i + 1][j]) {
                    return level;
                } else {
                    q.push(pair<int, int>(i + 1, j));
                }
            }
            if (j - 1 >= 0) {
                if (!mat[i][j - 1]) {
                    return level;
                } else {
                    q.push(pair<int, int>(i, j - 1));
                }
            }
            if (j + 1 < m) {
                if (!mat[i][j + 1]) {
                    return level;
                } else {
                    q.push(pair<int, int>(i, j + 1));
                }
            }
        }
        ++level;
    }
    return level;
}

vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
    mat=matrix;
    n = matrix.size();
    m = matrix[0].size();


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j]) {
                clear(q);
                q.push(pair<int, int>(i, j));
                matrix[i][j] = findDis(i, j);
            }
        }
    }

    return matrix;
}

int mainupdateMatrix() {
    vector<vector<int>> matrix =
            {{0, 1, 0, 1, 1},
             {1, 1, 0, 0, 1},
             {0, 0, 0, 1, 0},
             {1, 0, 1, 1, 1},
             {1, 0, 0, 0, 1}};
    vector<vector<int>> newmatrix = updateMatrix(matrix);
    cout << newmatrix.size();
}