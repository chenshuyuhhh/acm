#include <vector>

using namespace std;
//
// Created by 陈姝宇 on 2020/9/9.
//

class ReconstructQueue {
private:
    static bool cmp(vector<int> p1, vector<int> p2) {
        if (p1[0] == p2[0]) return p1[1] < p2[1];
        return p1[0] > p2[0];
    }

public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> people) {
        if (people.size() == 0)
            return {};
        sort(people.begin(), people.end(), cmp);
        vector<int> result[people.size()];
        result[0] = people[0];

        for (int i = 1; i < people.size(); ++i) {
            vector<int> p2 = people[i];
            vector<int> p1 = people[i - 1];

            // 不相等，就可能需要插值
            // 前面的都是更大的
            int size = p2[1];
            for (int k = i; k > size; --k) {
                result[k] = result[k - 1];
            }
            result[size] = p2;
        }
        vector<vector<int>> r(result, result+ sizeof(result)/ sizeof(vector<int>));
        return r;
    }
};
//int main(){
//    ReconstructQueue * reconstructQueue = new ReconstructQueue();
//    reconstructQueue->reconstructQueue({{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}});
//}