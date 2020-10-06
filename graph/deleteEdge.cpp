#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string.h>
#include <string>
#include <cmath>
#include <set>

using namespace std;

//
// Created by 陈姝宇 on 2020/9/18.
//
class deleteEdge {

    int n;
    int matrix[51][51];
    int dis[51]; // 和0点的距离
    int visit[51];
    long long minDisNums[51];
    set<int> nexts;
    int MaxN = 1000000007;

    void init() {

        string line;
        for (int i = 0; i < n; ++i) {
            cin >> line;
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = line[j] - '0';
            }
        }

        nexts.clear();
        memset(minDisNums, 0, sizeof(minDisNums));
        minDisNums[0] = 1;
        memset(visit, 0, sizeof(visit));
        visit[0] = 1;

        dis[0] = 0;
        for (int k = 1; k < n; ++k) {
            dis[k] = 2147483647;
        }

    }

    int main() {
        while (scanf("%d", &n) != EOF) {
            init();

            int nn = n;
            int begin = 0;
            unsigned long long cnt = 1;

            while (--nn) {
                int mindis = 2147483647;
                // begin line
                for (int i = 0; i < n; ++i) {
                    if (visit[i] == 0 && matrix[begin][i] > 0) {
                        int distance = dis[begin] + matrix[begin][i];
                        if (distance < dis[i]) {
                            dis[i] = distance;
                            nexts.insert(i);
                        }
                    }
                }
                // find next begin
                for (int next:nexts) {
                    if (dis[next] < mindis) {
                        mindis = dis[next];
                        begin = next;
                    }
                }
                visit[begin] = 1;
                nexts.erase(begin);
            }

            for (int j = 1; j < n; ++j) {
                for (int i = 0; i < n; ++i) {
                    if (matrix[j][i] > 0 && matrix[j][i] + dis[i] == dis[j]) {
                        ++minDisNums[j];
                    }
                }
                minDisNums[j] = minDisNums[j] % MaxN;
                cnt *= minDisNums[j];
                cnt = cnt % MaxN;
            }

            cout << cnt % MaxN << endl;
        }
    }
};