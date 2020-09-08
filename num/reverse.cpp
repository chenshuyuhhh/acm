#include <iostream>

using namespace std;
//
// Created by 陈姝宇 on 2020/5/11.
//

int reverse(int x) {
    int sum = 0;
    int digit;
    while (x) {
        // 取个位数
        digit = x % 10;
        // 大于INT的最大值
        if ((sum > INT32_MAX / 10) || ((sum == INT32_MAX / 10) && digit > 7))return 0;
        if ((sum < INT32_MIN / 10) || ((sum == INT32_MIN / 10) && digit < -8))return 0;
        sum = sum * 10 + digit;
        x = x / 10;
    }
    return sum;
}

//int main() {
//    // cout << reverse(100);
//    cout << reverse(-1463847412);
//    // -2147483648
//    // -2147483641
//}