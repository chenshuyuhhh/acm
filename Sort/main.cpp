#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
//
// Created by 陈姝宇 on 2020/3/12.
//

//给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。
//如果数组元素个数小于 2，则返回 0。
//输入: [3,6,9,1]
//输出: 3

void quickSort(int *array, int start, int end) {
    int key = array[start];
    int i = start;
    int j = end;
    while (true) {
        while (i < j && array[j] > key) --j;

        if (i < j) {
            array[i] = array[j];
            ++i;
        }

        while (i < j && array[i] < key) ++i;

        if (i < j) {
            array[j] = array[i];
            --j;
        }

        if (i == j) {
            quickSort(array, start, i);
            quickSort(array, i + 1, end);
            break;
        }
    }
}

int maximumGap(vector<int> &nums) {
    if (nums.size() < 2) return 0;

    int array[nums.size()];
    memcpy(array, &nums[0], nums.size() * sizeof(int));
    quickSort(array, 0, nums.size());
    int max_gap = 0;
    cout << max_gap;
}

int main2() {

    vector<int> num = {3, 6, 9, 1};
    maximumGap(num);
}
