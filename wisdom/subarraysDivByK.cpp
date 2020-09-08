#include <vector>
#include <map>
#include <iostream>

using namespace std;

//
// Created by 陈姝宇 on 2020/5/27.
//
int subarraysDivByK(vector<int> &A, int K) {
    map<int, int> m;
    int sum = 0;
    int num = 0;
    int rev = 0;
    m.insert(pair<int, int>(sum, 1));
    for (int i : A) {
        // 计算前缀值
        sum += i;
        // 计算余数,为了考虑负数情况
        rev = (sum % K + K) % K;
        // 找同余
        num += m[rev];
        // 更新同余
        ++m[rev];
    }
    return num;
}

//int main() {
//    vector<int> a = {-1, 2, 9};
//    cout << subarraysDivByK(a, 2);
//}