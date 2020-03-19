#include <iostream>
#include <vector>
#include <set>

using namespace std;

int largestRectangleArea(vector<int> &heights) {

//    set<int> s;
    set<int> setc(heights.begin(), heights.end()); //数组heights初始化一个set；
    vector<int> hset;
    hset.assign(setc.begin(), setc.end());

    int area = 0;
    for (int i = 0; i < hset.size(); ++i) {
        int height = hset[i];
        // i is layer level
        int l = 0;
        if (height * heights.size() <= area) {
            continue;
        }
        for (int j = 0; j < heights.size(); ++j) {
            int ltemp = 1;
            if (heights[j] >= height) {
                for (++j; j < heights.size(); ++j) {
                    if (heights[j] >= height) ++ltemp;
                    else break;
                }
                if (ltemp > l) l = ltemp;
            }
        }
        int areap = l * height;
        if (areap > area) area = areap;
    }
    return area;
}

int main84() {
    vector<int> heights = {5, 5, 1, 7, 1, 1, 5, 2, 7, 6};
    cout << largestRectangleArea(heights);
}