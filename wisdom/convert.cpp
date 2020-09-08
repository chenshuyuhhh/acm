#include <iostream>
#include <string>
#include <vector>

using namespace std;

//
// Created by 陈姝宇 on 2020/5/12.
//
string convert(string s, int numRows) {
    if (numRows == 0)
        return "";
    if (numRows == 1)
        return s;

    string rows[numRows + 1];
    int nums = 0;
    int l = (numRows - 1) << 1;
    int minl = numRows - 1;
    for (int i = 0; i < s.size(); ++i) {
        rows[nums] += s[i];
        if ((i % l) >= minl)--nums;
        else ++nums;
    }
    string result;
    for (const string &temp:rows) {
        result += temp;
    }
    return result;
}

//int main() {
//    cout << convert("PAYPALISHIRING", 3);
//}