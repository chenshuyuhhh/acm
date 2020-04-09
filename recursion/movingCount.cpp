#include <vector>
#include <iostream>

using namespace std;
//
// Created by 陈姝宇 on 2020/4/8.
//

int movingCount(int m, int n, int k) {
    int n1, n2;
    if (m + n <= k) return ((m + 1) * (n + 1));

    int cnt = 0;
    if (n >= k) n2 = k;
    else {
        n2 = n;
        cnt += (k - n) * (n + 1);
    }
    if (m >= k) n1 = k;
    else {
        n1 = m;
        cnt += (k - m) * (m + 1);
    }
    cnt += ((n2 * n2 - n1 * n1 + 2 * n2 * k + n1 + 3 * n2 - k + 2) >> 1);
    return cnt;
}

int main() {
    cout << movingCount(1, 2, ) << endl;
    // cout << movingCount(3, 1, 0) << endl;
}