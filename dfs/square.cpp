#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

//
// Created by 陈姝宇 on 2020/9/18.
//
class square {
    int l[25];
    int length;
    int visit[25];
    int m;

    static bool cmp(int a, int b) {
        return a > b;
    }

    bool find(int pos, int sum, int cnt) {
        if (cnt == 3) return true;

        if (sum == length) {
            return find(0, 0, cnt + 1);
        }

        for (int j = pos; j < m; ++j) {
            // 长度过长，已经用过，就不行
            if (sum + l[j] > length || visit[j])continue;
            else {
                visit[j] = 1;
                if (find(j, sum + l[j], cnt)) return true;
                visit[j] = 0;
            }
        }
        return false;
    }

    int main() {
        int n;
        cin >> n;
        while (n--) {
            memset(visit, 0, sizeof(visit));
            cin >> m;
            int sum = 0;
            for (int i = 0; i < m; ++i) {
                cin >> l[i];
                sum += l[i];
            }
            sort(l, l + m, cmp);
            length = sum / 4;

            if (sum % 4 != 0 || l[m - 1] > length) {
                cout << "no" << endl;
                continue;
            }

            if (find(0, 0, 0)) {
                cout << "yes" << endl;
            } else cout << "no" << endl;
        }
    }
};