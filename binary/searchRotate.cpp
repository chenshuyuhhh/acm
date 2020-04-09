#include <iostream>
#include <vector>

using namespace std;

//
// Created by 陈姝宇 on 2020/4/2.
//
int searchRotate(vector<int> &nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int mid = (low + high) >> 1;

    while (low <= high) {
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) {
            if (nums[mid] > nums[high])low = mid + 1;
            else if (target > nums[high]) high = mid - 1;
            else low = mid + 1;
        } else { // target < mid
            if (nums[low] <= nums[mid]) {
                if (target < nums[low]) low = mid + 1;
                else high = mid - 1;
            } else high = mid - 1;
        }
        mid = (low + high) >> 1;
    }
    return -1;
}

int main33() {
    vector<int> nums = {3,1};
    cout << searchRotate(nums, 1);
}