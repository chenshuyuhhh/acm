//
// Created by 陈姝宇 on 2020/9/14.
//

class UniquePaths {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 && n == 1) return 0;
        else if ((m == 2 && n == 1) || (m == 1 && n == 2))return 1;

        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
};