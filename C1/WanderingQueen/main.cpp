#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n, m;
char grid[1005][1005];
int dist[1005][1005]; //basically minimum dist, vis array won't be used as you want to visit a grid more than once if it's valid
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int bfs(int sr, int sc) {
    queue<int> qr, qc;
    qr.push(sr);
    qc.push(sc);
    while (!qr.empty()) {
        int cr = qr.front(); qr.pop();
        int cc = qc.front(); qc.pop();

        if (grid[cr][cc] == 'F') {
            return dist[cr][cc];
        }
        for (int i = 0; i < 8; i++) {
            int nr = cr;
            int nc = cc;
            while (true) {
                nr += dr[i];
                nc += dc[i];
                if (nr < 1 || nr > n) break;
                if (nc < 1 || nc > m) break;
                if (grid[nr][nc] == 'X') break;

                if (dist[nr][nc] == 0) {
                    dist[nr][nc] = dist[cr][cc] + 1;
                    qr.push(nr);
                    qc.push(nc);
                } else if (dist[nr][nc] != dist[cr][cc] + 1) break;
            }
        }
    }

    return -1;
}

int main() {
    fast_io();
    //use ll when possible!
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n >> m;
        int sr, sc;
        for (int r = 1; r <= n; r++) {
            for (int c = 1; c <= m; c++) {
                grid[r][c] = 0;
                cin >> grid[r][c];
                if (grid[r][c] == 'S') sr = r, sc = c;
            }
        }

        int moves = bfs(sr, sc);
        cout << moves << "\n";
    }

    return 0;
}