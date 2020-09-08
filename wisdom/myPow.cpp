#include <map>
#include <iostream>

using namespace std;
//
// Created by 陈姝宇 on 2020/5/11.
//

// Implement pow(x, n),
// which calculates x raised to the power n (xn).
double myPow(double x, int n) {
    if (x == 0 || x == 1) return x;
    if (n == 0)
        return 1;
    else if (n == 1)
        return x;

    // 记录是否是正数
    bool ifPos = true;
    if (n < 0) { // 负数
        ifPos = false;
        n = 0 - n;
    }

    // 记录每次平方的结果
    double result = x;
    int k = 2; // 次方数

    map<int, double> value;
    value[1] = x;// 初始化，一次方的情况
    while (k <= n) {
        result = result * result;
        value[k] = result;
        k *= 2;
    }
    // 回退k
    k = k / 2;
    // 剩余的平方数
    int dif = n - k;
    while (dif != 0) {
        if (dif >= k) { // 够减去
            result = result * value[k];
            dif = dif - k;
        } else { // 不够，就继续缩小k
            k = k / 2;
        }
    }
    if (ifPos)return result;
    else return 1.0 / result;
}

//int main() {
//    cout << myPow(0.00001, 2147483647);
//}