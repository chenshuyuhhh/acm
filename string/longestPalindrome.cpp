#include <iostream>
#include <string>
#include <map>

using namespace std;

//
// Created by 陈姝宇 on 2020/3/19.
//
// 给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
// 在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。

int longestPalindromeString(string s) {
    int result = 0;

    map<char, int> m; // Count characters and number of characters
    for (int i = 0; i < s.size(); i++) {
        m[s.at(i)] = m[s.at(i)] + 1;
    }

    int hasOdd = false; // Record whether odd number has occurred
    map<char, int>::iterator iter;
    for (iter = m.begin(); iter != m.end(); ++iter) {
        result += ((iter->second >> 1) << 1); // second / 2 * 2
        if (iter->second % 2 != 0 && !hasOdd) {
            hasOdd = true; // odd has occurred
            ++result; // Only an odd number of characters can appear in palindrome
        }
    }
    return result;
}

int main409() {
    string s = "abccccdd";
    cout << longestPalindromeString(s);
}