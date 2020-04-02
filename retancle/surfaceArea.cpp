#include <vector>
#include <iostream>

using namespace std;

//
// Created by 陈姝宇 on 2020/3/25.
//
int surfaceArea(vector<vector<int>> &grid) {
    int n = grid.size();
    int sidearea = 0; // side area
    if (n == 1) {
        if (grid[0][0] == 0) return 0;
        else return (grid[0][0] << 2) + 2;
    }
    for (int i = 0; i < n; i++) {
        sidearea += grid[i][0] + grid[i][n - 1] + grid[0][i] + grid[n - 1][i];
        for (int j = 0; j < n - 1; ++j) {
            if (grid[i][j] > 0) sidearea += 2; // top and down
            sidearea += abs(grid[i][j + 1] - grid[i][j]); // front and behind
            sidearea += abs(grid[j + 1][i] - grid[j][i]); // left and right
        }
        if (grid[i][n - 1] > 0) sidearea += 2; // top and down
    }
    return sidearea;
}

int main892() {
    vector<vector<int>> grid = {{2}};
    cout << surfaceArea(grid);
}