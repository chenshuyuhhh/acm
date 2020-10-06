#include <vector>

using namespace std;

//
// Created by 陈姝宇 on 2020/9/12.
//

class Candy {
public:

    // [29,51,87,87,72,12]
    //  1   2  3  3  2  1
    int candy(vector<int> &ratings) {
        int left2right[ratings.size()];
        int right2left[ratings.size()];
        memset(left2right, 1, sizeof(left2right));
        memset(right2left, 1, sizeof(right2left));

        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) left2right[i] = left2right[i - 1] + 1;
        }

        for (int i = ratings.size() - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) right2left[i] = right2left[i + 1] + 1;
        }

        int sum = 0;
        for (int j = 0; j < ratings.size(); ++j) {
            sum += max(left2right[j], right2left[j]);
        }

        return sum;
    }
};