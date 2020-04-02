#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

//
// Created by 陈姝宇 on 2020/4/2.
//
int search(vector<int> &nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int mid = (low + high) >> 1;
    while (low <= high) {
        if (nums[mid] == target) return mid;
        if (nums[mid] > target) high = mid - 1;
        else low = mid + 1;
        mid = (low + high) >> 1;
    }
    return -1;
}

int main() {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    cout << search(nums, 9);
}