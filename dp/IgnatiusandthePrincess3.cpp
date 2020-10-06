#include <iostream>

using namespace std;
//
// Created by 陈姝宇 on 2020/9/21.
//

int n;

int main() {
    while (cin >> n) {
        if (n <= 1) {
            cout << n << endl;
            continue;
        }

        int dp_1 = 1;
        int dp;
        for (int i = 2; i <= n; ++i) {
            dp = dp_1;
            dp += (i >> 1);
            dp_1 = dp;
        }
        cout << dp << endl;
    }
}