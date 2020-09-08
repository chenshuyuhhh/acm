#include <iostream>
#include <vector>

using namespace std;
//
// Created by 陈姝宇 on 2020/5/6.
//

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    // 1 对应的是长度较短的数组A
    // 2 对应的是长度较长的数组B
    int min1 = 0, max1 = 0;  // 长度较短的数组的最大最小值
    int size1, size2; // 记录下大小
    if (nums1.size() > nums2.size()) {
        // 如果1比2大，则交换数组
        vector<int> temp;
        temp.assign(nums2.begin(), nums2.end());
        nums2.assign(nums1.begin(), nums1.end());
        nums1.assign(temp.begin(), temp.end());
    }
    size1 = nums1.size();
    size2 = nums2.size();
    if (size2 == 0) {
        return 0;
    } else if (size1 == 0) {
        if (size2 % 2) { // 奇数
            return nums2[size2 / 2];
        } else { // 偶数
            return (nums2[size2 / 2 - 1] + nums2[size2 / 2]) * 1.0 / 2;
        }
    }

    // max1不用size-1,因为插空分，是可以分到末尾的
    max1 = nums1.size();

    // 记录下两个数组二分的中间值
    int p1;
    int p2;
    // 根据二分获得中位数左边值，中位数右边值
    // 最后根据size1+size2的奇偶性判断median取值
    int left, right;
    while (min1 <= max1) {
        p1 = (min1 + max1) / 2;
        p2 = (size1 + size2 + 1) / 2 - p1;
        // 用来限制的两个条件：
        // bool con2 = (nums2[p2 - 1] <= nums1[p1]);
        // bool con1 = (nums1[p1 - 1] < nums2[p2]);

        // 应当先调大小，可能存在临界值不满足大小关系
        if (p1 > 0 && nums1[p1 - 1] > nums2[p2]) {
            // nums1[p1 - 1] > nums2[p2]
            // 说明较短数组的中间值过大，应当调小
            max1 = p1 - 1;
        } else if (p1 < size1 && nums2[p2 - 1] > nums1[p1]) {
            // nums2[p2 - 1] > nums2[p1]
            // 说明较短数组的中间值过小，应当调大
            min1 = p1 + 1;
        } else {
            // 前两个情况均为临界值，先检查异常情况
            if (p1 == 0) { // 长度较短的数组A达到最小值
                // 即数组A全部被分到右边
                left = nums2[p2 - 1];
                // 存在数组B取到边界值的情况
                if (p2 == size2) right = nums1[p1];
                else right = min(nums1[p1], nums2[p2]);
                break;
            } else if (p1 == size1) { // 长度较短的数组A达到最大值
                // 即数组A全部被分到左边
                right = nums2[p2];
                if (p2 == 0) left = nums1[p1 - 1];
                else left = max(nums1[p1 - 1], nums2[p2 - 1]);
                break;
            } else {
                // 在边界内
                left = max(nums1[p1 - 1], nums2[p2 - 1]);
                right = min(nums1[p1], nums2[p2]);
                break;
            }
        }
    }
    if ((size1 + size2) % 2 == 0) return (left + right) * 1.0 / 2;
    else return left;
}
//
//int main() {
//    vector<int> num1 = {};
//    vector<int> num2 = {2, 3};
//    cout << findMedianSortedArrays(num1, num2);
//}