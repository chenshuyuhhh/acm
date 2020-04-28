#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

//
// Created by 陈姝宇 on 2020/3/29.
//
class MaxDistance {
    vector<vector<int>> Grid;
    int **p; // record
    int n_maxDistance;
    queue<pair<int, int>> land;
    queue<pair<int, int>> q; // ocean

    void pushQ(int x, int y) {
        if (x < n_maxDistance && 0 <= x && 0 <= y && y < n_maxDistance && p[x][y] == 0) {
            if (Grid[x][y] == 0) { // not visit and is ocean
                q.push(pair<int, int>(x, y));
            } else if (Grid[x][y] == 1) {
                land.push(pair<int, int>(x, y));
            }
        }
    }

    int getDis(int xx, int yy) {
        p[xx][yy] = 2;// land
        int dis = 0;
        land.push(pair<int, int>(xx, yy));
        while (!land.empty()) {
            int x = land.front().first;
            int y = land.front().second;
            land.pop();
            pushQ(x + 1, y);
            pushQ(x - 1, y);
            pushQ(x, y + 1);
            pushQ(x, y - 1);

        }
    }

    int maxDistance(vector<vector<int>> &grid) {
        Grid = grid;
        n_maxDistance = grid.size();
        p = new int *[n_maxDistance];
        for (int i = 0; i < n_maxDistance; i++) {
            p[i] = new int[n_maxDistance];
            memset(p[i], 0, sizeof(int) * n_maxDistance);
        }
        for (int i = 0; i < n_maxDistance; ++i) {
            for (int j = 0; j < n_maxDistance; ++j) {
                if (grid[i][j] == 1) {

                }
            }
        }
    }
};