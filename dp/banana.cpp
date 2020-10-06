#include <iostream>
#include <vector>
#include <map>
#include <string.h>

#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class Banana {
    int n;

    struct Rec {
        int x;
        int y;
        int h;

        Rec(int x, int y, int h) : x(x), y(y), h(h) {
        }
    };

    Rec *nodes[100];
    int dp[100];
//int lasts[100];

    static bool cmp(Rec *r1, Rec *r2) {
        if (r1->x == r2->x) {
            return r1->y < r2->y;
        } else return r1->x < r2->x;
    }

    int main(int argc, char **argv) {

        int lengths[3];
        int k;
        int caseNum = 0;
        while (cin >> n) {
            if (n == 0) break;

            k = 0;

            for (int i = 0; i < n; ++i) {
                // cin>>x>>y>>z;
                cin >> lengths[0] >> lengths[1] >> lengths[2];
                sort(lengths, lengths + 3);

                if (lengths[2] > lengths[1]) {
                    nodes[k++] = new Rec(lengths[1], lengths[0], lengths[2]);
                    nodes[k++] = new Rec(lengths[2], lengths[0], lengths[1]);
                } else {
                    nodes[k++] = new Rec(lengths[1], lengths[0], lengths[2]);
                }

                if (lengths[1] > lengths[0]) {
                    nodes[k++] = new Rec(lengths[2], lengths[1], lengths[0]);
                }
            }

            sort(nodes, nodes + k, cmp);
            memset(dp, 0, sizeof(dp));
            //memset(lasts, 0, sizeof(lasts));

            dp[0] = nodes[0]->h;
            int x, y;
            //int last = 0; // top
            //int begin = 0;
            for (int i = 1; i < k; ++i) {
                x = nodes[i]->x;
                y = nodes[i]->y;
                //last = 0;
                for (int j = i - 1; j >= 0; --j) {
                    if (x > nodes[j]->x && y > nodes[j]->y) {
                        if (dp[j] > dp[i]) {
                            //last = j;
                            dp[i] = dp[j];
                            //begin = lasts[j];
                        }
                    }
                }
                dp[i] += nodes[i]->h;
                //lasts[i] = last;
            }

            int maxh = 0;

            for (int i = 0; i < k; ++i) {
                maxh = max(maxh, dp[i]);
            }

            cout << "Case " << ++caseNum << ": maximum height = " << maxh << endl;
        }

        return 0;
    }
};