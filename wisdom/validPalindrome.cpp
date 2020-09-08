#include <map>
#include <iostream>

using namespace std;
//
// Created by 陈姝宇 on 2020/5/19.
//

bool validPalindrome(string s) {
    int l = s.size() / 2;
    int size = s.size() - 1;
    int i;
    for (i = 0; i < l; ++i) {
        if (s[i] != s[size - i]) {
            break;
        }
    }
    if (i == l) return true;
    if (s.size() % 2 == 0) {
        // 奇数个数，是不会变的
        // 偶数少一个比较字符
        --l;
    }

    // 删掉右边的数字
    size = size - 1;
    int temp_i = i;
    for (; temp_i < l; ++temp_i) {
        if (s[temp_i] != s[size - temp_i]) {
            break;
        }
    }
    if (temp_i == l) return true;
    // 删掉左边的数字
    // 整体右移
    size = size + 2; //恢复size
    temp_i = i + 1;
    ++l;
    for (; temp_i < l; ++temp_i) {
        if (s[temp_i] != s[size - temp_i]) {
            break;
        }
    }
    return temp_i == l;
}

int main680() {
    cout << validPalindrome("deeee");
}