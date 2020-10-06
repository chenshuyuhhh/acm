#include <iostream>
#include <string.h>
#include <cstring>
#include <string>
#include <set>

using namespace std;

//
// Created by 陈姝宇 on 2020/9/17.
//
// 1281
class class1281 {
    int graph[101][101];
    int pairs[210];
    int used[210];
    int N, M, K;

    bool find(int x) {
        for (int i = 1; i <= M; ++i) {
            if (graph[x][i] && !used[i]) {
                used[i] = 1;
                if (pairs[i] == 0 || find(pairs[i])) {
                    pairs[i] = x;
                    return true;
                }
            }
        }
        return false;
    }

    int main() {
        int t = 0;

        while (scanf("%d%d%d", &N, &M, &K) != EOF) {
            ++t;
            // init
            memset(graph, 0, sizeof(graph));
            memset(pairs, 0, sizeof(pairs));

            int hang, lie;
            while (K--) {
                cin >> hang >> lie;
                graph[hang][lie] = 1;
            }

            int cnt = 0;

            for (int i = 1; i <= N; ++i) {
                memset(used, 0, sizeof(used));
                if (find(i)) ++cnt;
            }


            int important = 0;
            for (int i = 1; i <= N; ++i) {
                for (int k = 1; k <= M; ++k) {
                    if (graph[i][k] == 1) {
                        graph[i][k] = 0;
                        memset(pairs, 0, sizeof(pairs));

                        int cnttemp = 0;
                        for (int j = 1; j <= N; ++j) {
                            memset(used, 0, sizeof(used));
                            if (find(j)) ++cnttemp;
                        }

                        if (cnttemp < cnt) ++important;

                        graph[i][k] = 1;
                    }
                }
            }
            cout << "Board " << t << " have " << important << " important blanks for " << cnt << " chessmen." << endl;
        }
    }
};
