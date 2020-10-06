#include <vector>
#include <map>

using namespace std;

//
// Created by 陈姝宇 on 2020/9/10.
//

class LeastInterval {
private:

public:
    int leastInterval(vector<char> &tasks, int n) {
        if (n == 0)
            return tasks.size();
        int map[26];
        for (char task:tasks) {
            int t = task - 'A';
            ++map[t];
        }

        int maxCnt = 0;
        for (int cnt:map) maxCnt = max(maxCnt, cnt);

        int last = 0;
        for (int cnt:map) {
            if (cnt == maxCnt) ++last;
        }
        return max((n + 1) * (maxCnt - 1) + last, (int) tasks.size());
    }
};