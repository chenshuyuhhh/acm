#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

//
// Created by 陈姝宇 on 2020/9/13.
//

class Exist {
private:
    vector<vector<char>> mboard;
    string mword;
    //int **visit;
    int m, n;

    bool dfs(int x, int y, int k, vector<vector<int>> &visit) {
        if (mboard[x][y] == mword[k]) {
            visit[x][y] = 1;
            ++k;
            if (mword.size() == k) return true;
            bool result = false;
            if (x + 1 < m && visit[x + 1][y] == 0) {
                if(dfs(x + 1, y, k, visit)) {
                    visit[x][y] = 0;
                    return true;
                }
            }

            if (x - 1 >= 0 && visit[x - 1][y] == 0) {
                if(dfs(x - 1, y, k, visit)) {
                    visit[x][y] = 0;
                    return true;
                }
            }

            if (y + 1 < n && visit[x][y + 1] == 0) {
                if(dfs(x , y+1, k, visit)) {
                    visit[x][y] = 0;
                    return true;
                }
            }

            if (y - 1 >= 0 && visit[x][y - 1] == 0) {
                if(dfs(x, y-1, k, visit)) {
                    visit[x][y] = 0;
                    return true;
                }
            }
            visit[x][y] = 0;
            return false;
        } else return false;
    }

public:
    bool exist(vector<vector<char>> &board, string word) {
        if (board.size() == 0) {
            return word.empty();
        }

        m = board.size();
        n = board[0].size();
        mword = word;
        mboard = board;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    vector<vector<int>> v(m, vector<int>(n));
                    if (dfs(i, j, 0, v)) return true;
                }
            }
        }
        return false;
    }
};
//
//int main() {
//    Exist *exist = new Exist();
//    vector<vector<char>> v = {{'a', 'b'},
//                              {'c', 'd'}};
//    cout << exist->exist(v,
//                         "cdba");
//}