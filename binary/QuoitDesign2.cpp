//
// Created by 陈姝宇 on 2020/9/20.
//

#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>

using namespace std;

class QuoitDesign {
    static const int MAXN = 100001;

    struct point {
        double x;
        double y;

        point() {}

        point(double x, double y) : x(x), y(y) {}
    };

    point node[MAXN];
    point py[MAXN]; //在getDis2函数中使用，筛选中线上下dis2范围的点
    static bool cmpx(point a, point b) {
        return a.x < b.x;
    }

    static bool cmpy(point a, point b) {
        return a.y < b.y;
    }

    static double calDis2(point a, point b) {
        double dis2 = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
        return dis2;
    }

    double getDis2(int left, int right) {
        double dis2 = 0;
        if (left == right) return 0;
        if (right == left + 1)
            return calDis2(node[right], node[left]);
        if (right == left + 2) //如果是三个点，直接计算了，就不放在递归里了麻烦。
            return min(calDis2(node[right], node[left]),
                       min(calDis2(node[left + 1], node[left]), calDis2(node[right],
                                                                        node[left + 1])));
        int mid = left + ((right - left) >> 1);
        dis2 = min(getDis2(left, mid), getDis2(mid, right));
        //左右半边的内部距 离，取最小的
        //选取中线横坐标左右dis2距离的点，并按y的升序排序
        int cnt = 0;
        for (int i = left; i <= right; i++) {
            if (node[i].x >= node[mid].x - dis2 && node[i].x <= node[mid].x + dis2) py[cnt++] = node[i];
        }
        sort(py, py + cnt, cmpy);
        for (int i = 0; i < cnt; i++) {
            for (int j = i + 1; j < cnt; j++) {
                if (py[j].y - py[i].y > dis2)
                    break;
                dis2 = min(dis2, calDis2(py[j], py[i]));
            }
        }
        return dis2;
    }

    int mainQD() {
        int n;
        while (cin >> n && n) {
            double x, y;
            for (int i = 0; i < n; i++) {
                scanf("%lf%lf", &x, &y);
                node[i] = point(x, y);
            } //按x的升序排序

            sort(node, node + n, cmpx);
            double minx = getDis2(0, n - 1);
            minx = sqrt(minx) / 2;
            printf("%.2f\n", minx);
        }

        return 0;
    }
};