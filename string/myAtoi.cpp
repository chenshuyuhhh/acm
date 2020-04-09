#include <iostream>
#include <string>
#include <map>

using namespace std;
//
// Created by 陈姝宇 on 2020/4/3.
//

int myAtoi(string str) {
    int result = 0;
    int p = 0;
    bool isn = false;
    for (int i = 0; i < str.size(); ++i) {
        char ch = str[i];
        if (48 <= ch && ch <= 57) {
            p = i;
            break;
        } else if ((ch == '-' || ch == '+') && i + 1 < str.size() && (48 <= str[i + 1] && str[i + 1] <= 57)) {
            p = i + 1;
            isn = (ch == '-');
            break;
        } else if (ch == ' ') continue;
        else return 0;
    }
    int n = 10;
    if (isn) {
        for (int i = 0; i + p < str.size(); ++i) {
            if (48 <= str[p + i] && str[p + i] <= 57) {
                int digit = (int) (str[p + i] - 48);
                if (i >= 8 && result * 1.0 < (INT32_MIN + digit) * 1.0 / n)
                    return INT32_MIN;
                result = result * n - digit;
            } else break;
        }
    } else {
        for (int i = 0; i + p < str.size(); ++i) {
            if (48 <= str[p + i] && str[p + i] <= 57) {
                int digit = (int) (str[p + i] - 48);
                if (i >= 8 && result * 1.0 > (INT32_MAX - digit) * 1.0 / n)
                    return INT32_MAX;
                result = result * n + digit;
            } else break;
        }
    }
    return result;
}
//
//int main() {
////    cout << myAtoi("   -42") << endl;
////    cout << myAtoi("42") << endl;
////    cout << myAtoi("4193 with words") << endl;
////    cout << myAtoi("words and 987") << endl;
//    cout << myAtoi("-91283472332") << endl;
//}