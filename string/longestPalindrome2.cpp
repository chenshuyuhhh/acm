#include <iostream>
#include <string.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

//
// Created by 陈姝宇 on 2020/9/15.
//


// 马拉车算法的本质：
// 根据回文对称性
// 已经有发现了长回文，那么包含在长回文中的左边的短回文在右边肯定也是短回文。

class longestPalindrome2 {
    static const int MAXN = 110005;
    int table[MAXN * 2];
    char s[MAXN * 2];
    string str;
    string newStr;

/*
newStr的构成不仅仅是加个# 应该给原串加完#后，
再在首尾加上不一样的两个符号比如 str = 12321
newStr = #1#2#3#2#1# 如果首尾一样，会出错!!!!!
*/

    void preProcess() {
        //fill(table, table + MAXN, 1);
        newStr = string(2 * str.length() + 3, '#');
        newStr[0] = '$';

        for (int i = 0, j = 2; i < str.size(); ++i, j += 2) {
            newStr[j] = str[i];
        }
        newStr[newStr.size() - 1] = '^';
    }

    int main() {
        while (scanf("%s", s) != EOF) {
            str = s;
            preProcess();

            int maxl = -1;

            int l = newStr.size() - 1;

            int r = 0; // 右边界
            int c = 0; // 指向中心
            table[0] = 0;

            for (int i = 1; i < l; ++i) {
                // i以c为中心对应的对称点
                // int i_mirror = c * 2 - i;

                // 是否可以用右边界
                if (r > i) {
                    table[i] = min(table[c * 2 - i], r - i);
                } else { // 不在已经求出的回文内部，不能重复利用之前的信息
                    table[i] = 0;
                }

                // 中心扩展，寻找回文
                // 这里用table[i]是可能，已有的信息不全，还需要往后继续判断
                while (newStr[i + table[i] + 1] == newStr[i - table[i] - 1]) {
                    ++table[i];
                }

                // 是否需要更新右边界和中心点
                if (i + table[i] > r) {
                    r = i + table[i];
                    c = i;
                }

                maxl = max(table[i], maxl);
            }
            cout << maxl << endl;
        }

        return 0;
    }
};