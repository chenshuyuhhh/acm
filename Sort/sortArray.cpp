#include <vector>
#include <iostream>

using namespace std;
//
// Created by 陈姝宇 on 2020/3/31.
//

void sortArrayL(vector<int> &nums, int start, int end) {
    if (start >= end)
        return;
    int key = nums[start];
    int i = start;
    int j = end;

    while (true) {
        while (i < j && nums[j] > key) --j;

        if (i < j) {
            nums[i] = nums[j];
            ++i;
        }

        while (i < j && nums[i] < key) ++i;

        if (i < j) {
            nums[j] = nums[i];
            --j;
        }

        if (i == j) {
            nums[i] = key;
            sortArrayL(nums, start, i - 1);
            sortArrayL(nums, i + 1, end);
            break;
        }
    }
}

vector<int> sortArray(vector<int> &nums) {
    sortArrayL(nums, 0, nums.size() - 1);
    return nums;
}

//int main() {
//    vector<int> nums = {5, 1, 1, 2, 0, 0};
//    sortArray(nums);
//    cout << nums.size();
//}
