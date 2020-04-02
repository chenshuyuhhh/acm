#include <vector>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

//
// Created by 陈姝宇 on 2020/3/31.
//
void sortArray2(vector<int> &nums) {
    int n = 0;
    vector<string> array[10];
    vector<string> arraytwo[10];
    for (int num : nums) {
        string st = to_string(num);
        n = max(n, (int) st.size());
        int bit = num % 10;
        array[bit].push_back(st);
    }

    for (int i = 1; i < n; ++i) {
        if (i % 2 == 1) {
            arraytwo->clear();
            for (auto &vec : array) {
                for (auto num : vec) {
                    if (num.length() <= i) {
                        arraytwo[0].push_back(num);
                    } else {
                        int p = num.at(num.size() - i - 1) - 48;
                        arraytwo[p].push_back(num);
                    }
                }
            }
        } else {
            array->clear();
            for (auto &vec : arraytwo) {
                for (auto num : vec) {
                    if (num.length() <= i) {
                        array[0].push_back(num);
                    } else {
                        int p = num.at(num.size() - i - 1) - 48;
                        array[p].push_back(num);
                    }
                }
            }
        }
    }

    nums.clear();
    if (n % 2 == 1) {
        for (auto &vec : array) {
            for (auto num : vec) {
                nums.push_back(stoi(num));
            }
        }
    } else {
        for (auto &vec : arraytwo) {
            for (auto num : vec) {
                nums.push_back(stoi(num));
            }
        }
    }
}

//int main() {
//    vector<int> nums = {3, -1};
//    sortArray2(nums);
//    cout << nums.size();
//}