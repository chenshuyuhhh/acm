#include <vector>
#include <string>
#include <set>
#include <map>
#include <iostream>

using namespace std;
//
// Created by 陈姝宇 on 2020/5/20.
//

int findTheLongestSubstring(string s) {
    vector<int> pos(1 << 6, -1);
    //  'a', 'e', 'i', 'o', 'u'
    int state = 0;
    int maxl = 0;
    for (int i = 0; i < s.size(); ++i) {
        char temp = s[i];
        switch (temp) {
            case 'a':
                state ^= 1 << 5;
                break;
            case 'e':
                state ^= 1 << 4;
                break;
            case 'i':
                state ^= 1 << 3;
                break;
            case 'o':
                state ^= 1 << 2;
                break;
            case 'u':
                state ^= 1;
                break;
        }
        if (pos[state] != -1 || state == 0) { // 存在奇偶相同
            maxl = max(maxl, i - pos[state]);
        } else { // 不存在，就说明是最早的
            pos[state] = i;
        }
    }
    return maxl;
}

//int main() {
//    cout << findTheLongestSubstring("bcbcbc");
//}