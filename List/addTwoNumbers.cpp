#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//
// Created by 陈姝宇 on 2020/4/28.
//

// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order and each of their nodes contain a single digit.
// Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    auto *nl = new ListNode(0);
    auto *head = nl;
    while (l1 && l2) {
        int value = l1->val + l2->val + nl->val;
        if (value >= 10) {
            nl->val = value % 10;
            nl->next = new ListNode(value / 10);
        } else {
            nl->val = value;
            if (l1->next || l2->next) {
                nl->next = new ListNode(0);
            }
        }
        l1 = l1->next;
        l2 = l2->next;
        nl = nl->next;
    }
    while (l1){
        int value = l1->val + nl->val;
        if (value >= 10) {
            nl->val = value % 10;
            nl->next = new ListNode(value / 10);
        } else {
            nl->val = value;
            if (l1->next) {
                nl->next = new ListNode(0);
            }
        }
        l1 = l1->next;
        nl = nl->next;
    }
    while (l2){
        int value = l2->val + nl->val;
        if (value >= 10) {
            nl->val = value % 10;
            nl->next = new ListNode(value / 10);
        } else {
            nl->val = value;
            if (l2->next) {
                nl->next = new ListNode(0);
            }
        }
        l2 = l2->next;
        nl = nl->next;
    }
    return head;
}
