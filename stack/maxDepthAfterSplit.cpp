#include <iostream>
#include <vector>
#include <stack>

using namespace std;
//
// Created by 陈姝宇 on 2020/4/2.
//

vector<int> maxDepthAfterSplit(string seq) {
    int p[seq.size()];
    stack<int> s;
    for (int i = 0; i < seq.size(); ++i) {
        if (seq.at(i) == '(') {
            s.push(i);
        } else { // )
            s.pop();
            if (s.size() % 2 == 0) {
                p[i] = 0;
            } else p[i] = 1;
        }
    }
    return vector<int>(p, p + seq.size());
}

int main1111(){

}