#include <iostream>
#include <vector>

using namespace std;

//
// Created by 陈姝宇 on 2020/4/2.
//
int findMin(vector<int> &nums) {
    int low = 0;
    int high = nums.size() - 1;
    int mid = (low + high) >> 1;
    while (low <= high) {
        if (nums[mid] > nums[low]) {
            if (nums[high] >= nums[mid]) {
                return nums[low];
            } else low = mid + 1;
        } else {
            if (mid == 0 || nums[mid - 1] > nums[mid])return nums[mid];
            else high = mid - 1;
        }
        mid = (low + high) >> 1;
    }
    return nums[0];
}

//int main() {
//    vector<int> num = {1, 3, 3};
//    cout << findMin(num);
//}