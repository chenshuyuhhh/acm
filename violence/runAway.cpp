//
// Created by 陈姝宇 on 2020/9/14.
//

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

class RunAway {

    static const int MAX = 25;

    struct point {
        int x, y, step, state;

        point(int x = 0, int y = 0, int step = 0, int state = 0) : x(x), y(y), step(step), state(state) {};
    };

    char g[MAX][MAX];
    int vis[MAX][MAX][1025];
    int dirx[4] = {0, 1, 0, -1};
    int diry[4] = {1, 0, -1, 0};
    int n, m, t;
    int sx, sy, ex, ey;

    bool judgein(int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < m;
    }

    int bfs() {
        memset(vis, 0, sizeof(vis));
        queue<point> que;
        vis[sx][sy][0] = 1;
        que.push(point(sx, sy, 0, 0));
        while (!que.empty()) {
            point top = que.front();
            que.pop();
            int x = top.x;
            int y = top.y;
            int step = top.step;
            int state = top.state;

            if (step >= t) {
                return -1;
            }

            if (x == ex && y == ey) {
                return step;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dirx[i];
                int ny = y + diry[i];
                int nstep = step + 1;
                int nstate = state;
                if (judgein(nx, ny) && g[nx][ny] != '*' && !vis[nx][ny][nstate]) {
                    if (g[nx][ny] == '.') {
                        vis[nx][ny][nstate] = 1;
                        que.push(point(nx, ny, nstep, nstate));
                    } else if (g[nx][ny] >= 'A' && g[nx][ny] <= 'J') {
                        int key = nstate & (1 << (g[nx][ny] - 'A'));
                        if (key) {
                            vis[nx][ny][nstate] = 1;
                            que.push(point(nx, ny, nstep, nstate));
                        }
                    } else if (g[nx][ny] >= 'a' && g[nx][ny] <= 'j') {
                        nstate = nstate | (1 << (g[nx][ny] - 'a'));
                        vis[nx][ny][nstate] = 1;
                        que.push(point(nx, ny, nstep, nstate));
                    }
                }
            }
        }
        return -1;
    }

    int mainRunAway() {
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
        while (scanf("%d%d%d", &n, &m, &t) != EOF) {
            getchar();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    scanf("%c", &g[i][j]);
                    if (g[i][j] == '@') {
                        sx = i;
                        sy = j;
                        g[i][j] = '.';
                    }
                    if (g[i][j] == '^') {
                        ex = i;
                        ey = j;
                        g[i][j] = '.';
                    }
                }
                getchar();
            }

            int ans = bfs();
            printf("%d\n", ans);
        }
        return 0;
    }
};