#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

char M[25][25];
bool vis[25][25];
int R, C;
char land;

int bfs(int sr, int sc) {
    queue<int> qr, qc;
    qr.push(sr);
    qc.push(sc);
    vis[sr][sc] = true;

    int dir_r[] = {1, 0, -1, 0};
    int dir_c[] = {0, 1, 0, -1};
    int count = 0;
    while (!qr.empty()) {
        count++;
        int cr = qr.front(); qr.pop();
        int cc = qc.front(); qc.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nr = cr + dir_r[dir];
            int nc = cc + dir_c[dir];
            if (nr < 0 || nr >= R) continue;
            if (nc < 0 || nc >= C) continue;
            if (M[nr][nc] != land) continue;
            if (vis[nr][nc]) continue;

            vis[nr][nc] = true;
            qr.push(nr);
            qc.push(nc);
        }

        if (cc == 0 && M[cr][C-1] == land && !vis[cr][C-1])
            count += bfs(cr, C-1);
        else if (cc == C-1 && M[cr][0] == land && !vis[cr][0])
            count += bfs(cr, 0);
    }

    return count;
}

int main() {
    fast_io();
    while (cin >> R >> C) {
        memset(vis, 0, sizeof(vis));
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                cin >> M[r][c];
            }
        }

        int y, x; cin >> y >> x;
        land = M[y][x];

        bfs(y, x);
        int best = 0;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (!vis[r][c] && M[r][c] == land) {
                    best = max(best, bfs(r, c));
                }
            }
        }

        cout << best << "\n";
    }

    return 0;
}