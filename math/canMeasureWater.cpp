#include <iostream>

using namespace std;

//
// Created by 陈姝宇 on 2020/3/22.
//
bool canMeasureWater2(int x, int y, int z) {
    if (x + y < z)return false;
    if (x == 0 || y == 0)return z == 0 || x + y == z;
    int rev = x % y;
    while (rev != 0) {
        x = y;
        y = rev;
        rev = x % y;
    }
    return z % y == 0;
}