#include <iostream>
#include <string>
#include <set>

using namespace std;

//
// Created by 陈姝宇 on 2020/4/28.
//
int lengthOfLongestSubstring(string s) {
    if (s.length() <= 1)
        return s.length();
    int i = 0;
    int j = 0;
    int length = 0;
    set<char> setChar;
    while (i < s.length() && j < s.length()) {
        for (; j < s.length(); ++j) {
            // insert not successfully
            if (!setChar.insert(s[j]).second) {
                int l = j - i;
                if (l > length) length = l;

                // find position of repeat char
                for (int k = i; k < j; ++k) {
                    if (s[k] == s[j]) {
                        // length
                        i = k + 1; // begin char at the next of repeat char
                        ++j;
                        break;
                    } else {
                        setChar.erase(s[k]);
                    }
                }
                break;
            }
        }
    }
    int ltemp = s.length() - i;
    return max(length, ltemp);
}
