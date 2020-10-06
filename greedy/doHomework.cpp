#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

//
// Created by 陈姝宇 on 2020/9/19.
//
class DoHw {
    struct Node {
        int dll;
        int reduce;

        Node(int dll) : dll(dll) {};

        Node(int dll, int reduce) : dll(dll), reduce(reduce) {};
    };

    int n;
    Node *hws[1001];
    map<int, vector<Node *>> m;
    int hasRemove[1001];

    static bool cmpReduce(Node *n1, Node *n2) {
        if (n1->reduce == n2->reduce) {
            return n1->dll < n2->dll;
        }
        return n1->reduce < n2->reduce;
    }

    int main() {
        int cases;
        cin >> cases;

        while (cases--) {
            cin >> n;
            int temp;
            int maxDll = 0;
            memset(hasRemove, 0, n * sizeof(int));
            m.clear();

            for (int i = 0; i < n; ++i) {
                cin >> temp;
                maxDll = max(maxDll, temp);
                hws[i] = new Node(temp);
                m[temp].push_back(hws[i]);
            }

            for (int i = 0; i < n; ++i) {
                cin >> temp;
                hws[i]->reduce = temp;
            }

            sort(hws, hws + n, cmpReduce);

            int sum = 0;
            int result = 0;
            for (int i = 1; i <= maxDll; ++i) { // i --- time
                if (m.find(i) != m.end()) {
                    sum += m[i].size();
                    if (sum > i) {
                        for (int j = 0; i < n && sum > i; ++j) {
                            if (!hasRemove[j] && hws[j]->dll <= i) {
                                --sum;
                                result += hws[j]->reduce;
                                hasRemove[j] = 1;
                            }
                        }
                    }
                }
            }

            cout << result << endl;
        }
    }
};