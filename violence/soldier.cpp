#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <list>
#include <string.h>
#include <cstring>
#include <string>

using namespace std;

//
// Created by 陈姝宇 on 2020/9/13.
//

class soldier {
    int main() {
        int n;
        cin >> n;
        int cnt;
        //vector<vector<int>> result;

        for (int j = 0; j < n; ++j) {
            cin >> cnt;

            list<int> l;
            vector<int> v;

            for (int i = 1; i <= cnt; ++i) {
                l.push_back(i);
            }

            if (cnt <= 3) {
                for (int i = 1; i < cnt; ++i) {
                    cout << i << " ";
                }
                cout << cnt << endl;
                //result.push_back(v);
                continue;
            }

            bool isTwo = true;
            while (l.size() >= 6) {
                if (isTwo) {
                    isTwo = false;
                    auto it = l.begin();
                    ++it;
                    int size = (l.size() >> 1);
                    while (size--) {
                        it = l.erase(it);
                        ++it;
                    }
                } else {
                    isTwo = true;
                    auto it = l.begin();
                    ++it;
                    ++it;
                    int size = l.size() / 3;
                    while (size--) {
                        it = l.erase(it);
                        ++it;
                        ++it;
                    }
                }
            }

            while (l.size() > 3) {
                if (isTwo) {
                    isTwo = false;
                    auto it = l.begin();
                    ++it;
                    int size = (l.size() >> 1);
                    while (size--) {
                        it = l.erase(it);
                        if (l.size() == 3) break;
                        ++it;
                    }
                } else {
                    isTwo = true;
                    auto it = l.begin();
                    ++it;
                    ++it;
                    int size = l.size() / 3;
                    while (size--) {
                        it = l.erase(it);
                        if (l.size() == 3) break;
                        ++it;
                        ++it;
                    }
                }
            }

            for (auto it = l.begin(); it != l.end(); ++it) {
                v.push_back(*it);
            }

            cout << v[0] << " " << v[1] << " " << v[2] << endl;
        }
    }
};