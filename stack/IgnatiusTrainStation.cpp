#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <string.h>

using namespace std;
//
// Created by 陈姝宇 on 2020/9/13.
//

// 3 123 321
// 3 123 312
int lgnatiusTrainStation() {
    int n;
    while (cin >> n) {
        string in, out;
        cin >> in >> out;

        stack<char> s;

        int j = 0;
        int i = 0;
        vector<string> v;
        while (j < n) {
            if (!s.empty() && s.top() == out[j]) {
                v.emplace_back("out");
                s.pop();
                ++j;
            } else {
                while (i < n && in[i] != out[j]) {
                    v.emplace_back("in");
                    s.push(in[i]);
                    ++i;
                }
                if (i < n) {
                    v.emplace_back("in");
                    s.push(in[i]);
                    ++i;
                } else break;
            }
        }
        if (v.size() < n * 2) {
            cout << "No." << endl;
        } else {
            cout << "Yes." << endl;
            for (const auto &k : v) {
                cout << k << endl;
            }
        }
        cout << "FINISH" << endl;
    }
}

