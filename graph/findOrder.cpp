#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
//
// Created by 陈姝宇 on 2020/5/17.
//

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> matrix[numCourses];
    // 记录图的首结点
    int firstNode[numCourses];
    // 初始化为0
    memset(firstNode, 0, sizeof(firstNode));
    // read prerequisite
    for (auto &prerequisite : prerequisites) {
        int aft = prerequisite[0];
        int pre = prerequisite[1];
        matrix[pre].push_back(aft);
        // 一旦作为某一结点的后继结点，就不再是首结点
        firstNode[aft] = 1;
    }

    vector<int> course; // 记录可行的课程
    stack<int> dpstack; // 使用栈实现非递归的深度遍历
    for (int i = 0; i < numCourses; ++i) {
        if (firstNode[i] == 0) { // 是头结点，找出一条路
            // 先清空栈
            stack<int>().swap(dpstack);
            // 头结点进入
            dpstack.push(i);
            while (!dpstack.empty()) {
                int num = dpstack.top();
                course.push_back(num);
                if (course.size() == numCourses) // 已经达到课程要求
                    return course;
                dpstack.pop();
                for (int j : matrix[num]) {
                    dpstack.push(j);
                }
            }
        }
    }

    return {};
}