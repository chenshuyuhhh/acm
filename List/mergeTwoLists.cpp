#include <cmath>
#include <set>
#include <iostream>

using namespace std;

//
// Created by 陈姝宇 on 2020/5/1.
//
struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};


ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *nodeTemp = new ListNode(0);
    ListNode *head = nodeTemp;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            nodeTemp->next = new ListNode(l1->val);
            nodeTemp = nodeTemp->next;
            l1 = l1->next;
        } else if (l1->val > l2->val) {
            nodeTemp->next = new ListNode(l2->val);
            nodeTemp = nodeTemp->next;
            l2 = l2->next;
        } else {
            nodeTemp->next = new ListNode(l2->val);
            nodeTemp = nodeTemp->next;
            nodeTemp->next = new ListNode(l1->val);
            nodeTemp = nodeTemp->next;
            l1 = l1->next;
            l2 = l2->next;
        }
    }
    while (l1) {
        nodeTemp->next = new ListNode(l1->val);
        nodeTemp = nodeTemp->next;
        l1 = l1->next;
    }

    while (l2) {
        nodeTemp->next = new ListNode(l2->val);
        nodeTemp = nodeTemp->next;
        l2 = l2->next;
    }

    return head->next;
}