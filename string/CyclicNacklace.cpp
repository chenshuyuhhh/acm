#include <iostream>
#include <string.h>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

//
// Created by 陈姝宇 on 2020/9/15.
//

class CyclicNacklace {
    int main() {
        int n;
        cin >> n;

        string str;
        while (n--) {
            cin >> str;

            // 双指针，k指向被匹配的字符串，j指向匹配的字符串
            int k = -1; //  从字符串的开始指，方便对照前缀
            // k=-1,表示和第一个字符匹配，不相等
            int j = 0; // 从字符串开始到尾部，寻找前缀

            int nextArray[100001];
            //memset(nextArray, 0, sizeof(nextArray));
            // 初始化头部
            nextArray[j] = k; // -1表达的意思是，如果和第一个字符匹配，不相等，则j和k都需要移动到下一位
            while (j < str.size()) {
                if (k == -1 || str[k] == str[j]) {
                    // 如果和第一个字符匹配，不相等，or，字符能匹配上
                    // 两个指针都往后移动一位
                    ++k;
                    ++j;
                    // 如果k=-1，则next[j]=-1
                    // 如果是str[k] == str[j]，则表示前面已经有k个字符被匹配上
                    nextArray[j] = k;
                } else {
                    // 不是第一个字符没有匹配上，而是已经匹配了k个字符，然后在j处没有匹配上
                    // j保持不变
                    k = nextArray[k];
                }
            }

            int l = str.size() - nextArray[str.size()];
            if (l != str.size() && str.size() % l == 0) {
                //字符串本身就是一个循环串，且至少 有两个循环节
                cout << 0 << endl;
            } else {
                cout << l - (str.size() % l) << endl;
            }
        }
    }
};