#include <iostream>
#include <string>
#include <vector>

using namespace std;

//
// Created by 陈姝宇 on 2020/3/29.
//
int minimumLengthEncoding2(vector<string> &words) {
    vector<string> reserve;
    int length = 0;
    for (string word:words) {
        reverse(word.begin(), word.end());
        reserve.push_back(word);
    }
    sort(reserve.begin(), reserve.end());

    for (int i = 0; i < words.size() - 1; ++i) {
        if (reserve[i + 1].find(reserve[i]) == 0) {

        } else {
            length = length + reserve[i].length() + 1;
        }
    }
    length = length + reserve[words.size() - 1].length() + 1;
    return length;
}