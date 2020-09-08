#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

//
// Created by 陈姝宇 on 2020/6/8.
//

// a==b
// a!=b

// 记录并查集的父
map<char, char> parent;

// 找根节点
char find(char a) {
    while (parent.find(a) != parent.end() && parent[a] != a) {
        parent[a] = parent[parent[a]]; // 压缩路径
        a = parent[a];
    }

    // 说明a没有父节点，那他自己作为父节点
    if (parent.find(a) == parent.end()) parent[a] = a;

    // parent[a] == a
    // 已经找到了父节点，父节点的父节点就是它自己
    return a;
}

void unionChar(char a, char b) {
    char pa = find(a);
    char pb = find(b);
    if (pa != pb) {
        parent[pb] = pa;
    }
    // else 如果相等，那就本来在一个集合，没有必要再合并
}

bool equationsPossible(vector<string> &equations) {
    vector<pair<char, char>> notEqual;
    // 先构建并查集
    for (const auto &equation : equations) {
        string e = equation; // 取出式子
        if (e[1] == '!') notEqual.emplace_back(e[0], e[3]); // 不等式
        else { // 等式
            char a = e[0];
            char b = e[3];
            unionChar(a, b);
        }
    }

    for (auto & it : parent) {
        cout << it.first << " " << it.second << endl;
    }
    // 再根据不等式判断是否有矛盾
    // 不等式不应该在同一个集合中
    for (pair<char, char> ne:notEqual) {
        // 如果父节点是一个，就说明是同一个集合，矛盾
        if (find(ne.first) == find(ne.second)) return false;
    }
    return true;
}

//int main() {
//    vector<string> q = {"f==d", "b!=e", "d!=c", "b==c", "b!=a", "b!=f"};
//    cout << equationsPossible(q);
//}