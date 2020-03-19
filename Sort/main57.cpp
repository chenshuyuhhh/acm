#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//给出一个无重叠的 ，按照区间起始端点排序的区间列表。
//在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

bool cmp(vector<int> a, vector<int> b) {
    return a[0] < b[0]; // 升序排序
}

vector<vector<int>> insert(vector<vector<int>> intervals, vector<int> newInterval) {
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end(), cmp);

    vector<vector<int>> result;
    for (int i = 0; i < intervals.size(); ++i) {
        int firstR = intervals[i][1]; // get the right of the first element
        int firstL = intervals[i][0];
        // find boundary
        for (i = i + 1; i < intervals.size(); ++i) {
            int nextL = intervals[i][0]; // get the left ele of the next element
            int nextR = intervals[i][1];
            if (firstR < nextL) {
                --i; // back one step
                break; // if r is less than l, have found boundary
            } else if (firstR < nextR) {
                // nextL <= firstR < nextR
                firstR = nextR;
            }
            // else firstR > nextR, keep the firstR
        }
        // push pair
        result.push_back({firstL, firstR});
    }
    return result;
}

int main57() {

    vector<vector<int>> intervals = {{1, 3},
                                     {6, 9}};
    vector<int> newInterval = {2, 5};

    vector<vector<int>> result = insert(intervals, newInterval);
    for (auto &i : result) {
        cout << i[0] << i[1] << endl;
    }
//    输入: intervals = [[1,3],[6,9]], newInterval = [2,5]
//    输出: [[1,5],[6,9]]
    return 0;
}
