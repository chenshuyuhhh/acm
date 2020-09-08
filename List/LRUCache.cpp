#include <map>

using namespace std;

struct Node {
    int key;
    int val;
    Node *next;
    Node *before;

    explicit Node(int key, int val) : key(key), val(val), next(nullptr), before(nullptr) {};
};

class LRUCache {
private:
    // hash 映射便于查找
    map<int, Node *> hashm;
    int cap;
    // 双向链表
    Node *head = nullptr;
    Node *tail = nullptr;

    // 不是头结点，不用再移动
    void update(Node *temp) {
        if (temp == tail) {
            // 尾结点没有后继结点
            tail = tail->before;
            tail->next = nullptr;
        } else { // remove node
            temp->before->next = temp->next;
            temp->next->before = temp->before;
        }
        // put node to the head
        temp->next = head;
        head->before = temp;
        // 更新头结点
        head = temp;
    }

public:

    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (hashm.find(key) == hashm.end()) return -1; // 没找到，返回-1
        else { // 存在
            // 更新链表
            Node *temp = hashm[key];
            // 如果是头结点，不用再移动
            if (temp != head) {
                update(temp);
            }
            // 返回值
            return temp->val;
        }
    }

    void put(int key, int value) {
        Node *newnode;
        if (hashm.find(key) != hashm.end()) {
            // 如果已经存在，更新val即可
            hashm[key]->val = value;
            newnode = hashm[key];
            // 如果是头结点，不用再移动
            if (newnode != head) {
                update(newnode);
            }
        } else {
            // update number of node
            newnode = new Node(key, value);
            hashm[key] = newnode;
            if (hashm.size() > cap) { // 超过最大容量
                Node *temp = tail;
                // 首先删掉hash表中的对应元素
                hashm.erase(temp->key);

                if (tail == head) { //头结点等于尾结点，则尾结点没有before
                    head = nullptr;
                    tail = nullptr;
                } else {
                    // 删除链表的尾结点
                    temp->before->next = nullptr;
                    // 更新尾结点
                    tail = temp->before;
                }
                // 删除尾结点
                delete temp;
                // 删除结点之后，必然应当更新结点数
            }
            if (hashm.size() == 1) {
                head = newnode;
                tail = head;
            } else {
                // become head node
                newnode->next = head;
                head->before = newnode;
                head = newnode;
            }
        }
    }
};

int mainLRU() {
    LRUCache *cache = new LRUCache(2 /* capacity */ );

    cache->get(2);
    cache->put(2, 1);
    cache->put(1, 1);
    cache->put(2, 3);
    cache->put(4, 1);
    cache->get(1);
    cache->get(2);       // returns 3
    //  cache->get(4);       // returns 4

}
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */