#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

char grid[10][10];
bool vis[10][10];
int R, C;

int dr[] = {-1, 0, 0};
int dc[] = {0, 1, -1};

string path = "IEHOVA#";

int pr[10];
int pc[10];

bool dfs(int cr, int cc, int i = 0) {
    if (grid[cr][cc] == '#' && i == 7) {
        return true;
    }

    vis[cr][cc] = true;
    bool finish = false;

    for (int d = 0; d < 3; d++) {
        int nr = cr + dr[d];
        int nc = cc + dc[d];
        if (nr < 0 || nr >= R) continue;
        if (nc < 0 || nc >= C) continue;
        if (grid[nr][nc] != path[i]) continue;
        if (vis[nr][nc]) continue;

        finish = dfs(nr, nc, i+1);
        if (finish) {
            pr[i] = dr[d];
            pc[i] = dc[d];
            break;
        }
    }

    return finish;
}

int main() {
    fast_io();
    int n; cin >> n;
    while (n--) {
        memset(vis, 0, sizeof(vis));
        cin >> R >> C;
        int sr, sc;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == '@') {
                    sr = i;
                    sc = j;
                }
            }
        }

        dfs(sr, sc);
        for (int i = 0; i < 7; i++) {
            if (pr[i] == -1) cout << "forth";
            else if (pc[i] == -1) cout << "left";
            else cout << "right";

            if (i < 6) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}