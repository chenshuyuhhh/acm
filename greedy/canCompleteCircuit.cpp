#include <vector>

using namespace std;

//
// Created by 陈姝宇 on 2020/9/9.
//

class CanCompleteCircuit {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int sum = 0;
        int index = 0;
        int minGas = INT32_MAX;
        for (int i = 0; i < gas.size(); ++i) {
            sum += (gas[i] - cost[i]);
            if (sum < minGas) {
                index = i;
                minGas = sum;
            }
        }
        if (sum >= 0) return index + 1;
        else return -1;
    }
};