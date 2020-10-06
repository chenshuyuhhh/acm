#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <string>
#include <cstring>
#include <string.h>
#include <vector>
#include <queue>
#include <set>

using namespace std;
//
// Created by 陈姝宇 on 2020/9/17.
//

class AccomodationOfStudents {
    int n, m;
    vector<int> pairs[201];
//set<int> judgevisit;
    int cur[201];
    int used[201];
    int group[201];

    bool judge() {
        memset(cur, 0, sizeof(int) * (n + 1));

        queue<int> q;
        q.push(1);
        cur[1] = 1;

        while (!q.empty()) {
//        if (q.empty()) {
//            int temp = *judgevisit.begin();
//            q.push(temp);
//            cur[temp] = 1;
//            judgevisit.erase(temp);
//        }
            int node = q.front();
            q.pop();

            vector<int> nexts = pairs[node];
            int color = -cur[node];

            for (int next:nexts) {
                //judgevisit.erase(next);
                if (!cur[next]) {
                    cur[next] = color;
                    q.push(next);
                } else {
                    if (cur[next] != color) return false;
                }
            }
        }
        return true;
    }

    bool judge2(int x, int c) {
        if (cur[x] == 0) {
            cur[x] = c;
            vector<int> nexts = pairs[x];
            for (int next :nexts) {
                if (!judge2(next, -c)) return false;
            }
            return true;
        } else return cur[x] == c;
    }


    bool find(int x) {
        vector<int> nexts = pairs[x];
        for (int next:nexts) {
            if (!used[next]) {
                used[next] = 1;
                if (group[next] == 0 || find(group[next])) {
                    group[next] = x;
                    return true;
                }
            }
        }
        return false;
    }

    int main() {

        int person1, person2;
        while (cin >> n >> m) {
            for (int i = 1; i <= n; ++i) {
                pairs[i].clear();
            }
            //judgevisit.clear();

            for (int i = 1; i <= n; ++i) {
                //judgevisit.insert(i);
            }

            for (int i = 0; i < m; ++i) {
                cin >> person1 >> person2;
                pairs[person1].push_back(person2);
                pairs[person2].push_back(person1);
            }

            memset(cur, 0, sizeof(int) * (n + 1));
            bool isTwo = true;
            if (!judge()) {
                cout << "No" << endl;
                continue;
            }
//        for (int i = 1; i <= n; ++i) {
//            if (cur[i] == 0) {
//                if (!judge2(i, 1)) {
//                    cout << "No" << endl;
//                    isTwo = false;
//                    break;
//                }
//            }
//        }
            if (!isTwo) continue;

            memset(group, 0, sizeof(int) * (n + 1));
            int cnt = 0;
            for (int i = 1; i <= n; ++i) {
                memset(used, 0, sizeof(int) * (n + 1));
                if (find(i)) ++cnt;
            }
            cout << cnt / 2 << endl;
        }

    }
};