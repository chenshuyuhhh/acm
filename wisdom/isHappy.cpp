#include <cmath>
#include <set>
#include <iostream>
using namespace std;
//
// Created by 陈姝宇 on 2020/4/30.
//

int getSum(int n) {
    int sum = 0;
    while (n) {
        sum += pow(n % 10, 2);
        n = n / 10;
    }
    return sum;
}

bool isHappy(int n) {
    set<int> s;
    int sum = n;
    do {
        sum = getSum(sum);
        if (!s.insert(sum).second) {
            break;
        }
    } while (true);

    return sum == 1;
}