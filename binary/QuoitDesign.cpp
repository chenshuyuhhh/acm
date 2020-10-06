#include <iostream>
#include <cstring>
#include <string.h>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

//
// Created by 陈姝宇 on 2020/9/20.
//
class QuoitDesign {
    static int n;
    static const int MAXN = 100001;

    struct Node {
        double x;
        double y;

        Node() {};

        Node(double x, double y) : x(x), y(y) {}
    };

    Node nodes[MAXN];
    Node cands[MAXN];

    static bool cmpX(Node n1, Node n2) {
        return n1.x < n2.x;
    }

    static bool cmpY(Node n1, Node n2) {
        return n1.y < n2.y;
    }

    static double getDis(Node n1, Node n2) {
        double dis2 = (n1.x - n2.x) * (n1.x - n2.x) + (n1.y - n2.y) * (n1.y - n2.y);
        return dis2;
    }

    double minDis(int left, int right) {
        if (left == right) return 0;

        if (left + 1 == right) {
            return getDis(nodes[left], nodes[right]);
        }

        if (left + 2 == right) {
            return min(min(getDis(nodes[left], nodes[right]),
                           getDis(nodes[left], nodes[left + 1])),
                       getDis(nodes[left + 1], nodes[right]));
        }

        int mid = left + ((right - left) >> 1);
        double dis = min(minDis(left, mid), minDis(mid, right));

        int cnt = 0;
        for (int i = left; i <= right; ++i) {
            if (nodes[i].x >= nodes[mid].x - dis && nodes[i].x <= nodes[mid].x + dis) cands[cnt++] = nodes[i];
        }

        sort(cands, cands + cnt, cmpY);

        for (int i = 0; i < cnt; ++i) {
            for (int j = i + 1; j < cnt; ++j) {
                if (cands[j].y - cands[i].y > dis)
                    break;
                dis = min(dis, getDis(cands[i], cands[j]));
            }
        }

        return dis;
    }

    int main() {

        while (cin >> n && n) {
            double x, y;

            for (int i = 0; i < n; ++i) {
                scanf("%lf%lf", &x, &y);
                nodes[i] = Node(x, y);
            }

            sort(nodes, nodes + n, cmpX);

            double r = minDis(0, n - 1);
            r = sqrt(r) / 2.0;

            printf("%0.2lf\n", r);
        }

        return 0;
    }
};