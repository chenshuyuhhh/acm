#include <iostream>
#include <string.h>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;


//
// Created by 陈姝宇 on 2020/9/15.
//

class cutFlow {
    static const int MAXINT = 1001;
    int nextJ[MAXINT];

    int main() {
        string bigStr, littleStr;
        while (cin >> bigStr) {
            if (bigStr == "#") {
                break;
            }
            cin >> littleStr;

            // 构造next数组
            int k = -1; // -1 是为了++j之后就是从0开始
            int j = 0;
            nextJ[j] = k;
            while (j < littleStr.size()) {
                if (k == -1 || littleStr[k] == littleStr[j]) {
                    ++k;
                    ++j;
                    nextJ[j] = k;
                } else {
                    k = nextJ[k];
                }
            }

            // 使用KMP算法
            int i = 0; // -> bigStr
            j = 0; // -> littleStr
            int cnt = 0;
            while (i < bigStr.size()) {
                if (j == -1 || bigStr[i] == littleStr[j]) {
                    ++i;
                    ++j;
                } else {
                    j = nextJ[j];
                }
                if (j == littleStr.size()) {
                    ++cnt;
                    j = 0;
                }
            }
            cout << cnt << endl;
        }
        return 0;
    }
};