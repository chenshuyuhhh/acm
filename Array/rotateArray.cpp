#include <iostream>
#include <vector>

using namespace std;

//
// Created by 陈姝宇 on 2020/4/7.
//
void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    vector<vector<int>> m;
    for (int j = 0; j < n; ++j) {
        vector<int> m_line;
        for (int i = n - 1; i >= 0; --i) {
            m_line.push_back(matrix[i][j]);
        }
        m.push_back(m_line);
    }
    matrix.assign(m.begin(), m.end());
}