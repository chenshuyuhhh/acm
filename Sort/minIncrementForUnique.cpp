#include <iostream>
#include <vector>

using namespace std;

//
// Created by 陈姝宇 on 2020/3/23.
//
struct node {
    int key;
    node *next;

    node(int key) : key(key), next(nullptr) {}
};

int minIncrementForUnique(vector<int> &A) {
    int move = 0;
    node *head = new node(0);
    for (int i = 0; i < A.size(); i++) {
        int max = A[i];
        int p = i;
        for (int j = i + 1; j < A.size(); j++) {
            if (A[j] > max) {
                max = A[j];
                p = j;
            }
        }
        int temp = A[i];
        A[i] = max;
        A[p] = temp;
        if (head->next != nullptr && max == head->next->key) { // same value
            node *pNode = head->next;
            while (pNode->next != nullptr && pNode->key + 1 == pNode->next->key) {
                // if p has next or p'next is no equal to p'key + 1
                pNode = pNode->next; // get next
            }
            int real_value = pNode->key + 1; // change max to real_value
            move += real_value - max; // count move
            node *newnode = new node(real_value);
            newnode->next = pNode->next;
            pNode->next = newnode;
        } else {
            node *newnode = new node(max);
            newnode->next = head->next;
            head->next = newnode;
        }
    }
    return move;
}

int main953() {
    vector<int> a = {1,1,2};
    cout << minIncrementForUnique(a);
}