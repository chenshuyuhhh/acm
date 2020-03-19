#include <iostream>
#include <string>
#include <string.h>

using namespace std;
//
// Created by 陈姝宇 on 2020/3/12.
//

int mainMergeString() {
    string S = "aaabbbc";
    string result = "";
    for (int i = 0; i < S.size(); i++) {
        char c = S.at(i);
        int num = 1;
        for (i = i + 1; i < S.size(); i++) {
            char temp = S.at(i);
            if (temp != c) {
                --i;
                break;
            } else {
                ++num;
            }
        }
        result.append(c + to_string(num));
    }
    cout << result;
    return 0;
}
