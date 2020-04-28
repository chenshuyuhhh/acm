#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//
// Created by 陈姝宇 on 2020/4/26.
//

// Merge k sorted linked lists and return it as one sorted list.
// Analyze and describe its complexity.
struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *mergeKLists(vector<ListNode *> &lists) {

    int size = lists.size();
    int p[size];
    int all[size];
    ListNode *listsTemp[size];
    auto *result = new ListNode(0);
    ListNode *head = result;
    // result->next = new ListNode(0);
    for (int i = 0; i < size; ++i) {
        p[i] = 0;
        all[i] = 0;
        listsTemp[i] = lists[i];
    }
    int which = 0;
    while (true) {
        bool bre = true;
        int min = INT32_MAX;
        //  int second_min = INT32_MAX;
        for (int i = 0; i < size; ++i) {
            if (all[i] == 0) {
                ListNode *node = listsTemp[i];
                if (node->val < min) {
                    // second_min = min;
                    min = node->val;
                    which = i;
                }
                bre = false;
            }
        }
        if (bre) {
            break;
        }
        result->next = new ListNode(0);
        result = result->next;

        result->val = min;

        if (listsTemp[which]->next != nullptr)
            listsTemp[which] = listsTemp[which]->next;
        else all[which] = 1;

    }
    return head->next;
}
