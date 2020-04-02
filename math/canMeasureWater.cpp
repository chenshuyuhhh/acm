#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>

using namespace std;

//
// Created by 陈姝宇 on 2020/3/22.
//
int x;
int y;
int z;
bool result = false;

set<pair<int, int>> s;

void op2(int c1, int c2) {
    if (result) return;
    if (c1 == z || c2 == z || c1 + c2 == z) {
        result = true;
        return;
    }
    // both full or clear
    // if ((c1 == x && c2 == y) || (c1 == 0 && c2 == 0)) return;
    if (s.find(make_pair(c1, c2)) != s.end()) return;
    s.insert(make_pair(c1, c2));
    // op1:
    if (c1 < x) op2(x, c2); // c1 if full
    if (c2 < y) op2(c1, y); // c2 if full
    // op2:
    if (c1 > 0) op2(0, c2); // c1 is cleared
    if (c2 > 0) op2(c1, 0); // c2 is cleared
    // op3:
    // c1 to c2
    if (c2 < y && c1 > 0) { // c2 is not full
        if (c1 <= y - c2) op2(0, c2 + c1); // c1 is cleared
        else op2(c1 - y + c2, y); // c2 is full
    }
    // c2 to c1
    if (c1 < x && c2 > 0) { // c1 is not full
        if (c2 <= x - c1) op2(c1 + c2, 0); // c1 is cleared
        else op2(x, c2 - x + c1); // c2 is full
    }
    return;
}

//op1 装满任意一个水壶
//op2 清空任意一个水壶
//op3 从一个水壶向另外一个水壶倒水，直到装满或者倒空
void op(int c1, int c2) {
    if (result) return;
    if (c1 == z || c2 == z || c1 + c2 == z) {
        result = true;
        return;
    }
    // both full or clear
    // if ((c1 == x && c2 == y) || (c1 == 0 && c2 == 0)) return;
    if (s.find(make_pair(c1, c2)) != s.end()) return;
    s.insert(make_pair(c1, c2));
    // op1:
    if (c1 < x) op(x, c2); // c1 if full
    if (c2 < y) op(c1, y); // c2 if full
    // op2:
    if (c1 > 0) op(0, c2); // c1 is cleared
    if (c2 > 0) op(c1, 0); // c2 is cleared
    // op3:
    // c1 to c2
    if (c2 < y && c1 > 0) { // c2 is not full
        if (c1 <= y - c2) op(0, c2 + c1); // c1 is cleared
        else op2(c1 - y + c2, y); // c2 is full
    }
    // c2 to c1
    if (c1 < x && c2 > 0) { // c1 is not full
        if (c2 <= x - c1) op(c1 + c2, 0); // c1 is cleared
        else op(x, c2 - x + c1); // c2 is full
    }
    return;
}

bool canMeasureWater2(int X, int Y, int Z) {
    x = X;
    y = Y;
    z = Z;
    // 本身等于
    if (x == Z || y == Z || x + y == Z) return true;
    s.insert(make_pair(0, 0));
    op2(x, 0);
    op2(0, y);
}

bool canMeasureWater(int x, int y, int z) {
    // 本身等于
    if (x == z || y == z || x + y == z) return true;
    stack<pair<int, int>> q;
    //set<pair<int, int>> m_set;
    q.push(make_pair(0, 0));
    while (!q.empty()) {
        pair<int, int> q_front = q.top();
        q.pop();
        int c1 = q_front.first;
        int c2 = q_front.second;
        if (c1 == z || c2 == z || c1 + c2 == z) {
            return true;
        }
        if (s.find(make_pair(c1, c2)) != s.end()) continue;
        s.insert(make_pair(c1, c2));
        if (c1 < x) q.push(make_pair(x, c2)); // c1 if full

        if (c2 < y) q.push(make_pair(c1, y)); // c2 if full
        // op2:
        if (c1 > 0) q.push(make_pair(0, c2)); // c1 is cleared
        if (c2 > 0) q.push(make_pair(c1, 0)); // c2 is cleared
        // op3:
        // c1 to c2
        if (c2 < y && c1 > 0) { // c2 is not full
            if (c1 <= y - c2)
                q.push(make_pair(0, c2 + c1)); // c1 is cleared
            else q.push(make_pair(c1 - y + c2, y)); // c2 is full
        }
        // c2 to c1
        if (c1 < x && c2 > 0) { // c1 is not full
            if (c2 <= x - c1)
                q.push(make_pair(c1 + c2, 0)); // c1 is cleared
            else q.push(make_pair(x, c2 - x + c1)); // c2 is full
        }
    }
    return false;
}

int main365() {
    // 22003
    //31237
    //123
    cout << canMeasureWater(104639, 104651, 234);
    // cout << result;
    //  cout << canMeasureWater(2, 6, 5);
}