#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;
//
// Created by 陈姝宇 on 2020/5/18.
//

vector<int> findOrder2(int numCourses, vector<vector<int>> &prerequisites) {
    if (numCourses == 0)
        return {};
    // 记录0入度的队列
    queue<int> q;

    // 记录邻接矩阵
    vector<int> matrix[numCourses];

    // 记录入度
    int degree[numCourses];
    memset(degree, 0, sizeof(degree));
    //  记录一开始的0入度结点
    set<int> starts;
    for (int i = 0; i < numCourses; ++i) {
        starts.insert(i);
    }

    // 找出邻接矩阵
    for (vector<int> prerequisite:prerequisites) {
        // 更新邻接矩阵
        matrix[prerequisite[1]].push_back(prerequisite[0]);
        // 更新入度
        degree[prerequisite[0]] += 1;
        // 已有入度，不能作为开始结点
        starts.erase(prerequisite[0]);
    }
    // 将一开始入度为0的点加入队列
    for (int start:starts) {
        q.push(start);
    }

    vector<int> result;
    while (!q.empty()) {
        // 取出头结点，加入结果
        int front = q.front();
        q.pop();
        // 加入结果
        result.push_back(front);

        // 这个结点指向的下一个结点入度减1
        for (int next:matrix[front]) {
            if ((--degree[next]) == 0) {// 如果减为0，加入队列
                q.push(next);
            }
        }
    }
    if (result.size() != numCourses) return {};
    return result;
}