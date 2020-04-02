#include <iostream>
#include <string>
#include <vector>

using namespace std;

//
// Created by 陈姝宇 on 2020/3/28.
// 820
int minimumLengthEncoding(vector<string> &words) {
    int size = words.size();
    int p[words.size()];
    memset(p, 0, sizeof(p));
    int l = 0;
    for (int i = 0; i < size; ++i) {
        if (p[i] == 1) continue;
        int i_size = words[i].size();
        l = l + i_size + 1;

        for (int j = i + 1; j < size; ++j) {
            int j_size = words[j].size();
            if (i_size > j_size) {
                // j is end substr of i
                if (words[j] == words[i].substr(i_size - j_size, i_size))
                    p[j] = 1;
            } else if (i_size == j_size) {
                if (words[i] == words[j]) p[j] = 1;
            } else {
                if (words[i] == words[j].substr(j_size - i_size, j_size)) {
                    l = l - i_size - 1;
                    break;
                }
            }
        }
    }
    return l;
}

int main820() {
    vector<string> sts = {"time", "atime", "btime"};
    cout << minimumLengthEncoding(sts);
}