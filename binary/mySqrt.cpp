#include <iostream>

//
// Created by 陈姝宇 on 2020/4/2.
//
int mySqrt(int x) {
    long high = (x >> 1) + 1;
    long low = 0;
    long mid = (low + high) >> 1;
    while (low <= high) {
        if (mid * mid == x) return mid;
        else if (mid * mid > x) {
            if ((mid - 1) * (mid - 1) <= x)return mid - 1;
            high = mid - 1;
        } else {
            if ((mid + 1) * (mid + 1) > x)return mid;
            low = mid + 1;
        }
        mid = (high + low) >> 1;
    }
}

int main704() {
    // std::cout << mySqrt(4);
    std::cout << mySqrt(2147483647);
}