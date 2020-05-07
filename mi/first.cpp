//
// Created by 陈姝宇 on 2020/4/29.
//

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int val) : val(val), next(nullptr) {};
};

ListNode *add(ListNode *ln1, ListNode *ln2) {
    auto *result = new ListNode(0);
    ListNode *head = result;
    while (ln1 && ln2) {
        int value = result->val + ln1->val + ln2->val;
        result->val = value % 10;
        result->next = new ListNode(value / 10);
        ln1 = ln1->next;
        ln2 = ln2->next;
        if (ln2 && ln1) {
            result->next = nullptr;
        } else {
            result = result->next;
        }
    }
    while (ln1) {
        int value = result->val + ln1->val;
        result->val = value % 10;
        result->next = new ListNode(value / 10);
        ln1 = ln1->next;
        result = result->next;
        if (ln1) {
            result->next = nullptr;
        } else {
            result = result->next;
        }
    }
    while (ln2) {
        int value = result->val + ln2->val;
        result->val = value % 10;
        result->next = new ListNode(value / 10);
        ln2 = ln2->next;
        if (ln2) {
            result->next = nullptr;
        } else {
            result = result->next;
        }
    }
    return head;
}
