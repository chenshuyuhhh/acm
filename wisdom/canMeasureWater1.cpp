#include <set>
#include <stack>
#include <iostream>
#include <unordered_set>

using namespace std;
//
// Created by 陈姝宇 on 2020/5/16.
//

using PII = pair<int, int>;

bool canMeasureWater(int x, int y, int z) {
    // 记录下倒水的状态，避免重复
    auto hash_function = [](const PII &o) { return hash<int>()(o.first) ^ hash<int>()(o.second); };
    unordered_set<PII, decltype(hash_function)> state(0, hash_function);

    // 深度遍历
    stack<PII> q;
    q.emplace(0, 0); // 初始化

    while (!q.empty()) {
        if (state.count(q.top())) { // 已有
            // 别忘了取出来
            q.pop();
            continue;
        }
        // 没有则添加
        state.emplace(q.top());
        // 取出队头
        int x_temp = q.top().first;
        int y_temp = q.top().second;
        q.pop();
        if (x_temp == z || y_temp == z || (x_temp + y_temp) == z)return true;

        // fill x
        q.emplace(x, y_temp);
        // fill y
        q.emplace(x_temp, y);
        // empty x
        q.emplace(0, y_temp);
        // empty y
        q.emplace(x_temp, 0);
        // x to y
        q.emplace(max(0, x_temp + y_temp - y), min(x_temp + y_temp, y));
        // y to x
        q.emplace(min(x_temp + y_temp, x), max(0, x_temp + y_temp - x));
    }

    return false;
}

//int main() {
////    104659
////    104677
////    142424
//
//    cout << canMeasureWater(2, 6, 5);
//    cout << canMeasureWater(104707, 104711, 1);
//    // cout << canMeasureWater(2, 6, 5);
//}