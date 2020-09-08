#include <string>
#include <queue>
#include <map>
#include <iostream>

using namespace std;
//
// Created by 陈姝宇 on 2020/5/23.
//

// Input: S = "ADOBECODEBANC", T = "ABC"
// Output: "BANC"
string minWindow(string s, string t) {
    queue<pair<int, char>> q;
    int size = t.size();
    map<char, int> m;

    for (int j = 0; j < size; ++j) {
        // 统计字符数
        if (m.find(t[j]) == m.end()) m[t[j]] = 1;
        else ++m[t[j]];
    }

    // 使用滑动窗口遍历
    int right = 0;
    // 在s中找到的字符数
    map<char, int> longm;
    char temp;
    int d = 0;
    int minl = INT32_MAX;
    int r = 0;
    int l = 0;
    while (right < s.size()) {
        temp = s[right];
        if (m.find(temp) != m.end()) { //找到了
            // 加入队列
            q.push(pair<int, char>(right, s[right]));

            // 记录是否找齐
            if (m.find(temp) == m.end()) longm[temp] = 1;
            else ++longm[temp];

            // 比需要的字符数少才能加
            if (longm[temp] <= m[temp]) ++d;

            // 已全部找到
            if (d == size) { // 开始左移动
                char leftchar = q.front().second;
                while (longm[leftchar] > m[leftchar]) { // 有多的，就可以下一个
                    // 出队
                    q.pop();
                    // 更新已找到字符数
                    --longm[leftchar];
                    // 再次访问对头
                    leftchar = q.front().second;
                }
                // 计算距离
                int templ = right - q.front().first + 1;
                // 更新最小距离
                if (templ < minl) {
                    minl = templ;
                    l = q.front().first;
                    r = right;
                }
                // 出队，更新
                --longm[leftchar];
                q.pop();
                // 很容易忘记更新
                --d;
            }
        }

        // 没有找到，找下一个
        ++right;
    }
    if (minl == INT32_MAX) return "";
    return s.substr(l, minl);
}
//
//int main() {
//    string s = "abc", t = "b";
//    cout << minWindow(s, t);
//}