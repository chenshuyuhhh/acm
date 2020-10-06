#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <cstring>
#include <algorithm>

using namespace std;

//
// Created by 陈姝宇 on 2020/9/14.
//


int *getChildNums(vector<int> matrix[], int n) {
    queue<int> q;
    q.push(1);

    int visit[n + 1];
    memset(visit, 0, sizeof(visit));
    visit[1] = 1;

    int *result = new int[n + 1];
    for (int i = 0; i < n + 1; ++i) {
        result[i] = 0;
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        vector<int> childs = matrix[node];
        for (int child:childs) {
            if (!visit[child]) {
                ++result[node];
                q.push(child);
                visit[child] = 1;
            }
        }
    }
    return result;
}

int mainTest1() {
    int n, m;
    cin >> n;
    int nodes1[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> nodes1[i];
    }

    vector<int> matrix1[n + 1];

    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        matrix1[a].push_back(b);
        matrix1[b].push_back(a);
    }
    int *childs1 = getChildNums(matrix1, n);

    cin >> m;
    int nodes2[m + 1];

    for (int j = 1; j <= m; ++j) {
        cin >> nodes2[j];
    }

    vector<int> matrix2[m + 1];
    for (int i = 0; i < m - 1; ++i) {
        cin >> a >> b;
        matrix2[a].push_back(b);
        matrix2[b].push_back(a);
    }
    int *childs2 = getChildNums(matrix2, m);

    int sum;
    cin >> sum;

    bool has = false;
    for (int i = 1; i <= n; ++i) {
        int num1 = nodes1[i];
        for (int j = 1; j <= m; ++j) {
            int num2 = nodes2[j];
            if (num1 + num2 == sum && childs1[i] == 2 && childs2[j] == 2) {
                cout << i << " " << j << endl;
                has = true;
            }
        }
    }
    if (!has) cout << -1 << endl;

}