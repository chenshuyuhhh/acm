#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;
//
// Created by 陈姝宇 on 2020/9/13.
//

//struct machine {
//    int begin;
//    int t;
//
//    machine(int begin, int t) : begin(begin), t(t) {};
//};

string intToStr(int num) {
    if (num == 0) return "0";
    string result = "";
    while (num > 0) {
        int d = num % 10;
        char D = d + '0';
        num = num / 10;
        result = D + result;
    }
    return result;
}

int main2() {
    int n, m, w, d;
    cin >> n >> m >> w >> d;


    vector<int *> table;

    int *begin = new int[n + 1];
    for (int i = 0; i <= n; ++i) begin[i] = 0;
    table.push_back(begin);

    int result[m][2];
    int rnum = 0;

    while (m--) {
        char c;
        cin >> c;
        if (c == 'R') { // read
            int t;
            cin >> t;

            int time; // 第几条是被访问的
            for (time = table.size() - 1; time >= 0; --time) {
                if (table[time][0] <= t) break;
            }
            // 取下访问的这一条
            int *original_record = table[time];

            // 记录访问的机器情况
            map<int, vector<int>> read;
            // 输入需要访问的机器
            set<int> nums;
            int num;
            for (int i = 0; i < w; ++i) {
                cin >> num; // 被访问的机器编号
                nums.insert(num);
                // original_record[num] 该机器的数据
                read[original_record[num]].push_back(num);
            }
            if (read.size() == 1) { // 数据一致
                result[rnum][0] = w;
                if (original_record[num] == 0)result[rnum][1] = original_record[num];
                else result[rnum][1] = original_record[num] + d;
            } else { // 访问到了未更新数据，数据不一致
                int cnt = 0;
                for (int i = 1; i <= n; ++i) {
                    // 从 1 号机器开始继续访问未访问过的机器
                    if (nums.find(i) == nums.end()) {
                        ++cnt;
                        read[original_record[i]].push_back(i);
                        if (read[original_record[i]].size() == w) {// 直到有 𝑤 台机器的数据相同
                            int new_t = original_record[i];
                            result[rnum][0] = cnt + w;
                            result[rnum][1] = new_t + d;

                            // 将本次访问过的所有没有最新成功提交数据的机器更新为最新成功提交的数据
                            int *record = new int[n + 1];
                            // 更新完成的时间
                            record[0] = t + d;
                            int visit[n + 1]; // 记录是否被更新过
                            memset(visit, 0, sizeof(visit));
                            for (auto &it : read) {
                                // 没有最新成功提交数据的机器
                                if (it.first != new_t) {
                                    vector<int> updates = it.second;
                                    for (int update:updates) { // update为被更新的机器的编号
                                        visit[update] = 1;
                                        record[update] = new_t;
                                    }
                                }
                            }

                            for (int j = 1; j <= n; ++j) {
                                if (visit[j] == 0) {
                                    record[j] = original_record[i];
                                }
                            }
                            table.push_back(record);
                            // cout << table.size() << endl;
                        }
                    }
                }
            }
            ++rnum;
        } else { // write
            int t, k;
            cin >> t >> k;
            int visit[n + 1];
            memset(visit, 0, sizeof(visit));

            int *record = new int[n + 1];
            record[0] = t + d;

            int *original_record = table[table.size() - 1];

            int num;
            for (int i = 0; i < k; ++i) {
                cin >> num;
                record[num] = t;
                visit[num] = 1;
            }

            for (int j = 1; j <= n; ++j) {
                if (!visit[j]) {
                    record[j] = original_record[j];
                }
            }

            table.push_back(record);
            //cout << table.size() << endl;
        }
    }

    for (int j = 0; j < rnum; ++j) {
        cout << result[j][0] << " " << result[j][1] << endl;
    }
}