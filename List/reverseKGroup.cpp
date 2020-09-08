#include <iostream>

using namespace std;

//
// Created by 陈姝宇 on 2020/5/16.
//
struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *reverseKGroup(ListNode *head, int k) {
    if (head == nullptr || head->next == nullptr) return head;

    ListNode *one = head;
    ListNode *next = one->next;
    ListNode *nextTemp;
    // 记录下倒转后每小节的尾部
    ListNode *tail = one;
    ListNode *tailnext = nullptr;
    while (next != nullptr) {
        int knum = k - 1;
        while (next != nullptr && knum--) {
            nextTemp = next->next;
            next->next = one;
            one = next;
            next = nextTemp;
        }
        if (knum>0) { // 不够knum
            int revk = k - knum - 1;
            next = one->next;
            one->next = nullptr;
            while (revk--) {
                nextTemp = next->next;
                next ->next = one;
                one = next;
                next = nextTemp;
            }
            tail->next = one;
            break;
        }
        if (tailnext == nullptr) {
            head = one;
            tailnext = next;
        } else {
            tail->next = one;
            tail = tailnext;
            tailnext = next;
        }
        if (next != nullptr) {
            one = next;
            next = one->next;
            if (next == nullptr) {
                tail->next = one;
            }
        } else {
            tail->next = nullptr;
        }
    }
    return head;
}

//int main() {
//    auto *ln = new ListNode(1);
//    auto *head = ln;
//    for (int i = 2; i <= 5; i++) {
//        ln->next = new ListNode(i);
//        ln = ln->next;
//    }
//    head = reverseKGroup(head, 3);
//    cout << head->val;
//}